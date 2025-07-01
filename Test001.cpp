#include <iostream>
using namespace std;

struct Node {
  int num;
  Node* next;
};

int main(){
  Node* head, * tail, * mover;
  int i;

  head=tail=NULL;

  for(i=1;i<=15;i++){
    Node* N = new Node {i,NULL};

    if(head=NULL) {
      head=N;      
    }
    else {
      mover=tail;
      mover->next=N;      
    }
    tail=N;    
  }

  mover=head;
  while (mover->next!=NULL){
    cout<<mover->num<<"]";
    mover=mover->next;
  }
  
  
  return 0;
} 
