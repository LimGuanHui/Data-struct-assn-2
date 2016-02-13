#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Lim Guan Hui
 *  \date      12 Feb 2016
 *  \note      150623L
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//

LinkedList::LinkedList()
{
    head = 0;
}

LinkedList::~LinkedList()
{

}

void LinkedList::push_front(int data)
{

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    
}

void LinkedList::push_back(int data)
{
    if (head == 0) push_front(data);
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
        temp->next->next = 0;
    }
}

int LinkedList::pop_front()
{
    if (head == 0) return 0;
    Node *Temp = head;
    head = head->next;
    Temp->next = 0;
    int data = Temp->data;
    delete Temp;
    return data;
}

int LinkedList::pop_back()
{
    if (head == 0) return 0;
    
    Node *temp = head;
    if (temp->next == 0)
    {
        return pop_front();
    }
    else {
        while (temp->next->next)
        {
            temp = temp->next;
          
        }
    }
    
    Node *deletenode;
    deletenode = temp->next;
    temp->next = 0;
    int data = deletenode->data;
    delete deletenode;
    return data;
}

void LinkedList::insert_at(int pos, int data)
{
    if (pos <= 0 || head == 0)
    {
        push_front(data);
        
    }
    else if (pos >= (int)size()-1) push_back(data);
    else /*if (pos > 0)*/
    {
        int counter = 1;
        Node *temp = head;
        while (counter != (pos-1))
        {
            counter += 1;
            temp = temp->next;
        }
        Node *temp2 = new Node(data);
        temp2->next = temp->next->next;
        temp->next = temp2;
    }
}



int LinkedList::pop_at(int pos)
{
    Node *temp = head;
    if (pos == 0 || pos < 0 || temp == 0) return 0;
    if (pos >= (int)size()) return pop_back();
    if (pos == 1) return pop_front();

    int counter = 1;
    while (counter < pos-1)
    {
        counter += 1;
        temp = temp->next;
    }
    Node *deletenode = temp->next;
    temp->next = temp->next->next;
    deletenode->next = 0;
    int data = deletenode->data;
    delete deletenode;
    return data;
}

size_t LinkedList::size()
{
    if (head == 0) { return 0; }
    int size = 1;
    Node *temp = head;
    while (temp->next != 0)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue()
{
    front = 0;
    back = 0;
}

Queue::~Queue()
{

}

void Queue::enqueue(int data)
{
    if (front)
    {
        Node *newnode = new Node(data);
        back = newnode;
    }
    else 
    {
        front = new Node(data);
        front->next = back;
    }
}

int Queue::dequeue()
{
    if (front == 0) return 0;

    Node *temp = front;
    int data = 0;
    front = front->next;
    data = temp->data;
    delete temp;
    return data;
}

size_t Queue::size()
{
    if (front == 0) return 0;
    Node *frontnode = front;
    int size = 1;
    while (frontnode->next)
    {
        size++;
        frontnode = frontnode->next;
    }
    return size;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
    top = 0;
}

Stack::~Stack()
{

}

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

int Stack::pop()
{
    if (top == 0) return 0;

    Node *temp = top;
    int data = 0;
    top = top->next;
    data = temp->data;
    delete temp;
    return data;
}

size_t Stack::size()
{
    if (top == 0) return 0;
    int size = 0;
    Node *temp = top;
    while (temp->next)
    {
        size++;
        temp = temp->next;
    }

    return size;
}
