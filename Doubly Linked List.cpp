// Doubly Linked List.cpp : 

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node()
    {
        data = -1;
        next = prev = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }
   ~DoublyLinkedList()
    {
       Node* delNode = head;
       while (delNode != nullptr)
       {
           Node* temp = delNode->next;
           delete delNode;
           delNode = temp;

       }
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void InsertAtBegin(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        if (IsEmpty())
        {
            newNode->next = newNode->prev = nullptr;
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
    void InsertAtEnd(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        if (IsEmpty())
        {
            newNode->next = newNode->prev = nullptr;
            head = tail = newNode;
            return;
        }
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    void DisplayForward()
    {
        if (IsEmpty())
        {
            cout << "List is Empty" << endl;
            return;
        }
        cout << " List is : ";
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void DisplayBackward()
    {
        if (IsEmpty())
        {
            cout << "List is Empty" << endl;
            return;
        }
        cout << " backward List is : ";
        Node* temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    bool IsFound(int check)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == check) return true;
            temp = temp->next;
        }
        
        return false;
    }
    void InsertBefore(int targetVal, int newVal)
    {
        if (IsEmpty() || head->data == targetVal)
        {
            InsertAtBegin(newVal);
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != targetVal)
        {
            temp = temp->next;
        }
        Node* newNode = new Node();
        newNode->data = newVal;
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    void Delete(int delVal)
    {
        if (IsEmpty())
        {
            cout << "List is Empty, no element to delete" << endl;
            return;
        }
        Node* temp = head;
         if(head->data == delVal)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != delVal)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Value " << delVal << " not found in the list." << endl;
            return;
        }
        if (temp == tail)
        {
            tail = tail->prev;
        }
        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    int Peek()
    {
        return head->data;
    }
    int Tail()
    {
        return tail->data;
    }
};
int main()
{
    DoublyLinkedList list;
    for (int i = 0; i < 3; i++)
    {
        cout << "Insert a num at end " << endl;
        int add;
        cin >> add;
        list.InsertAtEnd(add);
   }
    list.DisplayForward();
    cout << "----------------------------" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Insert a num at begin " << endl;
        int add;
        cin >> add;
        list.InsertAtBegin(add);
    }
    list.DisplayForward();
    list.DisplayBackward();
    cout << "Peek is : " << list.Peek() << endl;
    cout << "Tail is : " << list.Tail() << endl;
    cout << "----------------------------" << endl;
    cout << "Enter num to delete" << endl;
    int delnum;
    cin >> delnum;
    list.Delete(delnum);
    cout<<"After deletion list is : "<< endl;
    list.DisplayForward();
    list.DisplayBackward();
    cout << "Peek is : " << list.Peek() << endl;
    cout << "Tail is : " << list.Tail() << endl;
    cout << "----------------------------" << endl;
    cout << "Enter numto check if exict" << endl;
    int check;
    cin >> check;
    if (list.IsFound(check))
    {
        cout<< check << "is found" << endl;
    }
    else
    {
        cout<< check << "is not found" << endl;
    }
}

