#include <iostream>
#include <string>
using namespace std;

struct Cal {
  char op;
  float num;
  Cal* next;
};

void KeyBoard(string &input){
  cout << "Enter : ";
  cin >> input;
}

void BuildList (string input, Cal* &head, Cal* &tail, bool &valid){
  int i, len;
  char operation = '+';
  float number = 0;

  len = input.length();
  head = tail = NULL;

  for (i=0, valid=true; valid && i<=len; i++){
    if (input[i]>47 && input[i]<58) {number = number * 10 + input[i] - 48;}
    
    else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == 0) {
      Cal* c = new Cal {operation, number, NULL};

      if(head==NULL) {head = c;}
      else {tail->next = c;}
      
      tail = c;
			number = 0;
			operation = input[i];
	    
    }

    else {
			cout << "Invalid character detected!";
			valid = false;
		}
  }
  
}

void Compute(Cal* head, bool &valid, float &result) {
	Cal* move, * start, * end;
	char operation;
	
	for(move=head, start=NULL; valid && move->next!=NULL; move=move->next){

		operation = move->next->op;
		start = move;
		
		if(operation == '*') {start->num *= move->next->num;}
		
		else if (operation == '/') {
			if (move->next->num!=0) {start->num /= move->next->num;}
			else {valid = false;}
		}	
					
		else if ((operation == '+' || operation == '-') && start!=NULL){
			start->next = move->next;
			start = NULL;
		}
	}
}

void PrintList(Cal* head, bool valid, float result) {

	Cal* move = head;

	while (valid && move != NULL) {
		cout << "[" << move->op << "] " << move->num << endl;
		move = move->next;
	}

	if (valid) { cout << "[=]" << result; }
	else { cout << "Infinity :("; }

}

int main() {

	string input;
	Cal* head, * tail;
	bool valid = true;
	float result = 0;

	KeyBoard(input);
	BuildList(input, head, tail, valid);
	Compute(head, valid, result);
	PrintList(head, valid, result);

	return 0;
}
