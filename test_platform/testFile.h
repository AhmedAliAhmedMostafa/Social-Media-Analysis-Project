#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<map>

using namespace std;
typedef struct  make_pair_of
    {
       int n =0;
       int m = 0;
       int data = -1;
    }m_and_n;
   
void stream_pos_init(map<int,long>&test_pos);
long r_file_w_console_pair(int&test_ID,bool&EOT,long&cwl,m_and_n&data);