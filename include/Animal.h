#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

using namespace std;

class Animal {
	protected:
		// Animal Attributes
		string breed;
		string name;
		string colour;
		Animal * dad;
		Animal * mum;
		
	public:
		// Animal constructor, copy constructor, copy assignment, and destructor
		Animal(string breed, string name, string colour);
		Animal(const Animal &obj);
		Animal& operator=(const Animal& obj);
		~Animal();
		
		// Animal getters and setters
		virtual string getBreed();
		virtual string getName();
		virtual string getColour();
		virtual Animal* getDad();
		virtual Animal* getMum();
		virtual void setDad(Animal * obj);
		virtual void setMum(Animal * obj);
};
#endif /* ANIMAL_H */
