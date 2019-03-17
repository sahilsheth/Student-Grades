#pragma once
#include <string>

using namespace std;

class Student {
public:
	Student(); // default constructor
	Student(const string &cwid); // constructor with parameter
	void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
	double getGPA(); // calculate and return GPA
	void printTranscript(); // print transcript - see Student.cpp for the format
	string getCWID(); // return the CWID of this student
private:
	// any private member variables and methods go here
	// TO BE COMPLETED
	string courses[50];
	char letters[50];
	string cwid1;
	double gpa;
	double moe;

};

