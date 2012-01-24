// Kevin Mangan
// Data Structures
// Basic Linked List Lab Part A
// Header file: Node.h

#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;


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

		void setPrevPtr(Node *nPtr){
                        prevPtr = nPtr;
                }


		void setData(string first, string last, string mid, int soc, int agee){

			fname = first;
                	lname = last;
                	mi = mid;
                	SSN = soc;
                	age = agee;	

			}

                string fname;
                string lname;
                string mi;
                int SSN;
                int age;

        private:
                Node *nextPtr;
		Node *prevPtr;
};

#endif


