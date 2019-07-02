#include <iostream>
#include <fstream>
#include <string>
#include"header.h" 
void open (ifstream &infile)
{
		infile.open("default.txt");

			if(infile.fail())
			{
				cout<<"Error opening the file \n";
				
			}
}
int main()
{
	ifstream infile;
	char choice;

				do
				{
				cout<<"enter 1 for degree Or 2 for closeness or 3 for betweenes or e for exit \n ";
				cin>>choice;
				switch (choice)
				{
				case '1':
					open(infile);
					cout<<"Degree Centrality :\n";
					deg_cent(infile);
					infile.close();
					break;
				case '2':
					open (infile);
					cout<<"closeness Centrality :\n";
					clos_cent(infile);
					infile.close();
					break;
				case'3':
					break;
				default:
					choice='e';
					break;
				
				}
				}while (choice !='e');
				
			
			

	return 0;
}
