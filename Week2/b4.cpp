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

    Node* queue(int x){
        if(head == NULL){
            head = new Node(x, head);
            return head;
        }

        Node* p = head;
        for(; p->next != NULL; p = p->next){

        }

        Node* newNode = new Node(x, NULL);

        newNode->next = p->next;
        p->next = newNode;

        return newNode;
        
    }


    void print(){
        for(Node* p = head; p != NULL; p = p->next){
            cout << p->value << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue qu;
    int n;
    cin >> n;
    int i = 0;
    while(i < n){
        string s;
        int x;
        cin >> s;
        if(s == "enqueue"){
            cin >> x;
            qu.queue(x);
        }else if(s == "dequeue"){
            qu.dequeue();
        }
        i++;
    }

    qu.print();
}