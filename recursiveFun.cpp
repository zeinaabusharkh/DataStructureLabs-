#include <iostream>
using namespace std;

int digitPrint(int x)
{
if(x<10){ cout<< x <<endl; return 0;}

digitPrint(x/10);
cout<< x%10 <<endl;
}

int fact(int x)
{
    if(x == 0){return 1;}
    return x* fact(x-1);

}

int sum(int x)
{
    if( x== 0){ return 0;}
    return  x+sum(x-1);
}


 int binarySerch( int * a, int f , int l , int x)   
 {
     if(f > l) return -1;
     int mid = (f+l)/2;
     if( a[mid] == x) return mid;
     if(x> a[mid]){ return binarySerch( a, mid+1 , l , x);}
 }

 int fib(int x )
 {
    if( x <=1){ return x;}
    return fib(x-1)+fib(x-2);
 }




bool isPrime(int n , int i=2 )
{

    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
 
    return isPrime(n, i + 1);

}
void IntegerPalindrome(int n ){

   if (n < 9)
  {
    cout << n << " ";
    IntegerPalindrome(n + 1);
    cout << n << " ";
  }
  if(n==9){cout<<"9 " ;}
}

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
   
    // int arr[10];
    // for(int i= 0; i< 10 ; i++)
    // {
    //     arr[i]=i+9;
    //     cout<< arr[i]<<endl;

    // }

    //cout<<"------------print digits------------"<<endl;
    //digitPrint(78409);

    //cout<<"------------binary search------------"<<endl;
    //cout<< " the binary serch of the value is " << binarySerch(arr , 0 , sizeof(arr) , 6);

    //cout<<"------------fibonacci------------"<<endl;
    //cout<< fib(9)<<endl;

    //cout<<"------------factorial------------"<<endl;
    //cout<< "factorial : " << fact(4)<<endl;

    // cout<<"------------Sum------------"<<endl;
    // cout<< sum(4)<<endl;

    // cout<<"------------isPrime------------"<<endl;
    // cout<< "is number 23 prime ?" ;
    // cout<<isPrime(23)<<endl;

    // cout<<"------------Palindrom------------"<<endl;
    // IntegerPalindrome(5);


    // cout<<"------------------Checksum--------------------------"<<endl;
    // string line = "S12310242038100221C01014303810143040207CFFFFFFFC41FB80DA41F8100110E01010B8";
    // cout<<"Input Line? "+line <<endl;
    // cout<<"Checksum value? "+ checkSum(line)<<endl;  
    // if(checkSum(line) ==255){ cout<<" correct "<<endl;}else{ cout<<"erroneous"<<endl;}

    return 0;
}
