#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{

	srand(time(NULL));

	ofstream exercise_file;

	//Open file, or create if file does not exist
	exercise_file.open("Exercise13_1.txt");
	
	int count = 0;
	int line = 0;
	while (count < 100)
	{
		exercise_file << rand() % 10 << " ";
		count++;
		line++;
		if (line == 15)
		{
			exercise_file << endl;
			line = 0;
		}
	}

	exercise_file.close();

	return 0;



}