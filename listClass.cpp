// Kevin Mangan
// Linked List II
// listClass.cpp Implementation
// Data Structures CISC 2200

#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
#include <exception>
#include <stdlib.h>

using namespace std;
/*
// Copy Constructor
List::List(const List& alist){
	if(alist.head = NULL)
		head = NULL;
	else{
		// Copy first node
		head = new Node;
		head->fname = aList.head->fname;
		head->lname = aList.head->lname;
		head->mi = aList.head->mi;
		head->SSN = aList.head->SSN;
		head->age = aList.head->age;

		// Copy rest of list
		Node *newPtr = head;
		for(Node *origPtr = aList.head->getNextPtr(); origPtr != NULL; origPtr = origPtr->getNextPtr()){
			newPtr = newPtr->getNextPtr();
			newPtr->fname = origPtr->fname;
			newPtr->lname = origPtr->lname;
			newPtr->mi = origPtr->mi;
			newPtr->SSN = origPtr->SSN;
			newPtr->age = origPtr->age;
		}

		newPtr->getNextPtr() = NULL;
	}
}
*/

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
	char tempchar;
	string tempstring;
  	node *q, *p, *t;
  
	for(node*q = head ; q ; q=q->next) // Determine number of nodes
    		++n;
 
  	for(i=1 , t = head  ; i<=n-1 ;  t = t->getNextPtr() , ++i)
    		for( j=0 , p = head  ; j<n-i ;  p = p->getNextPtr() , ++j)
       			if(p->age > (p->getNextPtr())->age)
       			{
	 			tempstring = p->fname;
         			p->fname = (p->getNextPtr())->fname;
         			(p->getNextPtr())->fname = tempstring;

				tempstring = p->lname;
                                p->lname = (p->getNextPtr())->lname;
                                (p->getNextPtr())->lname = tempstring;

				tempchar = p->mi;
                                p->mi = (p->getNextPtr())->mi;
                                (p->getNextPtr())->mi = tempchar;

				tempint = p->SSN;
                                p->SSN = (p->getNextPtr())->SSN;
                                (p->getNextPtr())->SSN = tempint;

				tempint = p->age;
                                p->age = (p->getNextPtr())->age;
                                (p->getNextPtr())->age = tempint;

      			}
}









// Input the head, and the new node that you want to append to the end of the list
void List::append(Node *head, Node *nPtr){

	Node *curr = head;
	while(curr -> getNextPtr()){
		curr = curr -> getNextPtr();
	}
	curr -> setNextPtr(nPtr);
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


void List::insertFile(){


	ifstream inFile("studentfile.txt");
	string first;
	string last;
	char mid;
	int soc;
	int agee;

	if (inFile >> first)
	{ // File not empty
		try
		{  	head = new Node;
		   	head->fname = first;
		   	head->lname = last;
		   	head->mi = mid;
		   	head->SSN = soc;
		   	head->age = agee;
		   	head->setNextPtr(NULL);
		   	tail = head;

			while(inFile >> first)
			{  
			tail->getNextPtr() = new Node;
		   	tail = tail->getNextPtr();
		   	tail->fname = first;
                   	tail->lname = last;
                   	tail->mi = mid;
                   	tail->SSN = soc;
                   	tail->age = agee;
		   	tail->setNextPtr(NULL);
			}
		}

		catch(bad_alloc e){
			throw ListException(
				"ListException: restore cannot allocate memory.");
			}
	}
	
	
	inFile.close();
		

}





////////////////////////////////////////////////////////////////////////////
/*
void List::insert(string first, string last, char mid, int soc, int agee){

	Node *nPtr;
	bool firstnode = false;

	if (head == NULL){
		nPtr->setNextPtr(NULL);
		head = nPtr;

		nPtr->setData(first, last, mid, soc, agee);

	 	firstnode = true;
	}	
 
    	Node *prev = head;
    	Node *curr = head->getNextPtr();
 
	if (!firstnode){
    		if (curr == NULL) {
        		if (prev->age < agee) {
            			prev->setNextPtr(nPtr);
            			nPtr->setNextPtr(NULL);
            		
				nPtr->fname = first; // Fill in Node
        			nPtr->lname = last;
        			nPtr->mi = mid;
        			nPtr->SSN = soc;
		        	nPtr->age = agee;

        		}
        		else {
            			nPtr->setNextPtr(prev);
				head = nPtr;

				nPtr->fname = first;  // Fill in Node
        			nPtr->lname = last;
        			nPtr->mi = mid;
        			nPtr->SSN = soc;
		        	nPtr->age = agee;

        		}
    		}
	}		
 
    	
	while (curr != NULL) {
        	if (prev->age < agee && curr->age >= agee) {
            	prev->setNextPtr(nPtr);
            	nPtr->setNextPtr(curr);
            	
		nPtr->fname = first; // Fill in Node
        	nPtr->lname = last;
        	nPtr->mi = mid;
        	nPtr->SSN = soc;
	        nPtr->age = agee;

        	}
        
		curr = curr->getNextPtr(); // Traverse
        	prev = prev->getNextPtr();
    	}
	
 
}
*/


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
	
