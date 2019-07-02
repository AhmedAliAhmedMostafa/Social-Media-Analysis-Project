#include"testFile.h"
void stream_pos_init(map<int,long>&test_pos)
{

    ifstream test_cases;
    string line;
    int test_ID = 0;           // ID of test
    bool mutex = 1;              // used for allowing only one extra getline at start of the test <not at end>
    test_cases.open("test.txt");
    if(!(test_cases.is_open()))
       {
           std::cerr<<"test file could't be opened\n";
           return ;
       } 
    else
    {
        test_cases.seekg(0,ios::beg);
        while(getline(test_cases,line))     // will get out if EOF is reached or if failed
        {
            if(!(line.substr(0,7).compare("=======")))
            {
                char num_index = line.find("test ",20)+5;
                test_ID = stoi(line.substr(num_index,line.find(" ",num_index)));
                if(mutex)
                    {
                        //cout<<(char)test_cases.peek()<<"\n";
                        test_pos.insert({test_ID,test_cases.tellg()});
                        mutex = 0;
                    }
                else
                {
                    mutex = 1;
                }
            }
        }
        test_cases.close();
    
    }
    return;
}