// Kevin Mangan
// Driver program for List Class
#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
using namespace std;


int main(){

	string lname, fname;
	int SSN, age;
	char mi, exit;
	Node *nPtr = NULL;
	Node *head = NULL; //create the head of the list
	Node *tail = NULL;

	List nList;

	while(exit != 'y'){
		cout << "\n\tPlease enter Last Name: ";
		cin >> lname;
			if(lname != "-"){
				cout << "\n\tEnter First Name: ";
				cin >> fname;
				cout << "\n\tEnter Middle Initial: ";
				cin >> mi;
				cout << "\n\tEnter SSN: ";
				cin >> SSN;
				cout << "\n\tEnter Age: ";
				cin >> age;
			}
		nList.insert(lname, fname, mi, SSN, age);
		
		cout << "\n\tExit? (y/n)";
		cin >> exit;
	}

	nList.displayDescending();


	
}		
