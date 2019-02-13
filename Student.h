#pragma once
#ifndef Student_h
#define Student_h

#include <string>
//#include "StudentList.h"

using namespace std;


class Student {
private:
    int ID;
    string Name;
    
public: 
	Student(int nId, std::string nName);
    
	bool operator<(const Student& s) const {
		return Name < s.Name;
	}
    
	string getName() {
		return Name;
	}
    
	int getID() {
		return ID;
	}
};

#endif /* Student_h */
