#include<iostream>
#include<string>
using namespace std;

void MergeSort(int array[], int _low, int size) {
	
	int low = _low;
	int high = size;

	if (low >= high) {
		return ;
	}
	else{

		int middle = (low + high) / 2;

		MergeSort(array, low, middle);
		
		MergeSort(array, middle + 1, high);

		int end_low = middle;
		int start_high = middle + 1;

		while ((low <= end_low) && (start_high <= high)) {
			if (array[low] < array[start_high]) {
				low++;
			} else {
				int Temp = array[start_high];
				for (int k = start_high - 1; k >= low; k--)
				{
					array[k + 1] = array[k];
				}
				array[low] = Temp;
				low++;
				end_low++;
				start_high++;
			}
		}

	}	
}

void main()
{
	int data[] = { 90,44,108,46,0,33,47,59,900,333};

	cout << "sebelum : \n";
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << " ";
	}
	cout << "\n\n";

	QuickSort(data, 0, 9);
	cout << "sesudah : \n";
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << " ";
	}
	cout << "\n\n";

	getch();
}