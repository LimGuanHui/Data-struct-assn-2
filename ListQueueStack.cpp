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
    if (size() != 0)
    {
        for (int x = 0; x < (int)(size()); x++)
        {
            pop_front();
        }
    }
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
    else if (pos >= (int)size()) push_back(data);
    else /*if (pos > 0)*/
    {
        int counter = 0;
        Node *temp = head;
        while (counter != (pos-1))
        {
            counter += 1;
            temp = temp->next;
        }
        Node *addnode = new Node(data);
        addnode->next = temp->next;
        temp->next = addnode;
    }
}



int LinkedList::pop_at(int pos)
{
    Node *temp = head;
    if (pos <= 0 || temp == 0) return pop_front();
    else if (pos == (static_cast<int>(size()) - 1)) return pop_back();
    else if (pos > (static_cast<int>(size())-1)) return 0;
    /*if (pos == 1) return pop_front();*/
    else
    {
        Node *previous;
        int counter = 0;
        while (counter < pos)
        {
            counter += 1; 
            previous = temp;
            temp = temp->next;
        }
        Node *deletenode = temp;
        previous->next = temp->next;
        deletenode->next = 0;
        int data = deletenode->data;
        delete deletenode;
        return data;
        /*Node *current = head;
        Node *previous = head;
        for (int i = 0; i < pos && current != 0; ++i)
        {
            current = current->next;
        }
        int data = current->data;
        while (previous->next != current)
        {
            previous = previous->next;
        }
        previous->next = current->next;
        delete current;
        return data;*/

    }
    
}

size_t LinkedList::size()
{
    if (head == 0) { return 0; }
    int size = 0;
    Node *temp = head;
    while (temp)
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
    if (size() != 0)
    {
        for (int x = 0; x < (int)(size()); x++)
        {
            dequeue();
        }
    }
}

void Queue::enqueue(int data)
{
    if (front == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = front;
        front = newNode;
        back = front;
    }
    else 
    {
        back->next = new Node(data);
        back = back->next;
        back->next = 0;
    }
    

}

int Queue::dequeue()
{
    if (front == 0 || size() == 0) { return 0; }
    else if (front->next == 0){
        Node *temp = front;
        back = 0;
        front = back;
        int data = 0;
        data = temp->data;
        delete temp;
        return data;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        int data = 0;
        data = temp->data;
        delete temp;
        return data;
    }
    
}

size_t Queue::size()
{

    Node *temp = front;
    size_t size = 0;
    while (temp)
    {
        ++size;
        temp = temp->next;
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
    if (size() != 0)
    {
        for (int x = 0; x < (int)(size()); x++)
        {
            pop();
        }
    }
}

void Stack::push(int data)
{
    if (top != 0)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    else
    {
        top = new Node(data);
        top->next = 0;
    }
    
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
    Node *frontnode = top;
    size_t size = 0;
    while (frontnode)
    {
        ++size;
        frontnode = frontnode->next;
    }
    return size;
}
/*
Node* currNode = head;
int count = 0;
if (pos < 0) //sets negative value as 0
{
push_front(data);
}
else
{
while (count < (pos-1))
{
count++;
currNode = currNode->next;
}
    Node* addNode = new Node(data);
    addNode->next = currNode->next->next;
    currNode->next = addNode;
}

*/