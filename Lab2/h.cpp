#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* prev;

        Node() {
            val = 0; 
            next = NULL; 
            prev = NULL;
        }
        Node(int val) {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
        Node(int val, Node* next, Node* prev) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
};

class LinkedList {
    private:
        Node* head = NULL;
        Node* tail = NULL;
        int length = 0;
    public:
        LinkedList() {}

        void push_back(int value) {
            if (!head) {
                Node* newNode = new Node(value);
                head = newNode;
                tail = head;
            }
            else {
                Node* newNode = new Node(value, NULL, tail);
                tail->next = newNode;
                tail = tail->next;
            }
            length++;
        }
        void push_front(int value) {
            if (!head) {
                Node* newNode = new Node(value);
                head = newNode;
                tail = head;
            }
            else {
                Node* newNode = new Node(value, head, NULL);
                head->prev = newNode;
                head = head->prev;
            }
            length++;
        }
        void print() {
            if (head == NULL) {
                cout << -1 << endl;
                return;
            }
            Node* cur = head;
            // cout << "NULL <-> ";
            while (cur != NULL) {
                cout << cur->val << " ";
                cur = cur->next;
            }
            cout << endl;
        }
        void inserts(int value, int index) {
            if (index == 0) 
                push_front(value);
            else if (index == length)
                push_back(value);
            else {
                int cur_index = 1;
                Node* cur = head->next;
                while (cur != NULL) {
                    if (cur_index == index) {
                        Node* newNode = new Node(value, cur, cur->prev);
                        cur->prev->next = newNode;
                        cur->prev = newNode;
                        break;
                    }
                    cur_index++;
                    cur = cur->next;
                }
                length++;
            } 
        }
        int pop_front() {
            int num = head->val;
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            length--;
            return num;
        }
        int pop_back() {
            int num = tail->val;
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            length--;
            return num;
        }
        int pop(int index) {
            Node* cur = head;
            if (cur == NULL) return 0;
            else if (index == 0) {return pop_front();}
            else if (index == length - 1) {return pop_back();}
            else {
                length--;
                int cur_index = 0;
                while (cur != NULL) {
                    if (cur_index == index) {
                        int num = cur->val;
                        cur->next->prev = cur->prev;
                        cur->prev->next = cur->next;
                        delete cur;
                        return num;
                    }
                    cur_index++;
                    cur = cur->next;
                }
            }
        }
        void reverse() {
            Node* cur = head;
            if (cur == NULL) return;
            while (cur != NULL) {
                Node* temp = cur->next;
                cur->next= cur->prev;
                cur->prev = temp;
                cur = temp;
            }
            Node* temp = head;
            head = tail;
            tail = temp;
        }
        void left_shift(int shift) {
            while (shift != 0) {
                push_back(pop_front());
                shift--;
            }
        }
        void right_shift(int shift) {
            while (shift != 0) {
                push_front(pop_back());
                shift--;
            }
        }
        void replace(int index1, int index2) {
            inserts(pop(index1), index2);
        }
        int get_length() {
            return length;
        }
};

int main() {
    
    LinkedList ll;
    int command, index, index1, index2, num, shift;
    while (true) {
        cin >> command;
        switch (command) {
            case 0:
                return 0;
            case 1:
                cin >> num >> index;
                ll.inserts(num, index);
                break;
            case 2:
                cin >> index;
                ll.pop(index);
                break;
            case 3:
                ll.print();
                break;
            case 4:
                cin >> index1 >> index2;
                ll.replace(index1, index2);
                break;
            case 5:
                ll.reverse();
                break;
            case 6:
                cin >> shift;
                ll.left_shift(shift);
                break;
            case 7:
                cin >> shift;
                ll.right_shift(shift);
                break;
        }

    }
    return 0;
}