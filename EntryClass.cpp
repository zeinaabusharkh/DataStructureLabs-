#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

string convertToLower(string x)
{
    int i=0;
    while(i < x.length())
  	{
          	x[i] = tolower(x[i]);
		
		i++;
  	}
      return x;
}

class Entry
{
    private:
    string fName, lName;
    int phone;
    public:
    Entry(string f="none" , string l="none" , int p=00000000)
    {
        fName=f;
        lName=l;
        phone=p;
    }
    friend ostream& operator<<(ostream&outs , const Entry& e)
    {
            outs<<"First Name: "<< e.fName <<"  Last Name: "<< e.lName << "  Phone Number= "<<e.phone<<endl;
            return outs;

    }

    bool operator==(const string& temp) 
    {
    
        string fName= convertToLower(this->fName);
        string lName = convertToLower(this->lName);
        string temp1 = convertToLower(temp);
        return (fName==temp1 || lName==temp1);
      
    }

    string getfName(){return fName;}
    string getLName(){return lName;}
    int getPhone(){return phone;}
};





template <class container>
void print(ostream& os, container& cont)
{
   
    for(auto it = cont.begin();it!= cont.end();it++)
    {
        os<<*it<<endl;

    }

}

ostream& operator<<(ostream& os,  vector<Entry>& dir)
{

print(os,dir);
return os;

}

template <class itType, class keyType>
bool find(itType first, itType last, keyType name, itType& foundEntry)
{
        for(auto x=first;x!=last;x++)
        {
            
            if(*x==name)
            {
                foundEntry=x;
                return true;
            }
        }
        return false;

}


template <class container,class keyType>
 void Search(container dir, keyType s)
 {
     auto it= dir.begin();
     bool f=find(dir.begin(),dir.end(),s,it);
     if(f)
     {
         cout<< *it;
     }
      else{
                    cout<<"Conatact not found!!"<<endl;
                }
    
 }


    template <class container,class keyType>
    void edit(container& dir, keyType s)
        {
                auto it= dir.begin();
                bool f=find(dir.begin(),dir.end(),s,it);
                if(f){
                cout<<"do u want to edit " << s <<"contact values ? (Y/N)";
                char input;
                cin>>input;
                if(input=='Y'||input=='y')
                {
                    string first, last;
                    int phone; 
                    cout<<"Enter first name : ";
                    cin>>first;
                    cout<<"Enter last name : ";
                    cin>>last;
                    cout<<"Enter phone: ";
                    cin>>phone;
                    Entry temp(first, last , phone);
                    *it=temp;
                    cout<< *it;
                }
                    cout<<"***********Printing************"<<endl;
                    cout<<dir;
                    cout<<"***********Done Printing************"<<endl;
                }
                else{
                    cout<<"Conatact not found!!"<<endl;
                }

        };


template <class container,class keyType>
void eraseEntry(container& dir, keyType s)
{
                auto it= dir.begin();
                bool f=find(dir.begin(),dir.end(),s,it);
                if(f)
                {
                    cout<<"do u want to erase " << s <<"contact values ? (Y/N)";
                    char input;
                    cin>>input;
                    if(input=='Y'||input=='y')
                    {
                       dir.erase(it);
                    }
                    cout<<"***********Printing************"<<endl;
                    cout<<dir;
                    cout<<"***********Done Printing************"<<endl;

                }
                 else{
                    cout<<"Conatact not found!!"<<endl;
                }
                


};
  


int main()
{
    vector<Entry> dir;
    ifstream in("input.txt");
    if (in.fail())
    {
        cout<<"Cannot open file !!"<<endl;
        exit(1);

    }
    string fname,lname;
    int phone;
    while(in>>fname>>lname>>phone)
    {
        Entry x(fname,lname,phone);
        dir.push_back(x);

        
    }
    in.close();
    cout<<"****************Printing************"<<endl;
    cout<<dir;
    cout<<"***********Done Printing************"<<endl;
    auto it= dir.begin();
    cout<<"Enter a name to find : ";
    string input;
    cin>>input;
    Search(dir, input);

    edit(dir,input);

    cout<<"Enter a name to find : ";
    cin>>input;
    eraseEntry(dir,input);
  
    


    return 0;
}