#include "Student.h"
#include <sstream>
#include <string>

// Default Constructor
Student::Student(int perm, 
		 std::string lastName, 
		 std::string firstAndMiddleNames) {
  
  this->perm = perm;
  this->lastName = lastName;
  this->firstAndMiddleNames = firstAndMiddleNames;

}


// Student Object Constructor
Student::Student (std::string csvString) {

  std::istringstream iss(csvString);

  // This version of getline takes an input string (istream), a string, 
  // and a delimiter character (in this case, comma).
  // We read from the stream until the delimiter is encountered 
  
  std::string permAsString;
  getline(iss, permAsString, ',');
  this->perm = std::stoi(permAsString); // stoi converts std::string to int

  getline(iss, this->lastName, ',');

  getline(iss, this->firstAndMiddleNames, '\n');
}

// Returns Perm Number
int Student::getPerm() const { 
  return perm;
}

// Returns Last Name
std::string Student::getLastName() const { 
  return std::string(lastName);
}

// Returns First Name and Middle Name
std::string Student::getFirstAndMiddleNames() const {
  return firstAndMiddleNames;
}

// Creates String Containing First, Middle, and Last Names
std::string Student::getFullName() const { 
  std::string fullName = getFirstAndMiddleNames() + " " + getLastName();
  return fullName;
}

// Converts Array Containing Name and Perm Number to Full String
std::string Student::toString() const { 
  // e.g. [12345,Smith,Malory Logan]
  std::ostringstream oss;
  
  oss << "[" 
      << this->getPerm() << ","
      << this->getLastName() << ","
      << this->getFirstAndMiddleNames() << "]";
  return oss.str();
} 
