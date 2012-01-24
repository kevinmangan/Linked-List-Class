// Kevin Mangan
// Data Structures
// Basic Linked List Lab Part A
// Header file: List.h

#ifndef LIST_H
#define LIST_H
#include <string>
#include "Node.h"
using namespace std;

class List{

        public:
                List(){
			head = NULL;
			tail = NULL;
		};
		
		List(const List&);
		~List();

		bool isEmpty();
		int getLength();
		void append(Node*);
		void insert(string, string, string, int, int);
		Node* remove(Node*, string);
		void displayAscending();
		void displayDescending();
		void printNode(Node*);
		void insertFile();
		void bubblesort();	
		void selectionsort();
	
	private:

		Node *head;
		Node *tail;

};

#endif


