#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    
    Node(int val, Node* n)
    :value(val), next(n) {}
    
};

struct Stack{
    Node* head;

    Stack(){
        head = NULL;
    }

    Node* push(int x){
        if(head == NULL){
            head = new Node(x, head);
            return head;
        }

        Node* p = head;
        for(;p->next != NULL; p = p->next){}

        Node* newNode = new Node(x, NULL);
        
        newNode->next = p->next;

        p->next = newNode;

        return newNode;
    }

    void pop(){
        if(head == NULL){
            return ;
        }

        if(head->next == NULL){
            delete head;
            head = NULL;
            return ;
        }

        Node* p = head;
        for(; p->next->next != NULL; p = p->next){}

        delete p->next;

        p->next = NULL;

    }



    void print(){
        for(Node* p = head; p != NULL; p= p->next){
            cout << p->value << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack st;
    int n;
    cin >> n;
    int i = 0;
    while(i < n){
        string s;
        cin >> s;
        int x;
        if(s == "push"){
            cin >> x;
            st.push(x);
        }else if(s == "pop"){
            st.pop();
        }

        i++;
    }

    st.print();
}