#include "Cat.h"
#include <string>

using namespace std;

Cat::Cat(string breed, string name, string colour, string earType, string height,
	 string tailColour) : Animal(name, breed, colour) {		
	// Initialize Cat Attributes
	this->earType	 = earType;
	this->height	 = height;
	this->tailColour = tailColour;
}

Cat::Cat(const Cat &obj) : Animal(obj) {
	// Copy over attributes
	this->earType 	= obj.earType;
	this->height 	= obj.height;
	this->tailColour= obj.tailColour;
}

Cat& Cat::operator=(const Cat &obj){
	Animal::operator=(obj);
	// Copy over attributes
	this->earType 	= obj.earType;
	this->height 	= obj.height;
	this->tailColour= obj.tailColour;
	return *this;
}

Cat::~Cat() {
	// Deallocate memory
}

string Cat::getEarType() {
	return earType;
}

string Cat::getHeight() {
	return height;
}

string Cat::getTailColour() {
	return tailColour;
}

Cat* Cat::getDad() {
	return dad;
}

Cat* Cat::getMum() {
	return mum;
}

void Cat::setDad(Cat * obj) { 
	dad = obj;
}

void Cat::setMum(Cat * obj) {
	mum = obj;
}
