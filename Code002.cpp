#include <iostream>
#include <cstring>

using namespace std;

class Calculator {
public:

  int num;
  Calculator* next;

  void InsertNode(Calculator* &head);
};

void Calculator::InsertNode(Calculator* &head){
  Calculator* temp;

  Calculator* C = new Calculator (4,NULL);

  if(head=NULL) head = C;
  else {
    temp = head;
    while(temp->next != NULL){
      temp = temp->next;      
    }
  }
}

int main(){

}
