#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
using namespace std;

int main() {

  // Formatted output: fixed width with left alignment
  cout << "Breed   |Name    |Colour  |Ear Type|Height  |Tail Col|Dad     |Mom     |" << endl;
  cout << "--------|--------|--------|--------|--------|--------|--------|--------|" << endl;
  cout << left;

  // Create Storage for inputted Animals
  vector<Dog> dogVector;
  vector<Cat> catVector;
  vector<Horse> horseVector;

  // Code to read in a file by line
  // Read Dogs.csv
  ifstream infile1("Dogs.csv"); // Read file using fstream
  cout << "--------|--------|--------|------Dogs-------|--------|--------|--------|" << endl;

  if (infile1.is_open()) { // Test if the file is accessible
    string line;

    while (getline(infile1, line)) { // Read a line until EOF
      // Code to split a string by a delimiter
      stringstream ss(line);
      string item;
      // Create storage for the new Dog entry's attributes
      vector<string> attributes;

      while (getline(ss, item, ',')) {
	// print the items as a tuple
	cout << setw(8) << item << "|";
	// add the attribute to the new Dog's vector
	attributes.push_back (item);
	// make sure the line ends correctly
	if (item.empty()) {
	  cout << setw(8) << " " << "|";
	}
      }
      // Make a new Dog from the tuple attributes and add it to the Dogs Vector
      Dog newDog(attributes[1],attributes[0],attributes[2],attributes[3],attributes[4],attributes[5]);
      dogVector.push_back(newDog);

      // Link the animal to their parents
      for (int i = 0; (unsigned)i < dogVector.size(); i++) {
        if (attributes[6] == dogVector[i].getName()) {
	  dogVector[dogVector.size() - 1].setDad(&dogVector[i]);
        }
	if (attributes[7] == dogVector[i].getName()) {
	  dogVector[dogVector.size() - 1].setMum(&dogVector[i]);
        }
      }
      // end the tuple
      cout << endl;
    }
  }
  // Handle file reading error
  else {
    cout << "Error reading file!" << endl;
  }
  infile1.close();
  infile1.clear();

  // Code to read Cats.csv
  cout << "--------|--------|--------|------Cats-------|--------|--------|--------|" << endl;
  ifstream infile2("Cats.csv"); // Read file using fstream

  if (infile2.is_open()) { // Test if the file is accessible
    string line;

    while (getline(infile2, line)) { // Read a line until EOF
      // Code to split a string by a delimiter
      stringstream ss(line);
      string item;
      // Create storage for the new Cat entry's attributes
      vector<string> attributes;

      while (getline(ss, item, ',')) {
	// print the items as a tuple
	cout << setw(8) << item << "|";
	// add the attribute to the new Cat's vector
	attributes.push_back (item);
	// make sure the line ends correctly
	if (item.empty()) {
	  cout << setw(8) << " " << "|";
	}
      }
      // Make a new Cat from the tuple attributes and add it to the Cats Vector
      Cat newCat(attributes[1],attributes[0],attributes[2],attributes[3],attributes[4],attributes[5]);
      catVector.push_back(newCat);
      // Link the animal to their parents
      for (int i = 0; (unsigned)i < catVector.size(); i++) {
        if (attributes[6] == catVector[i].getName()) {
	  catVector[catVector.size() - 1].setDad(&catVector[i]);
        }
	if (attributes[7] == catVector[i].getName()) {
	  catVector[catVector.size() - 1].setMum(&catVector[i]);
        }
      }
      // end the tuple
      cout << endl;
    }
  }
  // Handle file reading error
  else {
    cout << "Error reading file!" << endl;
  }
  infile2.close();
  infile2.clear();

  // Code to Read Horses.csv
  cout << "--------|--------|--------|-----Horses------|--------|--------|--------|" << endl;
  ifstream infile3("Horses.csv"); // Read file using fstream

  if (infile3.is_open()) { // Test if the file is accessible
    string line;

    while (getline(infile3, line)) { // Read a line until EOF
      // Code to split a string by a delimiter
      stringstream ss(line);
      string item;
      // Create storage for the new Horse entry's attributes
      vector<string> attributes;

      while (getline(ss, item, ',')) {
	// print the items as a tuple
	cout << setw(8) << item << "|";
	// add the attribute to the new Horse's vector
	attributes.push_back (item);
	// make sure the line ends correctly
	if (item.empty()) {
	  cout << setw(8) << " " << "|";
	}
      }
      // Make a new Horse from the tuple attributes and add it to the Horses Vector
      Horse newHorse(attributes[1],attributes[0],attributes[2],attributes[3],attributes[4],attributes[5]);
      horseVector.push_back(newHorse);

      // Link the animal to their parents
      for (int i = 0; (unsigned)i < horseVector.size(); i++) {
        if (attributes[6] == horseVector[i].getName()) {
	  horseVector[horseVector.size() - 1].setDad(&horseVector[i]);
        }
	if (attributes[7] == horseVector[i].getName()) {
	  horseVector[horseVector.size() - 1].setMum(&horseVector[i]);
        }
      }
      // end the tuple
      cout << endl;
    }
  }
  // Handle file reading error
  else {
    cout << "Error reading file!" << endl;
  }
  infile3.close();
  infile3.clear();

  // end the table
  cout << "--------|--------|--------|--------|--------|--------|--------|--------|" << endl;
  cout << endl;

  // Total amounts of animals
  cout << "There are " << dogVector.size() << " dog(s), " << catVector.size() << " cat(s) and " << horseVector.size() << " horse(s) in the inventory." << endl;
  
  // Set up an input loop
  bool repeat = true;
  do {
    // Ask for an animal name
    cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: (enter 'quit' if you would like to end the program)" << endl; 
  
    // Get user input as a string
    char input[50];
    cin.getline(input, sizeof(input));
    string query(input);

    if(query == "quit") {
      repeat = false;
      break;
    }

    // Create a flag for whether the animal exists
    bool exists = true;

    // Make sure the input is formatted correctly (char -> space -> name)
    if(query[1]!=' ') {
      cout << "your input wasn't formatted correctly, try again" << endl;
      continue;
    }

    // Check which animal group queried
    switch(query[0]) {
      // Check all animals
      case 'a' :
	// Create a flag for whether the animal exists
        for (int i = 0; (unsigned)i < dogVector.size(); i++) {
          if (query.substr(2) == dogVector[i].getName()) {
	    // Check dogs and output paternal tree if found then exit the program
	    // Make sure to check that a parent exists before printing tree
	    // Print the paternal tree
            cout << "Paternal tree of " << dogVector[i].getName() << ":" << endl;
            cout << dogVector[i].getName();
            Dog * dog = &dogVector[i];
            bool keepgoing = true;
            while (keepgoing) {
              if (dog->getDad()) {
                dog = dog->getDad();
                cout << " <-- " << dog->getName();
              }
              else {
                keepgoing = false;
                cout << " <-- " << "[END]" << endl;
              } 
            }
	    return 0;
          }
	  else {
	    // Not the entered name, set flag to false
	    exists = false;
	  }
        }
        for (int i = 0; (unsigned)i < catVector.size(); i++) {
          if (query.substr(2) == catVector[i].getName()) {
	    // Check cats and output paternal tree if found then exit the program
	    // Make sure to check that a parent exists before printing tree
	    // Print the paternal tree
            cout << "Paternal tree of " << catVector[i].getName() << ":" << endl;
            cout << catVector[i].getName();
            Cat * cat = &catVector[i];
            bool keepgoing = true;
            while (keepgoing) {
              if (cat->getDad()) {
                cat = cat->getDad();
                cout << " <-- " << cat->getName();
              }
              else {
                keepgoing = false;
                cout << " <-- " << "[END]" << endl;
              } 
            }
	    return 0;
          }
	  else {
	    // Not the entered name, set flag to false
	    exists = false;
	  }
        }
        for (int i = 0; (unsigned)i < horseVector.size(); i++) {
          if (query.substr(2) == horseVector[i].getName()) {
	    // Check horses and output paternal tree if found then exit the program
	    // Make sure to check that a parent exists before printing tree
	    // Print the paternal tree
            cout << "Paternal tree of " << horseVector[i].getName() << ":" << endl;
            cout << horseVector[i].getName();
            Horse * horse = &horseVector[i];
            bool keepgoing = true;
            while (keepgoing) {
              if (horse->getDad()) {
                horse = horse->getDad();
                cout << " <-- " << horse->getName();
              }
              else {
                keepgoing = false;
                cout << " <-- " << "[END]" << endl;
              } 
            }
	    return 0;
          }
	  else {
	    // Not the entered name, set flag to false
	    exists = false;
	  }
        }
	// Animal name entered doesn't exist
	if (!exists) {
	  cout << "Cannot find that animal in the database, try again" << endl;
	}
        break;
      // Check all dogs
      case 'd' :
        for (int i = 0; (unsigned)i < dogVector.size(); i++) {
          if (query.substr(2) == dogVector[i].getName()) {
	    // Check dogs and output paternal tree if found then exit the program
	    // Make sure to check that a parent exists before printing tree
	    // Print the paternal tree
            cout << "Paternal tree of " << dogVector[i].getName() << ":" << endl;
            cout << dogVector[i].getName();
            Dog * dog = &dogVector[i];
            bool keepgoing = true;
            while (keepgoing) {
              if (dog->getDad()) {
                dog = dog->getDad();
                cout << " <-- " << dog->getName();
              }
              else {
                keepgoing = false;
                cout << " <-- " << "[END]" << endl;
              } 
            }
	    return 0;
          }
	  else {
	    // Not the entered name, set flag to false
	    exists = false;
	  }
        }
	// Animal name entered doesn't exist
	if (!exists) {
	  cout << "Cannot find " << query.substr(2) << " in the database, try again" << endl;
	}
	break;
      // Check all cats
      case 'c' :
        for (int i = 0; (unsigned)i < catVector.size(); i++) {
          if (query.substr(2) == catVector[i].getName()) {
	    // Check cats and output paternal tree if found then exit the program
	    // Make sure to check that a parent exists before printing tree
            // Print the paternal tree
            cout << "Paternal tree of " << catVector[i].getName() << ":" << endl;
            cout << catVector[i].getName();
            Cat * cat = &catVector[i];
            bool keepgoing = true;
            while (keepgoing) {
              if (cat->getDad()) {
                cat = cat->getDad();
                cout << " <-- " << cat->getName();
              }
              else {
                keepgoing = false;
                cout << " <-- " << "[END]" << endl;
              } 
            }
	    return 0;
          }
	  else {
	    // Not the entered name, set flag to false
	    exists = false;
	  }
        }
	// Animal name entered doesn't exist
	if (!exists) {
	  cout << "Cannot find that animal in the database, try again" << endl;
	}
        break;
      // Check all Horses
      case 'h' :
        for (int i = 0; (unsigned)i < horseVector.size(); i++) {
          if (query.substr(2) == horseVector[i].getName()) {
	    // Check horses and output paternal tree if found then exit the program
	    // Make sure to check that a parent exists before printing tree
	    // Print the paternal tree
            cout << "Paternal tree of " << horseVector[i].getName() << ":" << endl;
            cout << horseVector[i].getName();
            Horse * horse = &horseVector[i];
            bool keepgoing = true;
            while (keepgoing) {
              if (horse->getDad()) {
                horse = horse->getDad();
                cout << " <-- " << horse->getName();
              }
              else {
                keepgoing = false;
                cout << " <-- " << "[END]" << endl;
              } 
            }
	    return 0;
          }
	  else {
	    // Not the entered name, set flag to false
	    exists = false;
	  }
        }
	// Animal name entered doesn't exist
	if (!exists) {
	  cout << "Cannot find that animal in the database, try again" << endl;
	}
        break;
      // Invalid Input
      default :
        cout << "The first letter of your animal group was wrong. Try again" << endl;
        break;
    }
  } while(repeat);

  return 0;
}
