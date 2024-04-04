#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }

   
    void addNode(int data) {
        Node* newNode = new Node(data);
        if (next == nullptr) {
            next = newNode;
        }
        else {
           
            Node* temp = next;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    void deleteNode(int data) {
        Node* prev = this;
        Node* curr = next;

       
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        
        if (curr != nullptr) {
           
            if (prev == this) {
                next = curr->next;
            }
            else {
               
                prev->next = curr->next;
            }
            
            delete curr;
        }
    }
}

int main() {





	return 0;
}