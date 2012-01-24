// Kevin Mangan
// Linked List II
// source.cpp Implementation
// Data Structures CISC 2200

#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
#include <exception>
#include <stdlib.h>
#include <fstream>

using namespace std;

// Copy Constructor

List::List(const List& aList){
	

	if(aList.head == NULL)
		head = NULL;
	else{
		Node* cptr = aList.head;
		head = NULL;
		while(cptr) {

    			// create a new node that is an exact copy of the current node of the orig list
			Node *nPtr = new Node;
		
			nPtr->setData(cptr->lname, cptr->fname, cptr->mi, cptr->SSN, cptr->age);
	
    			// append new node to new list
    			append(nPtr);

    			// move to the next node
    			cptr = cptr->getNextPtr();

		
		}

		
	}
}


// Destructor
List::~List(){
	Node *curr = head;
	while(head){
		curr = head;
		head = head -> getNextPtr();
		delete curr;
	}
	
	head = NULL;
}

// SORTING ALGORITHMS

void List::bubblesort(){

	int i,j,m,n= 0;
	int tempint;
	string tempstring;
  	Node *q, *p, *t;
  
	for(q = head ; q ; q = q->getNextPtr()) // Determine number of nodes
    		++n;
 
  	for(i=1 ,t = head; i <= n-1 ;t = t->getNextPtr() ,++i)
    		for( j=0 ,p = head; j < n-i ;p = p -> getNextPtr() ,++j)
       			if(p->age > (p->getNextPtr())->age)
       			{
	 			tempstring = p->fname;
         			p->fname = (p->getNextPtr())->fname;
         			(p->getNextPtr())->fname = tempstring;

				tempstring = p->lname;
                                p->lname = (p->getNextPtr())->lname;
                                (p->getNextPtr())->lname = tempstring;

				tempstring = p->mi;
                                p->mi = (p->getNextPtr())->mi;
                                (p->getNextPtr())->mi = tempstring;

				tempint = p->SSN;
                                p->SSN = (p->getNextPtr())->SSN;
                                (p->getNextPtr())->SSN = tempint;

				tempint = p->age;
                                p->age = (p->getNextPtr())->age;
                                (p->getNextPtr())->age = tempint;

      			}
}


void List::selectionsort(){

	Node *i, *j;
	int tempint;
        string tempstring;
	Node* curr = head;
	
	while(curr->getNextPtr())
		curr = curr->getNextPtr();

	tail = curr;

	for(i = tail; i != NULL; i = i->getPrevPtr()){
	   for(j = i->getPrevPtr(); j != NULL; j = j->getPrevPtr()){
	       if(i->age > j->age){

		  tempstring =  i->fname;
		  i->fname = j->fname;
		  j->fname = tempstring;

		  tempstring =  i->lname;
                  i->lname = j->lname;
                  j->lname = tempstring;

		  tempstring =  i->mi;
                  i->mi = j->mi;
                  j->mi = tempstring;

		  tempint =  i->SSN;
                  i->SSN = j->SSN;
                  j->SSN = tempint;

		  tempint =  i->age;
                  i->age = j->age;
                  j->age = tempint;

	       }
	   }
	}

}







// Input the head, and the new node that you want to append to the end of the list
void List::append(Node *nPtr){

	Node* curr = head;
	
	if(head){	
		while(curr -> getNextPtr()){
			curr = curr -> getNextPtr();
		}
		curr -> setNextPtr(nPtr);
		nPtr -> setPrevPtr(curr);
		nPtr -> setNextPtr(NULL);
	
	}
	else{				// If first node does not yet exist, head is NULL
		curr = nPtr;
		curr -> setNextPtr(NULL);
		head = curr;
	}

}

// isEmpty function
bool List::isEmpty(){
	bool retStat = false;
	if(!head)
		retStat = true;
	return(retStat);
}

// Gets the number of nodes
int List::getLength(){
	
	int nNodes = 0;
	Node *curr = head;
	while(curr){
		nNodes++;
		curr = curr->getNextPtr();
	}
	
	return(nNodes);
}

// Inserts data from a file and uses append
void List::insertFile(){

	Node* nPtr;
	string firstname, lastname, mid;
	int soc, agee;
	string line;
	int counter = 0;
  	ifstream inputFile("inputFile.txt");

	while (!inputFile.eof()) {
		getline (inputFile, line);
		if (counter == 0){
        		nPtr = new Node;
			firstname = line;
		}
		if (counter == 1)
			lastname = line;
		if (counter == 2)
                        mid = line;
		if (counter == 3)
                        soc = atoi(line.c_str());
		if (counter == 4) 
			agee = atoi(line.c_str());

		if ((counter == 0) || (counter == 1) || (counter == 2) || (counter == 3))
			counter++;
		else{	// When counter is 4, set the data and append the node, reset counter				
			nPtr->setData(firstname, lastname, mid, soc, agee);
                	append(nPtr);
			counter = 0;	
		}
	}
		

}





////////////////////////////////////////////////////////////////////////////

void List::insert(string first, string last, string mid, int soc, int agee){

	Node *nPtr = new Node;

	if (head == NULL){
		nPtr->setNextPtr(NULL);
		head = nPtr;

		nPtr->setData(first, last, mid, soc, agee);
	}	
 
    	Node *prev = head;
    	Node *curr = head->getNextPtr();
	bool done = false;
 
	if (head){
    		if (curr == NULL) {
        		if (prev->age < agee) {
            			prev->setNextPtr(nPtr);
            			nPtr->setNextPtr(NULL);
            		
				nPtr->setData(first, last, mid, soc, agee);

        		}
        		else {
            			nPtr->setNextPtr(prev);
				head = nPtr;
				curr = prev;
				prev = nPtr;
				curr->setNextPtr(NULL);

				nPtr->setData(first, last, mid, soc, agee);

        		}
    		}
	}		
 
    	
	while (curr != NULL && !done) {
        	
		if(prev->age > agee){
			nPtr->setNextPtr(prev);
			head = nPtr;
			curr = NULL;

			nPtr->setData(first, last, mid, soc, agee);
		}



		if (prev->age < agee && curr->age >= agee) {
            		prev->setNextPtr(nPtr);
            		nPtr->setNextPtr(curr);
			curr = nPtr;
            	
			nPtr->setData(first, last, mid, soc, agee);
			done = true;
        	}
        	else{
			prev = prev->getNextPtr();
			curr = curr->getNextPtr(); // Traverse
		}    
	}

	
 
}



// Display the whole linked list by printing each individual node
void List::displayAscending(){

	Node *curr = head;
	while(curr){
		printNode(curr);
		curr = curr -> getNextPtr();
	}
}

// Display the whole linked list by printing each individual node
void List::displayDescending(){

        Node *curr = tail;
        while(curr){
                printNode(curr);
                curr = curr -> getPrevPtr();
        }
}

// Prints individual node
void List::printNode(Node *curr){

		cout  << endl;
                cout  << curr->fname << endl;
                cout  << curr->mi << endl;
                cout  << curr->lname << endl;
                cout  << curr->SSN << endl;
                cout  << curr->age << endl;
		cout  << endl;
}


// Delete node with a certain first name
// This is the only part that is not working correctly - when I trace it, it seems okay...
Node* List::remove(Node *head, string fname){

	Node *curr = head;
	Node *prev = NULL;
	while(curr){
		if(curr->fname == fname){
			if(!prev){
				head = curr->getNextPtr();
			}else{
				prev->setNextPtr(curr->getNextPtr());
			}
		}else{
			prev = curr;
			curr = curr -> getNextPtr();
		}
	}
	return(head);
}

