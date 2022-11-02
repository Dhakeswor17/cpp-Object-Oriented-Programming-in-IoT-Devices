#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string_arry[10];
	int total_char = 0;
	for (int i = 1; i <=10; i++)
	{
		cout << "Enter string " << i << ":";
		cin >> string_arry[i];
	}

	for (string str : string_arry)
	{
		cout << str << "\n";
		total_char += str.size();
	}

	cout << "\nTotal characters:" << total_char;
}

