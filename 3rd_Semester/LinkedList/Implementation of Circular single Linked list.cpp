#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*ptr;
    Node(int data){
        this->data = data;
        ptr = nullptr;
    }
    Node(int data , Node*next){
        this->data = data;
        ptr = next;
    }
};
class CircularLinkedList{
    public:
    Node*head;
    Node*tail;
    CircularLinkedList(){
        head = nullptr;
        tail = nullptr; 
    }
    void insertatfront(int val){
        Node*newNode = new Node (val);
        if (head == nullptr){
            head = tail = newNode;
            tail->ptr = head;
        }
        else{
            newNode->ptr = head;
            head = newNode;
            tail->ptr = head;
        }
    }
    void display(){
        if (head==nullptr){
            cout << "head is nullptr"<<endl;
            return;
        }
        Node*temp = head;
        do{
            cout << temp->data<<" ";
            temp = temp->ptr;
        }while(temp!=head);
        cout << endl;
    }
   void insertEnd(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        tail->ptr = head;
        return;
    }

    newNode->ptr = head;
    tail->ptr = newNode;
    tail = newNode;
}
    void insertAfter(int target, int value){
        if (head == nullptr){
            cout << "value: "<<value <<" not found"<<endl;
            return;
        }
        Node*newNode = new Node(value);
        Node*temp = head;
        do{
            if (temp->data == target){
                newNode->ptr = temp->ptr;
                temp->ptr = newNode;
                if (temp == tail){
                    tail = newNode;
                }
                cout << "Inserted successfully"<<endl;
                return;
            }
            temp = temp->ptr;
        }while(temp!=head);
        cout << "Target: "<<target<< " not found"<<endl;
    }
void deleteFront() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* temp = head;
    head = head->ptr;
    tail->ptr = head;
    delete temp;
}
    void DeleteEnd(){
        if (head==nullptr){
            cout << "linked list is empty"<<endl;
            return;
        }
        if (head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }
        Node*temp = head;
        while(temp->ptr!=tail){
            temp = temp->ptr;
        }
        delete tail;
        tail = temp;
        tail->ptr = head;
    }
    void search(int value){
        int x = 0;
        Node*temp = head;
        if (head==nullptr){
            cout << "Linked list is empty"<<endl;
            return;
        }
        do
        {
            if (temp->data == value){
                cout <<"Found "<<value<<" at position of "<<x<<endl;
            }
            x++;
            temp = temp->ptr;
        } while (temp!=head);
    }
    int count(){
        if (head==nullptr){
            return 0;
        }
        int cnt = 0;
        Node*temp = head;
        do{
            temp = temp->ptr;
            cnt++;
        }while(temp!=head);
        return cnt;
    }
    void clearList(){
        if (head==nullptr){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        Node*temp = head;
        tail->ptr = nullptr;
        while(temp!=nullptr){
            Node*prev = temp;
            temp = temp->ptr;
            delete prev;
        }
        head=tail=nullptr;
    }
    
void deleteValue(int value) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = tail;

    do {
        if (temp->data == value) {
            if (head == tail) {
                delete temp;
                head = tail = nullptr;
                return;
            }
            if (temp == head) {
                head = head->ptr;
                tail->ptr = head;
                delete temp;
                return;
            }
            prev->ptr = temp->ptr;
            if (temp == tail) {
                tail = prev;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->ptr;
    } while (temp != head);
    cout << "Value " << value << " not found" << endl;
}

void traverseSteps(int n) {
    cout << "Steps: ";
    if (head == nullptr || n <= 0) {
        cout << endl;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        cout << temp->data << " ";
        temp = temp->ptr;
    }
    cout << endl;
}

};
int main() {
    CircularLinkedList l;
    l.deleteFront(); // empty list
    l.insertEnd(10); 
    l.insertEnd(20); 
    l.insertEnd(40); 
    l.deleteFront();
    l.insertAfter(20, 30);
    l.insertAfter(99, 1); // target missing
    l.display(); 
    l.search(30); 
    l.search(99);
    cout << "Total nodes: " << l.count() << endl;
    l.deleteFront(); 
    l.DeleteEnd(); 
    l.deleteValue(20);
    l.display();
    l.traverseSteps(7); // list has only 2 nodes
    l.deleteFront(); 
    l.DeleteEnd(); // one-node list, then empty
    l.display();
    l.clearList();
    return 0;
}
