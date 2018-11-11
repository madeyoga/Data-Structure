// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
int BinarySearch(string arr[], int left, int right, string x) {
	if (right >= 1) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[left] == x) {
			return left;
		}
		else if (arr[right] == x) {
			return right;
		}
		if (arr[mid] < x) {
			return BinarySearch(arr, mid + 1, right, x);
		}
		else {
			return BinarySearch(arr, left, mid - 1, x);
		}
	}

	return -1;
}
void swap(string &str1, string &str2) {
	string temp = str1;
	str1 = str2;
	str2 = temp;
}
void BubbleSortArrOfString(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}
void QuickSortArrOfString(string arr[], int left, int right) {
	int i = left, j = right;
	string pivot = arr[(left + right) / 2];
	// partition
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			string tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	// recursion
	if (left < j) {
		QuickSortArrOfString(arr, left, j);
	}
	if (i < right) {
		QuickSortArrOfString(arr, i, right);
	}
}
int main()
{
	string arr[50] = { "buku", "lampu", "makan", "orang" };
	int index = 4;
	int choose;
	while (true) {
		cout << "DATA : \n";
		for (int i = 0; i < index; i++) {
			cout << i + 1 << ". " << arr[i] << "\n";
		}cout << endl;
		cout << "OPTION:\n1. Add\n"
			<< "2. Search\n"
			<< "0. Exit\n"
			<< ">> ";
		cin >> choose;
		if (choose == 1) {
			string item;
			cout << "input new item : ";
			cin >> item;
			arr[index] = item;
			index++;
			// BubbleSortArrOfString(arr, index);
			QuickSortArrOfString(arr, 0, index - 1);
		}
		else if (choose == 2) {
			string search;
			cout << "input : ";
			cin >> search;
			int i = BinarySearch(arr, 0, index - 1, search);
			if (i == -1) {
				cout << "item not found" << endl;
			} else {
				cout << search << " berada pada index ke-" << i << endl;
			}
		}
		else { break; } // handle
		system("pause");
		system("cls");
	}
    return 0;
}

