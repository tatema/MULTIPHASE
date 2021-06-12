#include <iostream>
#include <string>
using namespace std;
struct Node {
	string name;
	int start;
	int end;
	Node* next;
};

Node* add(Node *,Node *);
void display(Node *);
bool check(Node *head)
{
	if (head == NULL || head->next == NULL)
		return true;
	Node *p = head->next;
	if (head->start > p->start) return false;
	return check(p);
}
	int main() 
	{
		Node *head = NULL, *p;
		int i,repeat;
		cin >> repeat;
		for (i = 0; i < repeat; i++) {
			p = new Node;
			cin >> p -> name >> p->start >> p -> end;
			p->next = NULL;
			head = add(head, p);
		}
		if (!check(head))
			cout << "ERROR" << endl  ;

		display(head);
		return 0;
	}
