#include "Animal.h"
#include <string>

using namespace std;

class Cat: public Animal {
	private:
		// Cat attributes
		string earType;
		string height;
		string tailColour;
		Cat * dad;
		Cat * mum;
	public:
		// Constructor, Copy Constructor, Copy Assignment, and Destructor
		Cat(string breed, string name, string colour, string earType, string height,
		string tailColour);
		Cat(const Cat &obj);
		Cat& operator=(const Cat& obj);
		~Cat();

		// Cat getters and setters
		string getEarType();
		string getHeight();
		string getTailColour();
		Cat* getDad();
		Cat* getMum();

		void setDad(Cat * obj);
		void setMum(Cat * obj);
};
