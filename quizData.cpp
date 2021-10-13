#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int recursive (int n, int a)
{
    if(n==0) return a;
    if( n%2) a+= 1;
    return recursive(n/2 , a);

}

class linkedList{
    struct node{
        int key;
        node* next;
        node(int k , node* n) {key = k; next = n;}
    };
    node *root;
    public :
    linkedList()
    {
        root = new node(0,NULL);
        root->next= root;
    }
    void insert(int k)
    {
        node* temp = new node(k, root->next);
        root->next= temp;
    }
    void print()
    {
        node* temp = root;
        do
        {
            cout<< temp->next->key<<endl;
           temp =  temp->next->next;            
        } while (temp != root);
        
    }
};
void linkedlistoperation()
{
    linkedList l;
    for(int i=1 ; i<=6 ;i++){l.insert(i);}
    l.print();

}

void stakandqueue()
{
    stack<char> s;
    queue<char> q;
    for(char c= 'A'; c<='F' ;c++) s.push(c);
    for(int i =0 ; i< 10 ;i+=3)
    {
        q.push(char(65+i));
        s.push(q.front());
        s.pop();
        s.pop();
        q.pop();
        q.push(s.top());

    }
    while(!s.empty()){ cout<< s.top(); s.pop();}
    while(!q.empty()){ cout<< q.front(); q.pop();}
    
}


int main()
{
cout<<recursive(2051,0);
cout<<"==================================="<<endl;
linkedlistoperation();
cout<<"==================================="<<endl;
stakandqueue();
cout<<"==================================="<<endl;


    return 0;
}