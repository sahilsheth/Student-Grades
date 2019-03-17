#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() {
	// TO BE COMPLETED
  cwid1 = " ";
  moe = 0.0;
}

Student::Student(const string &cwid) {
	// TO BE COMPLETED
  cwid1 = cwid;
  moe = 0.0;
}


string Student::getCWID() {
	// TO BE COMPLETED
  return cwid1;
}

void Student::addCourseGrade (const string &courseName, char grade) {
	// TO BE COMPLETED
 
  for(int i=0; i<50; i++)
  {
     if (courses[i]=="")
     {
        courses[i]=courseName;
        letters[i]=grade;
        moe++;
        break;
     }

  }
}

double Student::getGPA() {
	// TO BE COMPLETED
 
  double total = 0.0;
  double ban= 0.0;
  for(int i=0; i< moe; i++)
  {
    if(letters[i]=='A')
    {
      ban = 4.0;
    }
    else if(letters[i]== 'B')
    {
      ban = 3.0;
    }
    else if(letters[i] == 'C')
    {
      ban = 2.0;
    }
    else if(letters[i] == 'D')
    {
      ban = 1.0;
    }
    else
    {
      ban = 0.0;
    }
    total += ban;
  }
 gpa = total/moe;
 return gpa;
}

// print transcript in this (sample) format:
// TRANSCRIPT FOR CWID=279750343
// CS 121		C
// CS 253		B
// CS 131		B
// GPA = 2.6667
void Student::printTranscript() {
	// TO BE COMPLETED
  //loop to print
  cout << "Transcript for cwid: " << cwid1 << endl;
  for(int i=0; i<moe; i++)
  {
    cout << courses[i]<< " " << letters[i] << endl;
  }
       //<< addCourseGrade() << endl
  cout<< gpa <<endl;
}
