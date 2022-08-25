#include<iostream>
using namespace std;


struct Node
{
	int data;

	struct Node *next;

}*head=NULL;

int countingNodes();







void InsertLL(int pos, int val)
{

	if (pos<0 || pos > countingNodes())
		return;

	struct Node* newNode = new Node, * t = head;
	int i;

	newNode->data = val;

	if (pos == 0)
	{
		newNode->next = head;

		head = newNode;
	}

	else
	{
		for (i = 1;i < pos;i++)
			t = t->next;

		newNode->next = t->next;
		t->next= newNode;

	}


}





void LsearchSwap(int x)
{
	struct Node* cur = head, * prev = NULL, * pprev = NULL;

	while (cur)
	{
		if (x == cur->data)
		{
			pprev->next = cur;
			prev->next = cur->next;
			cur->next=prev;
		}

		pprev = prev;
		prev = cur;
		cur = cur->next;
	}

	                    
}



void LsearchMoveToFront(int x)
{
	struct Node* cur = head,*prev=NULL;

	while (cur)
	{
		if (x == cur->data)
		{
			prev->next = cur->next;
			cur->next = head;
			head = cur;
		}

		prev = cur;
		cur = cur->next;
	}

}


bool recurLsearch(struct Node * head,int x)
{
	if (!head)
	{
		cout << "element not found";
		return 0;
	}

	if (x == head->data)
	{
		cout << "element found";
		return 1;
	}

	recurLsearch(head->next, x);

}


void LinearSearch(int x)
{
	struct Node* p = head;

	while (p)
	{
		if (x == p->data)
		{
			cout << "element found ";
			break;
		}

		p = p->next;

	}

	if (!p)
		cout << "element not found ";

}


int recurMax2(struct Node* head)
{
	int x = 0;

	if (!head)
		return INT_MIN;
	x = recurMax2(head->next);

	return x > head->data ? x : head->data;


}

int RecurMaxValLL(struct Node* head)
{
	
	static int maxv = INT_MIN;

	if (!head)
		return 0;

	
	maxv = max(head->data, maxv);

	RecurMaxValLL(head->next);

	return maxv;
}


void maxLL()
{
	struct Node* p = head;
	int maxVal = INT_MIN;
	while (p)
	{
		maxVal = max(maxVal, p->data);
		p = p->next;
	}


	cout << maxVal;

}


int recursiveSum(struct Node* head)
{
	if (!head)
		return 0;
	return recursiveSum(head->next) + head->data;

}

void sumLL()
{
	int sum = 0;

	struct Node* p = head;

	while (p)
	{
		sum += p->data;
		p = p->next;
	}

	cout << sum;
}


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

int countingNodes()
{
	struct Node* p = head;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;

	}
	return count;
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


void Display(struct Node *head)
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

	//sumLL();

	//cout<<recursiveSum(head);

	//maxLL();

	//cout<<RecurMaxValLL(head);

	//cout << recurMax2(head);

	//LinearSearch(3);

	//recurLsearch(head, 30);

	//LsearchMoveToFront(30);
	//Display(head);

	//LsearchSwap(30);
	//Display(head);


	//InsertLL(4, 100);
	//Display(head);


}