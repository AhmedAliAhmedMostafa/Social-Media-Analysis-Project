#include"testFile.h"
long r_file_w_console_pair(int&test_ID,bool&EOT,long&cwl,m_and_n&data )       // where <EOT> is END OF Test and <cwl> is currernt working line
{
    
    ifstream test_cases;
    string line;
    static bool mutex = 1;      // used for allowing only one extra getline at start of the test <not at end>
    test_cases.open("test.txt");
    if(!(test_cases.is_open()))
       {
           std::cerr<<"test file could't be opened\n";
           
           return -1;
       } 
    else
    {
        test_cases.seekg(cwl,ios::beg);
        if(getline(test_cases,line))     // will get out if EOF is reached or if failed
        {
            if(!(line.substr(0,7).compare("=======")))
            {
                char num_index = line.find("test ",20)+5;
                test_ID = stoi(line.substr(num_index,line.find(" ",num_index)));
                
                        mutex = 1;
                        EOT = 1;
                        long c_line = test_cases.tellg();
                        test_cases.close();
                        return c_line;
                    
            }   
            if(mutex)
            {
                mutex = 0;
                EOT = 0;
                data.m = stoi(line.substr(0,line.find(" ")));
                data.n = stoi(line.substr(line.find(" ")));
                
                return test_cases.tellg();
            }
            data.data = stoi(line);

        }
    }
    return test_cases.tellg();
}