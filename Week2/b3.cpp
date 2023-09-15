#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;

    Node(int val, Node* n = NULL, Node* p = NULL)
    :value(val), next(n), prev(p) {}
};

struct DList{
    Node* head;
    Node* tail;

    DList(){
        head = NULL;
        tail = NULL;
    }

    void add(int value){
        if(head == NULL){
            head = tail = new Node(value, head, tail);
            return;
        }
        Node* p = head;
        for(; p != tail; p = p->next){

        }

        Node* newNode = new Node(value, NULL, NULL);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int count_triplets(){
        int count = 0;
        for(Node* p = head; p->next->next != NULL; p = p->next){
            if(p->value + (p->next)->value + (p->next->next)->value == 0){
                count++;
            }
        }
        return count;
    }

    void print(){
        for(Node* p = head; p != NULL; p = p->next){
            cout << p->value <<  " ";
        }
        cout << endl;
    }
};

int main(){
    DList ds;

    int n;
    cin >> n;
    int i = 0;
    while(i < n){
        int x;
        cin >> x;
        ds.add(x);
        i++;
    }

    cout << ds.count_triplets() << endl;

    return 0;
}