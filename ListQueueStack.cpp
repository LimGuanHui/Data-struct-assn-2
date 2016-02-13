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
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
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
    Node *deletenode;
    
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
    deletenode = temp->next;
    temp->next = 0;
    int data = deletenode->data;
    delete deletenode;
    return data;

}

void LinkedList::insert_at(int pos, int data)
{
    if (pos == 0)
    {
        Node *newNode = new Node();
        newNode->next = head->next;
        head->next = newNode;
        
    }
    else if (pos > 0)
    {
        int counter = 0;
        Node *temp = head;
        while (counter < pos)
        {

            if (temp == 0)
            {
                break;
            }
            counter += 1;
            temp = temp->next;
        }

        if (counter == (pos - 1))
        {
            Node *temp2 = new Node(data);
            temp2->next = temp->next;
            temp->next = temp2;
        }
    }
}

int LinkedList::pop_at(int pos)
{
    if (pos == 0) return 0;
    if (pos < 0) return 0;

    int counter = 0;
    Node *temp = head;
    while (counter < pos)
    {
        if (temp == 0)
        {
            return 0;
            break;
        }
        counter += 1;
        temp = temp->next;
    }
    if (counter == (pos - 1))
    {
        Node *deletenode = temp->next;
        temp->next = temp->next->next;
        int data = deletenode->data;
        delete deletenode;
        return data;
    }


}

size_t LinkedList::size()
{
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
    front = back;
    back = front;
}

Queue::~Queue()
{

}

void Queue::enqueue(int data)
{
    Node *temp = back;
    Node *newnode = new Node(data);
    back = newnode;
    newnode->next = temp;
}

int Queue::dequeue()
{

    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{

}

void Stack::push(int data)
{

}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}
