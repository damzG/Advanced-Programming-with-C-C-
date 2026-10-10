//
// Created by User on 10/10/2026.
//
#include <iostream>
using namespace std;

//Node class representing each element in the list
class Node
{
    public:
        int data;
        Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;

public:

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (!head)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void traverse()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void remove(int value)
    {
        if (head == nullptr)
        {
            return;
        }

        //If the head node itself holds the value to be deleted
        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        //Search for the node to be deleted
        Node* temp = head;
        while (temp->next && temp->next->data != value)
        {
            temp = temp->next;
        }

        //If the value was found, unlink and delete it
        if (temp->next)
        {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
        else
        {
            cout << "Value" << value << "not found\n";
        }
    }
};

int main()
{
    LinkedList list;

    //Insert Elements
    list.insert(10);
    list.insert(20);
    list.insert(30);


    cout << "Initial Linked List:\n";
    list.traverse();

    //Delete an element
    list.remove(20);
    cout << "Linked List after deleting 20:\n";
    list.traverse();

    return 0;
}