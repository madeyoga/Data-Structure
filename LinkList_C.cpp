#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* create_new_node(int data)
{
	struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void show_list(struct Node* head)
{
	// loop through list
	while (head != NULL)
	{
		cout << head->data << ", ";
		head = head->next;
	}
}

int main() 
{
	// initial linked list attributes
	struct Node *head = NULL;
	struct Node *tail = NULL;

	int opsi = 0;
	while (true)
	{
		cout << "1. Add" << endl
			 << "2. Show" << endl
			 << "0. Exit" << endl
			 << "choose: ";
		cin >> opsi;
	
		if (opsi == 1)
		{
			int temp;
			cout << "input integer: ";
			cin >> temp;

			// check jika head null
			if (head == NULL)
			{
				head = create_new_node(temp);
				tail = head;
			}
			else
			{
				tail->next = create_new_node(temp);
				tail = tail->next;
			}
		}
		else if (opsi == 2)
		{
			show_list(head);
		}
		else if (opsi == 0)
		{
			break;
		}
		else
		{
			cout << "input tidak valid" << endl;
		}
	}

}