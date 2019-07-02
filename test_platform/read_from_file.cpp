#include"testFile.h"
map<int,long>test_pos;      
int main()                                                             
{    
    //=================== file stream variables ================      
    stream_pos_init(test_pos);    // <======== initailizes the test_pos to map the test_ID with its real starting position in the txt file                                                        
    int test_ID = -1;                 // you need only to enter the required test_ID                      
    bool EOT = 0;                                            
    int MAKE_TEST_NUM;
    cin>>MAKE_TEST_NUM;
    long c_str_pos = test_pos.find(MAKE_TEST_NUM)->second ;   // start of the required test
    
    // =================== problem variables ===================
    m_and_n ip;
    vector<int>MainVec;
    c_str_pos = r_file_w_console_pair(test_ID,EOT,c_str_pos,ip);
    while (!EOT)
    {
        c_str_pos = r_file_w_console_pair(test_ID,EOT,c_str_pos,ip);
        MainVec.push_back(ip.data);
        //cout<<"working on test ["<<test_ID<<"] at buffer :"<<c_str_pos<<"\n";
    }
    // for (int i=0; i<ip.n; i++) 
    //   cout << MainVec[i] << " ";
    // cout<<endl;
    return 0;
}
