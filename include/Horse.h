#include "Animal.h"
#include <string>

using namespace std;

class Horse: public Animal {
	private:
		// Horse attributes
		string earType;
		string height;
		string tailColour;
		Horse * dad;
		Horse * mum;
	public:
		// Constructor, Copy Constructor, Copy Assignment, and Destructor
		Horse(string breed, string name, string colour, string earType, string height,
		string tailColour);
		Horse(const Horse &obj);
		Horse& operator=(const Horse& obj);
		~Horse();

		// Horse getters and setters
		string getEarType();
		string getHeight();
		string getTailColour();
		Horse* getDad();
		Horse* getMum();

		void setDad(Horse * obj);
		void setMum(Horse * obj);
};
