#include <string>
#include <iostream>
using namespace std;
#include <fstream>

fstream f2001, f2002, f2003, f2004, f2005, f2006, f2007, f2008, f2009, f2010;

unsigned int lookupRank(unsigned year,string gender,string name);

int main()
{
	unsigned int ranking = 0;
	unsigned int cyear;
	cout << "Enter the year: ";
	cin >> cyear;
	string cgender;
	cout << "Enter the gender: ";
	cin >> cgender;
	cout << "Enter the name: ";
	string cname;
	cin >> cname;

	ranking = lookupRank(cyear, cgender, cname);

	if (ranking == 0)
		cout <<"The name "<< cname << " is not ranked in year " << cyear << endl;
	else
		cout << cname << " is ranked #" << ranking << " in year " << cyear << endl;


	return 0; 
}

unsigned int lookupRank(unsigned year, string gender, string name)
{

	string str;
	unsigned int ranking = 0;
	char rank[1000];


	fstream file;

	switch (year)
	{
	case 2001:
		file.open("babynameranking2001.txt", ios::in);
		break;
	case 2002:
		file.open("babynameranking2002.txt", ios::in);
		break;
	case 2003:
		file.open("babynameranking2003.txt", ios::in);
		break;
	case 2004:
		file.open("babynameranking2004.txt", ios::in);
		break;
	case 2005:
		file.open("babynameranking2005.txt", ios::in);
		break;
	case 2006:
		file.open("babynameranking2006.txt", ios::in);
		break;
	case 2007:
		file.open("babynameranking2007.txt", ios::in);
		break;
	case 2008:
		file.open("babynameranking2008.txt", ios::in);
		break;
	case 2009:
		file.open("babynameranking2009.txt", ios::in);
		break;
	case 2010:
		file.open("babynameranking2010.txt", ios::in);
		break;
	default:
		cout << year << " is not valid" << endl;
		return ranking;
	}

	//read the file line by line till end
	while (getline(file, str) && !file.eof())
	{
		if (file.eof()) break;
		
		for (int i = 0; i < str.length(); i++)
		{
			if (gender == "M")
			{
				if (!isalpha(str[i]))
				{
					i++;
				}
				string maleName(&str[i]); //using strings constructor to complete this

				if (strncmp(name.c_str(), maleName.c_str(), name.length()) == 0) //if user input name matches a name in file 
				{
					strncpy(rank, str.c_str(), i);
					ranking = stoi(rank);
					file.close();
					return ranking;
				}
			}
			else if (gender == "F")
			{
				if (!isalpha(str[i]))
				{
					i++;
				}

				string femaleName(&str[i]);

				if (strncmp(name.c_str(), femaleName.c_str(), name.length()) == 0)
				{
					strncpy(rank, str.c_str(), i);
					ranking = stoi(rank);
					file.close();
					return ranking;
				}

			}
			else
			{
				cout << "Gender must be M or F" << endl;
				file.close();
				return ranking;
			}
		} 
	} 
	return ranking;
}
