#include "Animal.h"
#include <string>

using namespace std;

Animal::Animal(string breed, string name, string colour) {		
	// Initialize Animal Attributes
	this->breed	 = breed;
	this->name	 = name;
	this->colour	 = colour;
}

Animal::Animal(const Animal &obj) {
	// Copy over attributes
	this->breed 	= obj.breed;
	this->name 	= obj.name;
	this->colour	= obj.colour;
	this->dad 	= obj.dad;
	this->mum 	= obj.mum;
}

Animal& Animal::operator=(const Animal &obj) {
	// Copy over attributes
	this->breed 	= obj.breed;
	this->name 	= obj.name;
	this->colour	= obj.colour;
	this->dad 	= obj.dad;
	this->mum 	= obj.mum;
	return *this;
}

Animal::~Animal() {
	// Deallocate memory
}

string Animal::getBreed() {
	return breed;
}

string Animal::getName() {
	return name;
}

string Animal::getColour() {
	return colour;
}

Animal* Animal::getDad() {
	return dad; 
}

Animal* Animal::getMum() {
	return mum;
}

void Animal::setDad(Animal * obj) {
	dad = obj;
}

void Animal::setMum(Animal * obj) {
	mum = obj;
}

