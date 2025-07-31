#include <iostream>
#include <string>

using namespace std;

struct Node {
  int num;
  Node* next; 
};

void BuildList(Node* &head, Node* &tail) {

int i;
Node* move;

head = tail = move = NULL;

for(i=0;i<20;i+=2;){

  Node* n = new Node{i, NULL);
  
  while (move->next!=NULL){
    if(head=NULL){head = n;}
    else{
      move = tail;
      move-next = n;
    }
    tail = n;    
  }
}
  
}
void PrintList(Node* head){

Node* move = head;

while(move!=NULL){
  cout << move->num << " :: " << move->next->num << endl;
}
  
}

int main() {
	
	Node* head, * tail;
	bool valid = true;
	float result = 0;

	BuildList(head, tail);
	PrintList(head);

	return 0;
}
  
  

