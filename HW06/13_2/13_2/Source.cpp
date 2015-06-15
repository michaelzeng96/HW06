#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{


	fstream inout;

	inout.open("test.txt", ios::out);

	inout << "four";

	inout.close();

	string inputFileName;

	cout << "User enter file name. Example: city.txt " << endl;

	cin >> inputFileName;

	inout.open(inputFileName, ios::in);

	if (inout.fail())
	{
		cout << inputFileName << " does not exist" << endl;
		cout << "Exit program" << endl;
		return 0;
	}

	char get = inout.get();  
	int count = 0; //startinga at 0 takes care of the input.eof() failing to become false after the last char 
	while (!inout.eof())
	{
		get = inout.get(); //extracts next char
		count++; //increments count
	}

	cout << "Number of characters in the file is " << count << endl;


	return 0;
}