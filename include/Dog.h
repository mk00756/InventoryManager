#include "Animal.h"
#include <string>

using namespace std;

class Dog: public Animal {
	private:
		// Dog attributes
		string earType;
		string height;
		string tailColour;
		Dog * dad;
		Dog * mum;
	public:
		// Constructor, Copy Constructor, Copy Assignment, and Destructor
		Dog(string breed, string name, string colour, string earType, string height,
		string tailColour);
		Dog(const Dog &obj);
		Dog& operator=(const Dog& obj);
		~Dog();

		// Dog getters and setters
		string getEarType();
		string getHeight();
		string getTailColour();
		Dog* getDad();
		Dog* getMum();

		void setDad(Dog * obj);
		void setMum(Dog * obj);
};
