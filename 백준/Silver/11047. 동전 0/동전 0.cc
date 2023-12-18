#include<iostream>

using namespace std;

int main()
{
	int num;
	int money;
	int min = 0;
	cin >> num >> money;

	int* arr = new int[num];

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < num; i++)
	{  
		while (money - arr[num - i - 1] >= 0)
		{
			money -= arr[num - i - 1];
			min++;
		}
	}
	
	cout << min;

}
  