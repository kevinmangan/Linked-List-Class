// Kevin Mangan
// Data Structures
// Basic Linked List Lab Part A
// Header file: nodeClass.h

#ifndef NODECLASS_H
#define NODECLASS_H
#include <string>
using namespace std;

class List{

        public:
                List();
		List(const List& alist);
		~List();

		bool isEmpty();
		int getLength();
		void append(Node*, Node*);
		void insert(string, string, char, int, int);
		void remove();
		void displayAscending(Node*);
		void displyDescending(Node*);
		void printNode(Node*);
	private:

		Node *head;
		Node *tail;

};


class Node{

	public:

		Node* getNextPtr(){
                        return(nextPtr);
                }

		Node* getPrevPtr(){
			return(prevPtr);
		}

                void setNextPtr(Node *nPtr){
                        nextPtr = nPtr;
                }

                string fname;
                string lname;
                char mi;
                int SSN;
                int age;

        private:
                Node *nextPtr;
		Node *prevPtr;
};

#endif

