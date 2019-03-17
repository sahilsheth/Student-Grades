#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) {
	ifstream myfile(filename.c_str());

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			// cout << cwid << " " << grade << endl;
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

Registrar::Registrar()
{
	//arr= new Student[numOf]; // student= 50,000 people
	arr= new Student[50000];
	addItem=0;
}

Registrar::Registrar(Registrar &a)
{
	addItem=a.addItem;
	arr= new Student[50000];
	for(int i=0; i<addItem; i++)
	{
		arr[i]=a.arr[i];
	}
}


Registrar & Registrar::operator=(const Registrar & a)
{
	if(this != &a)
	{
		delete[] arr;
		addItem= a.addItem;
		arr= new Student[addItem];
		for(int i=0; i<addItem; i++)
		{
			arr[i]= a.arr[i];
		}

	}
	return *this;
}



// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid
Student& Registrar::getStudent(string cwid) const
{
	// TO BE COMPLETED
	int n;
	for(int n=0; n< 50000; n++)
	{
		if(arr[n].getCWID() == cwid)
		{
			return arr[n];
		}

	}
	throw invalid_argument("CWID is invalid"); //throw error if CWID is not found
	
}

// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) {
	// TO BE COMPLETED


	try {
		Student &s = getStudent(cwid);
		s.addCourseGrade(courseName, grade);
		
	}
	catch (exception &e)
	{
		arr[addItem] = Student(cwid);
		
		arr[addItem].addCourseGrade(courseName, grade);
		
		addItem++;
		

	}



}

