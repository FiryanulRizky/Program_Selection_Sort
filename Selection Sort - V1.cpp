#include<iostream>
using namespace std;
#include<conio.h>

int main()
{
	int size, bil[50], a, b, temp;
	cout << "Masukkan Jumlah Angka : ";
	cin >> size;
	cout << "Masukkan Elements Angka : \n";
	for (a = 0; a<size; a++)
	{
	    cout << "Data angka ke - "<<a+1<<" : ";cin>>bil[a];
	}
	cout << "Sorting bilangan dengan selection sort...\n";
	for (a = 0; a<size; a++)
	{
		for (b = a + 1; b<size; b++)
		{
			if (bil[a]>bil[b])
			{
				temp = bil[a];
				bil[a] = bil[b];
				bil[b] = temp;
			}
		}
	}
	cout << "Hasil Sorting Adalah :\n";
	for (a = 0; a<size; a++)
	{
		cout << bil[a] << " ";
	}
	getch();
}
