#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;

	Node(int val, Node* n = NULL)
   	:value(val), next(n)   { }
};

struct List{
	Node* head;

	List(){
		head = nullptr;
	}

	Node* addFirst(int value){
		head = new Node(value, head);
		return head;
	}

	Node* insert(int p, int value){
		if(p < 0){
			return NULL;
		}

		if(p == 1){
			head = new Node(value, head);
			return head;
		}
		Node* n = head;
		for(int i = 1; i < p - 1; i++){
			n = n->next;
		}

		n->next = new Node(value, n->next);

		return n->next;

	}
	
	int deleteNode(int p){
		if(p <= 0 || head == NULL){
			return 0;
		}
		if(p == 1){
			Node* second = head->next;
			int value = head->value;

			delete head;
			head = second;

			return value;
		}

		Node* n = head;
		Node* t = head;
		for(int i = 0; i < p - 1; i++){
			n = n->next;
		}
		
		if(n == NULL){
			return 0;
		}
		
		for(int i = 0; i < p && t->next != n; i++){
			t = t->next;
		}

		t->next = n->next;

		int data;
		data = n->value;

		delete n;

		return data;
		
	}

	void print(){
		for(Node* p = head; p != NULL; p = p->next){
			cout << p->value << " ";
		}
		cout << endl;
	}
};


int main(int argc, char* argv[]){
	List ds;
	Node* head = NULL;
	int n;
	cin >> n;

	int i = 0;

	while(i < n){
		string s;
		cin >> s;

		int p, x;
		cin >> p;

		if(s == "insert"){
			cin >> x;
			ds.insert(p, x);
		}else{
			ds.deleteNode(p);
		}
		i++;
	}

	ds.print();

	return 0;

}