#include "Dog.h"
#include <string>

using namespace std;

Dog::Dog(string breed, string name, string colour, string earType, string height,
	 string tailColour) : Animal(name, breed, colour) {		
	// Initialize Dog Attributes
	this->earType	 = earType;
	this->height	 = height;
	this->tailColour = tailColour;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
	// Copy over attributes
	this->earType 	= obj.earType;
	this->height 	= obj.height;
	this->tailColour= obj.tailColour;
}

Dog& Dog::operator=(const Dog &obj){
	Animal::operator=(obj);
	// Copy over attributes
	this->earType 	= obj.earType;
	this->height 	= obj.height;
	this->tailColour= obj.tailColour;
	return *this;
}

Dog::~Dog() {
	// Deallocate memory
}

string Dog::getEarType() {
	return earType;
}

string Dog::getHeight() {
	return height;
}

string Dog::getTailColour() {
	return tailColour;
}

Dog* Dog::getDad() {
	return dad;
}

Dog* Dog::getMum() {
	return mum;
}

void Dog::setDad(Dog * obj) { 
	dad = obj;
}

void Dog::setMum(Dog * obj) {
	mum = obj;
}
