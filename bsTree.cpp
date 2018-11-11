
#include "stdafx.h"
#include <iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

template <typename T> class bsNode {
public:
	T data; // kata 
	T data2; // arti kata
	bsNode<T> *right;
	bsNode<T> *left;
	bsNode() {
		left = NULL;
		right = NULL;
	} void setData(T _data) {
		data = _data;
	} T getData() {
		return data;
	} void setRight(bsNode<T> *_right) {
		right = _right;
	} bsNode<T>* getRight() {
		return right;
	} void setLeft(bsNode<T> *_left) {
		left = _left;
	} bsNode<T>* getleft() {
		return left;
	} void add(bsNode<T> *x) {
		if (x->getData() < data) {
			if (left == NULL) {
				left = x;
			}
			else {
				left->add(x);
			}
		}
		else {
			if (right == NULL) {
				right = x;
			}
			else {
				right->add(x);
			}
		}
	}
};

template <typename T> class bsTree {
public:
	bsNode<T> *root;
	int size;
	bsTree() {
		size = 0;
		root = NULL;
	} void add(T x, T x2) {
		bsNode<T> *baru = new bsNode<T>;
		baru->setData(x);
		baru->data2 = x2;
		if (root == NULL)
			root = baru;
		else
			root->add(baru);
		size++;
	} void dfsInorder(bsNode<T> *temp = NULL) {
		if (temp == NULL) {
			temp = root;
		}
		if (temp->getleft() != NULL) {
			dfsInorder(temp->getleft());
		}
		if (temp->getData().length() < 9)
			cout << temp->getData() << "\t\t: " << temp->data2 << endl;
		else 
			cout << temp->getData() << "\t: " << temp->data2 << endl;
		if (temp->getRight() != NULL) {
			dfsInorder(temp->getRight());
		}
	} void bfs(bsNode<T> *temp = NULL) {
		if (temp == NULL) {
			temp = root;
		}
		queue<bsNode<T>*> q;
		q.push(temp);
		while (!q.empty()) {
			bsNode<T> *another = q.front();
			q.pop();
			cout << another->getData() << " ";

			if (another->getleft()) {
				q.push(another->getleft());
			}

			if (another->getRight()) {
				q.push(another->getRight());
			}
		}
	} void dfsPreorder(bsNode<T> *temp = NULL) {
		if (temp == NULL) {
			temp = root;
		}
		cout << temp->getData() << " : " << temp->data2 << endl;
		if (temp->getleft() != NULL) {
			dfsInorder(temp->getleft());
		}
		if (temp->getRight() != NULL) {
			dfsInorder(temp->getRight());
		}
	} void dfsPostorder(bsNode<T> *temp = NULL) {
		if (temp == NULL) {
			temp = root;
		}
		if (temp->getleft() != NULL) {
			dfsInorder(temp->getleft());
		}
		if (temp->getRight() != NULL) {
			dfsInorder(temp->getRight());
		}
		cout << temp->getData() << " : " << temp->data2 << endl;
	} T minData() {
		bsNode<T>*temp = root;
		while (temp) {
			if (temp->getleft() != NULL)
				temp = temp->getleft();
			else break;
		}
		return temp->getData();
	} T maxData() {
		bsNode<T>*temp = root;
		while (temp) {
			if (temp->getRight() != NULL)
				temp = temp->getRight();
			else break;
		}
		return temp->getData();
	} int getSize() {
		return size;
	}


	T closestValue(T x) {
		int distance = 0;
		bsNode<T> *temp = root;
		distance = abs(temp->getData() - x);
		T key;
		while (temp->getRight() != NULL || temp->getleft() != NULL) {
			if (distance > abs(temp->getRight()->getData() - x)) {
				temp = temp->getRight();
				key = temp->getData();
			}
			else if (distance > abs(temp->getleft()->getData() - x)) {
				temp = temp->getleft();
				key = temp->getData();
			}
			else {
				key = temp->getData();
				break;
			}

		}
		return key;
	} int maxChildDepth() {
		int count = 1;
		bsNode<T>*temp = root;
		while (temp) {
			if (temp->getRight()->getRight() != NULL) {
				temp = temp->getRight();
				count++;
			}
			else if (temp->getRight()->getleft() != NULL) {
				temp = temp->getRight();
				count++;
			}
			else if (temp->getleft()->getRight() != NULL) {
				temp = temp->getleft();
				count++;
			}
			else if (temp->getleft()->getleft() != NULL) {
				temp = temp->getleft();
				count++;
			}
			else { count++; break; }

		}
		return count;
	} T secondMinValue() {
		bsNode<T>*temp = root;
		while (temp) {
			if (temp->getRight()->getRight() != NULL) {
				temp = temp->getRight();
			}
			else break;
		}
		return temp->getData();
	}

	bsNode <T> *search_recursively(T key, bsNode<T>*node) {
		if (node == NULL || node->data == key || node->data2 == key) 
			return node;
		else if (key < node->data) 
			return search_recursively(key, node->left);
		return search_recursively(key, node->right);
	}

};

int main()
{
	bsTree <string> dictionary;

	fstream Read2;
	Read2.open("data2.txt", ios_base::in);

	while (!Read2.eof()) {
		string baru, arti;
		getline(Read2, baru, ',');
		getline(Read2, arti, '\n');
		dictionary.add(baru, arti);
	}

	int option = 1;

	while (option != 0) {

		cout << "<:OFFLINE DICTIONARY:>" << endl;
		cout << "1. Search Kata\n"
			 << "2. Tampilkan Isi Kamus\n"
			 << "3. Tambah Kalimat ke dictionary\n"
			 << "0. Exit\n"
			 << ">> ";
		cin >> option;
		if (option == 1) {
			string key;
			cout << "input kata : ";
			cin >> key;
			bsNode<string> *node = dictionary.search_recursively(key, dictionary.root);
			if (node != NULL)
				cout << node->data << " means " << node->data2 << endl;
			else
				cout << "Not Found" << endl;
		}
		else if (option == 2) {
			dictionary.dfsInorder();
		}
		else if (option == 3) {
			string baru, arti;
			cout << "input kata baru : ";
			cin >> baru;
			cout << "input arti kata : ";
			cin >> arti;
			dictionary.add(baru, arti);
			fstream f;
			f.open("data2.txt", ios_base::app);
			f << "\n" << baru << ',' << arti;
			f.close();
		}
		else
			option = 0; // handle
		system("pause");
		system("cls");

	}

	return 0;
}



