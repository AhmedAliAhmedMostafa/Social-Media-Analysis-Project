#include <iostream>
#include <fstream>
#include <string>
#include"header.h"
int main()
{
	ifstream infile;
	string path;
	char choice;
	cout<<"please enter input file path Or just write \"d\" to use the default file \n ";
	cin>>path;
	if(path=="d")
	{
		infile.open("default.txt");

	}
	else
		infile.open(path.c_str());
			if(infile.fail())
			{
				cout<<"Error opening the file \n";
				return 1;
			}
			else
			{
				cout<<"enter 1 for degree Or 2 for closeness or 3 for betweenes or 4 for all three\n ";
				cin>>choice;
				switch (choice)
				{
				case '1':
					cout<<"Degree Centrality :\n";
					deg_cent(infile);
					break;
				case '2':
					cout<<"closeness Centrality :\n";
					clos_cent(infile);
					break;
				default:
					break;
				}
				infile.close();
			}
			system("pause");

	return 0;
}
