#include<iostream>
using namespace std;

struct Node
{
	int data;

	struct Node *next;

}*head=NULL,*glast=NULL;

int countingNodes();


void RemoveDuplicates()
{

	struct Node* cur, * prev;

	prev = head;
	cur = head->next;

	if (!head || !head->next)
		return;

	while (cur)
	{

		if (prev->data != cur->data)
		{
			prev = cur;
			cur = cur->next;
		}
		else
		{
			prev->next = cur->next;
			delete cur;
			cur = prev->next;
		}

	}

}


void IsSorted2()
{
	struct Node* p = head;

	if (!head || !head->next)
	{
		cout << "empty list or single element list - no need sorting ";
	}

	while (p->next && p->data < p->next->data)
		p = p->next;

	if (!p->next)
		cout << "List is sorted";
	else
		cout << "List is not sorted";

}


void IsSorted()
{
	struct Node* p = head;

	if (!head || !head->next)
	{
		cout << "Empty list or list with single element no need to sort";
		return;
	}

	int x = INT_MIN;

	while (p)
	{
		if (p->data < x)
			break;

		x = p->data;
		p = p->next;
	}

	if (!p)
		cout << "Linked List is Sorted";
	else
		cout << "Linked List is not Sorted";


}


void deleteWithValue(int val)
{
	struct Node* cur, * pre;
	cur = head;
	pre = NULL;

	if (val == head->data)
	{
		head = head->next;
		delete cur;
		return;
	}

	while (cur && cur->data != val)
	{
		pre = cur;
		cur = cur->next;
	}
	if (!cur)
	{
		cout << endl << "Given value not found in list -> Deletion not performed" << endl;
		return;
	}
	pre->next = cur->next;

	delete cur;
}


void deleteWithPosition(int pos)
{
	struct Node* cur, * prev;
	prev = NULL;
	cur = head;

	if (pos == 1)
	{
		head = head->next;
		delete cur;
		return;
	}
	if (pos<=0 || pos > countingNodes())
	{
		cout<<endl << "Invalid position is given -> Deletion not possible " << endl;
		return;
	}
	
	
	for (int i = 1;i < pos && cur;i++)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;

	delete cur;


}


void InsertInSortedList2(int val)
{

	struct Node* cur = head , *newnode = new Node;

	newnode->data = val;
	newnode->next = NULL;

	if (!head)
	{
		head = newnode;
		return;
	}

	if (val < head->data)
	{
		newnode->next = head;
		head = newnode;
		return;
	}

	while (cur->next && cur->next->data < val)
		cur = cur->next;
	
	newnode->next=cur->next;
	cur->next = newnode;
}


void InsertInSortedList(int val)
{
	struct Node* cur, * prev ;

	cur = head?head->next:NULL;
	prev = head;
	struct Node* newNode = new Node;

	newNode->data = val;
	newNode->next = NULL;

	if (!head)
	{
		head = newNode;
		return;
	}
	
	if (val < head->data)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	
	while ( cur && cur->data < val)
	{
		prev = cur;
		cur = cur->next;
	}
	newNode->next=prev->next;
	prev->next = newNode;

}


void InsertAtLast(int val)
{
	struct Node * newNode;
	struct Node* first=head;
	struct Node* last=glast;

	newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
		head = first;
		
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	
	glast = last;

}

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
	cout << endl;
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
	int a[5] = { 10,10,20,50,50};

	createLL(a, 5);

	Display(head);

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
	
	/*InsertAtLast(20);
	InsertAtLast(400);
	InsertAtLast(300);
	InsertAtLast(70);
	Display(head);*/


	/*int a[5] = { 10,20,30,60,100 };

	createLL(a, 5);

	Display(head);

	InsertInSortedList(150);
	cout << endl << "after insertion " << endl;

	Display(head);*/


	/*int a[5] = { 10,20,30,60,100 };

	createLL(a, 5);

	Display(head);

	InsertInSortedList2(90);
	cout << endl << "after insertion " << endl;

	Display(head);*/


	/*deleteWithPosition(0);
	cout << endl << "after deletion " << endl;
	Display(head);*/


	/*deleteWithValue(50);
	cout << endl << "after deletion " << endl;
	Display(head);*/

	//IsSorted();

	//IsSorted2();

	RemoveDuplicates();
	cout << endl << "after removing duplicates" << endl;
	Display(head);


}