#include <iostream>
using namespace std;
#include <random>
#include<fstream>

//Declare a struct Word as given below:
struct word {
    string wrd;
    int order;
   	word* next;

    word() : next(NULL) {}
    word(string wrd0, int order0) :
    wrd(wrd0), order(order0),next(NULL) {}
};


// Write a class text with the following data and function members:
class Linkedlist
{
    // 1.	Two data members: head and tail of type struct word.
private:
word* head;
word* tail;

    // 2.	A default constructor 
public:
Linkedlist()
{ head = new word(); //head = new word 
 tail = new word(); //tail = new word
 // a.	initialize head and tail. Make head next points to tail.
 head->next = tail; //set the head word to point to tail word
 tail->next = NULL; //set tail node to point to Nothing NULL 
}

// 3.	Insert function, void insert(string s, int ord=0)that inserts string s at the position order
//      in the list.
//     Don’t forget to update the order of rest of the following nodes after inserting. 
void insert(string s, int ord=0)
{
  word* temp = head;
 while (temp->next != tail && ord > temp->next->order)
 temp = temp->next;
 word* aux = new word(s , ord);
 aux->next = temp->next;
 temp->next = aux;
 
}


//4.	Overload ostream << operator that prints the words in the given format (order): word
 friend ostream& operator<<(ostream& os , Linkedlist& ll) {
 word* temp = ll.head->next;
 while (temp != ll.tail) {
 os << temp->order << "->  " << temp->wrd << endl;
 temp = temp->next;
 }
 os << endl << endl;
  return os;
 }


//--------------------------------------------------------------------------------------------------
// 1.	bool findWord(int ord, word& w): finds the word that’s present at order ord. 
//     If the word exist in the text then return true and save the word in reference variable.
bool findWord(int ord, word& w)
{ 
word* temp = head;
 while (temp->next != tail &&  temp->next->order != ord) 
 {
    temp = temp->next; 
    w=*temp;
    return true;
 }
 return false;
}


// 2.	bool erase(int ord): erases the word present at the order ord. Do not forget to update 
//     the oder of the words followed.
bool erase(int ord)
{
    word* temp = head;
    while (temp->next != tail &&  temp->next->order != ord) 
    {
        temp = temp->next; 
    }
    if(temp->next==tail)
    {
      return false;  
    }
     word* afterword = temp->next;
     temp->next =afterword->next;
     delete afterword;
     this->reOrder();
    // while(temp->next!= tail)
    // {
    //     temp->next->order --;
    //     temp=temp->next;
    // }
     return true;

}

// 3.	bool eraseAll(string w): erases all instances of the word w.
bool eraseAll(string w)
{
    bool returnType=false;
    word* temp = head;
    while (temp->next != tail ) 
    {
        if(temp->wrd == w)
        {
            this->erase(temp->order);
            returnType=true;
        }
      temp = temp->next;
       
    }
    return  returnType;
}


// to re-order the list 
void reOrder()
{
    word* temp = head;
      int orderWord=0;
        while(temp->next != tail)
        {
            temp = temp->next; 
            temp->order  = orderWord;
            orderWord++;
        }
}

};




int main() {
Linkedlist ll;
    ifstream in("input.txt");
    if (in.fail())
    {
        cout<<"Cannot open file !!"<<endl;
        exit(1);

    }
    string word;
    int orderWord=0;
    while(in>>word)
    {
       ll.insert(word, orderWord);
       orderWord++;
    }
    in.close();

cout<<"-------------------- Printing list -----------------------------"<<endl;
cout<<ll;
cout<<"-----------------------END Printing list -----------------------"<<endl;


cout<<"-------------------- Find Element ------------------------------"<<endl;
 struct::word foundWord;
 cout<< "Dose this order exists : " << endl;
 cout<< ll.findWord(3,foundWord );
 cout<< endl;
 cout<< "whats the word?"<<endl; 
 cout<< foundWord.wrd;
 cout<< endl;
cout<<"-------------------- END Find Element ------------------------------"<<endl;

cout<<"-------------------- Erase Element ------------------------------"<<endl;
cout<<"Did it erase? ";
cout<< ll.erase(30);
cout<<endl;
cout<<ll;

cout<<"-------------------- END Erase Element ------------------------------"<<endl;

cout<<"-------------------- Erase All Element instance ------------------------------"<<endl;
cout<< ll.eraseAll("been");
cout<<endl;
cout<<ll;
cout<<"-------------------- END Erase All Element instance ------------------------------"<<endl;
 return 0;

}