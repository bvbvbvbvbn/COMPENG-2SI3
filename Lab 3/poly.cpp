#include "Poly.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

//big theta(1)
Poly::Poly() {
	//creates a 0 polynomial with degree equals -1 (deg, coeff, next)
	head = new PolyNode(-1, 0, NULL);
	size = 0;
}

//beg theta(n)
Poly::Poly(const std::vector<int> &deg, const std::vector<double> &coeff) {
	for (int j = deg.size(); j > 0; j--) {
		//creating new node that stores all degrees and coeffecients, and moves next
		PolyNode *newNode = new PolyNode(deg[j-1], coeff[j-1], head);
		head = newNode;
	}
	size = deg.size();
	PolyNode *s = head;
	head = new PolyNode(-1, 0, s);
}

//big theta(n)
Poly::~Poly() {
	//sets head as a temp to be freed, and sets the next to next position in the head to the next position
	PolyNode *temp;
	while (head->next) { //iterates while another node exists after head
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}

//big theta(n)
void Poly::addMono(int i, double c) {
	PolyNode *newNodeHead = head;
	PolyNode *newNode = head->next;
	if (c == 0) {
		newNodeHead->next = newNode->next;
		return;
	} //adding 0 = not possible
	//creating new node from start
	else if (getTermsNo() == 0) {
		head->next = new PolyNode(i, c, NULL);
		return;
	} else {
		while (newNode) {
			//degree is the same
			if (newNode->deg == i) {
				//adds to 0
				if (newNode->coeff + c == 0) {
					newNodeHead->next = newNode->next;
					size--;
					return;
				}
				//regular addition
				else {
					newNode->coeff += c;
					size++;
					return;
				}
			}
			//degree is larger
			else if (newNode->deg < i) {
				newNodeHead->next = new PolyNode(i, c, newNode);
				size++;
				return;
			}
			//degree is smaller
			else if ((newNode->next == NULL) && (newNode->deg > i)) {
				newNode->next = new PolyNode(i, c, NULL);
				size++;
				return;
			}
			//iterating through list
			newNodeHead = newNode;
			newNode = newNode->next;
		}
	}
}

//big theta(n)
void Poly::addPoly(const Poly &p) {
	PolyNode *newNode = p.head->next;
	while (newNode) {
		addMono(newNode->deg, newNode->coeff); //adds p to polynomial
		newNode = newNode->next; //interate through list
	}
}

//big theta(n)
void Poly::multiplyMono(int i, double c) {
	PolyNode *newNode = head->next;
	if (c == 0) {
		head->next = NULL;
	} //multiply by 0, not in list
	while (newNode) {
		newNode->coeff *= c; //multiply coefficients
		newNode->deg += i; //add degrees
		newNode = newNode->next; //iterate
	}
}

//big theta(n^3)
void Poly::multiplyPoly(const Poly& p)
{
    PolyNode *newNode = p.head->next;
    Poly tempMult = Poly();
    Poly tempAdd = Poly();

    while(newNode){
    	this->duplicate(tempMult); //duplicating the original
    	tempMult.multiplyMono(newNode->deg, newNode->coeff); //multiplying tempMult with p
    	tempAdd.addPoly(tempMult); //adding multiply to the duplicate of the original
		newNode = newNode->next; //iterating p
    }
    tempAdd.duplicate(*this); //duplicate of original
}


//big theta(n)
void Poly::duplicate(Poly& outputPoly)
{
	//empty
    if(head->next == NULL){
    	outputPoly.head->next = NULL; //copy over empty node
    }
    PolyNode *newNodeHead = outputPoly.head;
    PolyNode *newNode = head->next;
	while(newNode){
		newNodeHead->next = new PolyNode(newNode->deg, newNode->coeff, NULL);//copy over elements
		////iterate through both lists
		newNodeHead = newNodeHead->next;
    	newNode = newNode->next;
    }
}


//big theta(1)
int Poly::getDegree() {
	//empty
	if (head->next == NULL) {
		return -1;
	}
	int output = head->next->deg;
	return output;
}


//big theta(n)
int Poly::getTermsNo() {
	//empty
	if (head->next == NULL) {
		return 0;
	}
	int output = 0;
	PolyNode *newNode = head->next;
	while (newNode) {
		newNode = newNode->next;		//iterate
		output++;		//add to total
	}
	return output;
}


//big theta(n)
double Poly::evaluate(double x) {
	PolyNode *newNode = head->next;
	double output = 0;
	for (int i = 0; i < getTermsNo(); i++) { //iterate
		output += newNode->coeff * pow(x, newNode->deg); //c*x^i for every element in list
		newNode = newNode->next; //iterate
	}
	return output;
}


std::string Poly::toString() {
	return "";
//	string output = "";
//	PolyNode *newNode = head->next;
//	output = "degree = " + (newNode->deg) + "; ";
//	while (newNode) {
//		output += "a(" + (newNode->deg) + ") = " + (newNode->coeff) + "; ";
//		newNode = newNode->next;
//	}
//	return output;
}
