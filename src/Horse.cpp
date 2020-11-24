#include "Horse.h"
#include <string>

using namespace std;

Horse::Horse(string breed, string name, string colour, string earType, string height,
	 string tailColour) : Animal(name, breed, colour) {		
	// Initialize Horse Attributes
	this->earType	 = earType;
	this->height	 = height;
	this->tailColour = tailColour;
}

Horse::Horse(const Horse &obj) : Animal(obj) {
	// Copy over attributes
	this->earType 	= obj.earType;
	this->height 	= obj.height;
	this->tailColour= obj.tailColour;
}

Horse& Horse::operator=(const Horse &obj){
	Animal::operator=(obj);
	// Copy over attributes
	this->earType 	= obj.earType;
	this->height 	= obj.height;
	this->tailColour= obj.tailColour;
	return *this;
}

Horse::~Horse() {
	// Deallocate memory
}

string Horse::getEarType() {
	return earType;
}

string Horse::getHeight() {
	return height;
}

string Horse::getTailColour() {
	return tailColour;
}

Horse* Horse::getDad() {
	return dad;
}

Horse* Horse::getMum() {
	return mum;
}

void Horse::setDad(Horse * obj) { 
	dad = obj;
}

void Horse::setMum(Horse * obj) {
	mum = obj;
}
