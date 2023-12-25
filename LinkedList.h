#include <iostream>

using std::cout;
class Node 
{
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};
class LinkedList 
{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
        LinkedList(int value)
        {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() 
        {
            Node* temp = head;
            while (head)
            {
               head = head->next;
               delete temp;
               temp = head;
            }
        }
        void printList() 
        {
            Node* temp = head;
            while (temp) 
            {
                cout << temp->value << "\n";
                temp = temp->next;
            }
        }
        void append(int value)
        {
            if(length > 0)
            {
                Node* newNode = new Node(value);
                head = newNode;
                tail = newNode;
            }
            else
            {
                Node* newNode = new Node(value);
                tail->next = newNode;
                tail = newNode; 
            }
            length++;
        }
        void deleteLast() 
        {
            if(length == 0) return;
            Node* pre = head;
            Node* temp = head;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
                
            }
            else
            {
                while (temp->next) 
                {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }
        void prepend(int value)
        {
            Node* newNode = new Node(value);
            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
        void deleteFirst()
        {
            if(length == 0) return;
            Node* temp = head;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
            }
            length--;
            delete temp;
        }
        bool insert(int index, int value)
        {
            if(index < 0 || index > length)
            {
                return false;
            }

            return true;
        }
        Node* get(int index)
        {
            if(index < 0 || index > length)
            {
                return nullptr;
            }
            Node* temp = head;
            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp;
        } 
        bool set(int index, int value){
            if(index < 0 || index > length) 
            {
                return false;
            }
            Node* temp = get(index);
            if(temp)
            {
                temp->value = value;
                return true;
            }
            else
            {
                return false;
            }
        }
        int getHead() 
        {
            return head->value;
        }
        int getTail() 
        {
            return tail->value;
        }
        int getLength() 
        {
            return length;
        }
};

int main()
{
    LinkedList* myLL = new LinkedList(4);
    return 0;
}