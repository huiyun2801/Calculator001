#include <iostream>
#include <string>

using namespace std;

struct Cal {
	char op;
	int num;
	Cal* next;
};


void KeyBoard(string &str) {

	cout << "Enter : ";
	cin >> str;

}

void BuildList(string str, Cal* &head, bool &valid) {

	size_t i, len = str.length();
	int number = 0;
	char operation = '+';
	Cal* temp;

	head = temp = NULL;

	for (i = 0, valid = true; valid && i <= len; i++) {

		if (str[i] > 47 && str[i] < 58) {
			number = number * 10 + (str[i] - 48);
		}

		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == 0) {

			Cal* c = new Cal{ operation, number, NULL };

			if (head == NULL) {
				head = c;
			}

			else {
				temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = c;
			}
			operation = str[i];
			number = 0;
		}

		else {
			cout << "Invalid character detected!";
			valid = false;
		}

	}
}

void Compute(Cal* head, bool &valid, float &result) {
	Cal* temp = head;

	result = 0;

	while (valid && temp != NULL) {
		switch (temp->op) {

		case '+':
			result += temp->num;
			break;
		case '-':
			result -= temp->num;
			break;
		case '*':
			result *= temp->num;
			break;
		case '/':
			if (temp->num == 0) { valid = false; }
			else { result /= temp->num; }
			break;
		default:
			break;

		}

		temp = temp->next;
	}

}

void PrintList(Cal* head, bool valid, float result) {

	Cal* temp = head;

	while (valid && temp != NULL) {
		cout << "[" << temp->op << "] " << temp->num << endl;
		temp = temp->next;
	}

	if (valid) { cout << "[=]" << result; }
	else { cout << "Infinity :("; }

}

int main() {

	string input;
	Cal* head;
	bool valid = true;
	float result = 0;

	KeyBoard(input);
	BuildList(input, head, valid);
	Compute(head, valid, result);
	PrintList(head, valid, result);

	return 0;
}
