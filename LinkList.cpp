#include <iostream>
using namespace std;

// template <typename Type>
class Node { // element single link list
	Node* next;
	int data;
public :
	Node () {
		next = NULL;
	}

	int getData() {
		return data;
	}

	void setData(int _data) {
		data = _data;
	}

	Node* getNext() {
		return next;
	}

	void setNext (Node* _next) {
		next = _next;
	}

};

class NodeDL {
	int data;
	NodeDL *next;
	NodeDL *prev;
public :
	NodeDL () {
		next = NULL;
		prev = NULL;
	}

	int getData() {
		return data;
	}

	void setData(int _data) {
		data = _data;
	}

	NodeDL* getNext() {
		return next;
	}

	void setNext (NodeDL* _next) {
		next = _next;
	}

	NodeDL* getPrev () {
		return prev;
	}

	void setPrev (NodeDL* _prev) {
		prev = _prev;
	}

};

class slLinkedList { // single linear linked list
	Node *head;
	Node *tail;
public:
	slLinkedList () {
		head = NULL;
		tail = NULL;
	}

	void add (int x) {
		Node *baru = new Node;
		baru->setData(x);
		if(!head) { // if Head == NULL 
			head = baru;
			tail = baru;
		} else {
			tail->setNext(baru);
			tail = baru;
		}
	}

	void view () {
		cout << "ISI" << endl;
		Node *temp;
		temp = head;
		while ( temp ) { // temp != NULL
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}

	void DelBack() {
		Node *temp;
		temp = head;
		while ( temp->getNext()->getNext() ) {
			temp = temp->getNext();
		} 
		temp->setNext(NULL);
		tail = temp;
	}

	void DelFront() {
		head = head->getNext();
	}

};

class dlLinkedList {
	NodeDL *head;
	NodeDL *tail;
public :
	dlLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void add (int _data) {
		NodeDL *temp = new NodeDL;
		temp->setData(_data);
		if (!head) {
			head = temp;
			tail = temp;
		} else {
			tail->setNext(temp);
			temp->setPrev(tail);
			// temp->setNext(NULL);
			tail = temp;
		}
	}

	void viewDescending() {
		NodeDL *temp = head;
		cout << "ISI DESCENDING" << endl;
		while ( temp ) {
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}

	void viewAscending() {
		NodeDL *temp = tail;
		cout << "ISI ASCENDING" << endl;
		while( temp ) {
			cout << temp->getData() << endl;
			temp = temp->getPrev();
		}
	}

	void view () {
		NodeDL *temp = head;
		cout << "ISI" << endl;
		while (temp) {
			cout << temp->getData() << endl;
			temp = temp->getNext();
		} 
	}

};

void main ()
{
	slLinkedList a;
	// a.view();
	a.add(10);
	a.add(20);
	a.add(30);
	// a.DelBack();
	a.DelFront();
	a.view();

	dlLinkedList b;
	b.add(30);
	b.add(20);
	b.add(10);
	b.viewAscending();
	b.viewDescending();
}