//============================================================================
// Name        : notes.cpp
// Author      : Ömer YASLITAŞ
// Version     : 1.0
// Description : List-ADT - NOTES PART 1
//============================================================================
#include <iostream> //input/output

using namespace std;

namespace LinkedList
{

    template <class T>
    class Node
    {
    public:
        Node(const T &e = T(), Node *n = nullptr) : data(e), next(n) {}

        T data;
        Node *next;
    };

    template <class T>
    void constructList()
    {
        Node<int> *list = new Node<int>(1);
        Node<int> *p = list;

        for (int i = 4; i <= 100; i += 3)
        {
            p->next = new Node<int>(i);
            p = p->next;
        }

        p = list;
        Node<int> *temp = nullptr;
        while (p != nullptr)
        {
            temp = p;
            cout << p->data << " ";
            p = p->next;
            delete temp;
        }
        cout << endl;
    }

}

namespace LinkedIntList
{

    class NoSuchElementException
    {
    };

    class ListNode
    {
    public:
        int data;
        ListNode *next;

        ListNode(int x) : data(x), next(nullptr) {}

        ListNode(int x, ListNode *p) : data(x), next(p) {}
    };

    class LinkedIntList
    {
    public:
        LinkedIntList() : front(nullptr) {}
        ~LinkedIntList()
        {
            while (front)
                remove();
        }
        LinkedIntList(const LinkedIntList &rhs)
        {
            front = nullptr;
            *this = rhs; // operator =
        }

        LinkedIntList &operator=(const LinkedIntList &rhs)
        {
            if (this != &rhs)
            {
                while (front)
                    remove();
                ListNode *r = rhs.front;

                while (r)
                {
                    add(r->data);
                    r = r->next;
                }
            }
            return *this;
        }

        void add(int value)
        {
            if (front == nullptr)
            {
                front = new ListNode(value);
            }
            else
            {
                ListNode *current = front;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = new ListNode(value);
            }
        }

        void add(int index, int value)
        {
            if (index == 0)
                front = new ListNode(value, front);
            else
            {
                ListNode *current = front;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                current->next = new ListNode(value, current->next);
            }
        }

        void addSorted(int value)
        {
            ListNode *current;
            if (front == nullptr || front->data >= value)
            {
                front = new ListNode(value, front);
            }
            else
            {
                current = front;
                while (current->next && current->next->data < value)
                {
                    current = current->next;
                }
                current->next = new ListNode(value, current->next);
            }
        }

        int get(int index)
        {
            ListNode *current = front;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->data;
        }

        int remove()
        {
            if (front == nullptr)
            {
                throw NoSuchElementException();
            }
            else
            {
                int result = front->data;
                ListNode *tmp = front;
                front = front->next;
                delete tmp;
                return result;
            }
        }

        void remove(int index)
        {
            if (index == 0)
            {
                ListNode *tmp = front;
                front = front->next;
                delete tmp;
            }
            else
            {
                ListNode *current = front;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                ListNode *tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            }
        }

        void print()
        {
            ListNode *current = front;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

    private:
        ListNode *front;
    };

    void testLinkedIntList()
    {
        LinkedIntList list;

        list.add(5);
        list.add(10);
        list.add(15);
        list.add(25);
        list.print();
        cout << "second element is " << list.get(1) << endl;
        list.addSorted(12);
        list.remove(4);
        list.print();
        list.addSorted(100);
        try
        {
            list.remove(0);
            list.remove();
            list.remove();
            list.remove();
            list.print();
            list.remove();
            list.remove();
        }
        catch (NoSuchElementException e)
        {
            cout << "List is empty!!" << endl;
        }
    }
}

int main()
{
    // LinkedList::constructList<int>();
    LinkedIntList::testLinkedIntList();

    return 0;
}