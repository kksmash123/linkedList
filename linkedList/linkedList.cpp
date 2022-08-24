#include<iostream>
using namespace std;


struct Node
{
	int data;

	struct Node *next;

}*head=NULL;




int recursivecountDown(struct Node* head)
{
	if (!head)
		return 0;
	return recursivecountDown(head->next) + 1;

}

int recursiveCount(struct Node* head )
{
	int x = 0;

	if (!head)
		return 0;
	cout << x << " ";
	x = recursiveCount(head->next) + 1;

	cout << x << " ";
	return x;
}

void countingNodes()
{
	struct Node* p = head;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;

	}
	cout << count;
}


void recursiveDisplay(struct Node* head)
{
	if (head)
	{
		cout << head->data << " ";
		recursiveDisplay(head->next);
		
	}
	


}


struct Node* RecursiveReverseLL(struct Node *head)
{
	if (!head->next || !head)
		return head;

	struct Node* temp;

	temp = RecursiveReverseLL(head->next);
	head->next->next = head;
	head->next = NULL;

	return temp;
}


void ReverseLL()
{
	struct Node* cur = head, * prev = NULL, * nxt = NULL;

	cout << endl << "Reverse of Linked List" << endl;

	while (cur)
	{
		nxt = cur->next;
		cur->next = prev;

		//moving 

		prev = cur;
		cur = nxt;
	}
	head = prev;

}


void Display(struct Node *head=NULL)
{
	struct Node* p = head;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}

}

void createLL(int a[], int n)
{
	struct Node* last = new Node;
	head = last;
	head->data = a[0];
	head->next = NULL;


	for (int i = 1;i < n;i++)
	{
		struct Node* p = new Node;
		//linking new node
		last->next = p;
		//filling the new node
		p->data = a[i];
		p->next = NULL;
		last = p;
	}

}

int main()
{
	int a[5] = { 10,20,30,40,50 };

	createLL(a, 5);

	//Display(head);

	//ReverseLL();
	//Display();
	//cout <<endl<< "after recursive reverse call " << endl;
	//Display(RecursiveReverseLL(head));
	
	//recursiveDisplay(head);

	//countingNodes();

	//recursiveCount(head);

	//cout<<recursivecountDown(head);




}