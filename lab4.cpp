#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>

using namespace std;

typedef uint32_t u32;
typedef uint64_t u64;

struct record {
	u32 id; // automic id (like a primary key)
	string name;
	u64 tel;
	void print() {
		cout << id << ": " << name << ",  " << tel << endl;
	}
    record(){}
};

class Directory {
private:
	u32 autoID;
	list<record> lst;
	list<record>::iterator current;

public:
	Directory() { autoID = 0; current = lst.end(); }

	void insert()
    {
        record* contact= new record();
        cout<< "Enter a usename: ";
        cin>>contact->name;
        cout<< "Enter a telephone number: ";
        cin>> contact->tel;
        contact->id= autoID;
        autoID++;
        lst.push_back(*contact);

    } // Prompt for Name and Telephone Number and insert a new record in order of Name.

	void remove(){
        int k;
        print();
        cout<<"Enter contact index to be deleted : ";
        cin>>k;
        for (auto v : lst)
        { 
        current++;
        if(v.id == k)
        {
            lst.erase(current);
        }
        }
        
    } // remove the current record

	void edit(){
    print();
    int k;
    cout<< "Enter the index of the contact you would like to edit : ";
    cin>>k;
    for (auto v : lst)
        { 
        if(v.id == k)
        {
            cout<<"Edit Contact name:";
            cin>>v.name;
            cout<<"Edit telephone number: ";
            cin>>v.tel;
            v.print();
        }

        }

    } // edit the current record

	void go(){} //change the current record based on its ID. 

	void display(){} // prints the current record

	void search(){} // dispalys all record with a matching substring in name


	void print()
    {
        cout<<"------------printing all elements----------"<<endl;
        for (auto v : lst)
               { v.print();  }

    } // print all the records; 
};



void hit() {
	cout << "-----------Hit Any Key To Continue----------\n";
	char c ;
    cin>> c;
    system("clear");

}


char menu() {
	char c;
	string validChars = "irespgxd";
	int index;
	do {
		system("clear");
		cout << "Insert New Record (I): " << endl;
		cout << "Print All Records (P): " << endl;
		cout << "Remove Current Record (R) " << endl;
		cout << "Edit Current Record (E): " << endl;
		cout << "Search for Records: (S): " << endl;
		cout << "Go to Record (G): " << endl;
		cout << "Display Current Record (d): " << endl;
		cout << "Exit Program (x): " << endl;
        cin>>c ;
		c = tolower(c);
		index = validChars.find_first_of(string(1, c));
	} while (index == string::npos);
	return c;

};

int main() {
	Directory dir;
	char c = menu();
	while (c != 'x') {
		switch (c) {
		case 'i': dir.insert(); hit(); break;
		case 'p': dir.print(); hit(); break;
		case 'r': dir.remove(); hit(); break;
		case 'e': dir.edit(); hit(); break;
		case 's': dir.search(); hit(); break;
		case 'g': dir.go(); hit(); break;
		case 'd': dir.display(); hit(); break;
		}
		c = menu();
	}
}