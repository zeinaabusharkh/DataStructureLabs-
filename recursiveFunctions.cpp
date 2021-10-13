
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int char2value(char c)
{
    int value = int(c);
    if(c <=int('9')){  return (value- 48);}
    return int(c)- int('A')+10;
}


int get2hex(char c1, char c0)
{
  return char2value(c1)*16 + char2value(c0);
}


int checkSum(string s, int sum=0)
{ 
   
    if( s[0]== int('S')){s = s.substr(2,s.size()-2); }
    if(s.size()==0) {return sum;}
    return checkSum( s.substr(2 , s.size()-2) , (sum + get2hex(s[0], s[1]))%256 ); 
   
}


int main()
{
   
   int sum;
 string line;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    cout<<"--------------------------------------------"<<endl;
    cout<<"Input Line? "+line <<endl;
    cout<<"Checksum value? "+ checkSum(line)<<endl;  
    if(checkSum(line) ==255){ cout<<" correct "<<endl;}else{ cout<<"erroneous"<<endl;}
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
    return 0;
}
