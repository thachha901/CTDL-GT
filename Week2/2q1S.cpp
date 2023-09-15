#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;

    Node(int val, Node* n)
    :value(val), next(n) { }
};

struct Queue{
    Node* head;

    Queue(){
        head = NULL;
    }

    Node* enqueue(int x){
        if(head == NULL){
            head = new Node(x, head);
            return head;
        }

        Node* p = head;
        for(;p->next != NULL; p = p->next){

        }

        Node* newNode = new Node(x, NULL);

        newNode->next = p->next;
        p->next = newNode;

        return newNode;
    }

    int dequeue(){
        if(head == NULL || head->next == NULL){
            return 0;
        }

        Node* second = head->next;
        int val = head->value;

        delete head;
        head = second;

        return val;
    }

    int getFirst(){
        return head->value;
    }

    void print(){
        for(Node* p = head; p != NULL; p =p->next){
            cout << p->value << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q, q2;
    int n;
    cin >> n;

    int i = 0;
    while(i < n){
        string s;
        cin >> s;
        int x;

        if(s == "add"){
            cin >> x;
            q.enqueue(x);
        }else if(s == "delete"){
            q2.enqueue(q.getFirst());  
            q.dequeue();   
        }
        i++;
    }

    q.print();

    q2.print();

    return 0;
}