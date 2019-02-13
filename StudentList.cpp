#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <chrono>
#include <algorithm>
#include "Student.h"
#include "StudentList.h"

using namespace std;
//class Student;

StudentList::StudentList(string file) {
    ifstream nfile;
    nfile.open(file);
    
    if(!nfile.is_open()) exit(0);
    
    std::string word;
    nfile>>word;
    //    cout << word << endl;
	nfile.close();
    
    vector<std::string> names;
    
    stringstream ss(word);
    
    char tempw;
    std::string temp = "";
    while(ss >> tempw){
        temp += tempw;
        if(ss.peek()==','){
            names.push_back(temp);
            temp = "";
            ss.ignore();
        }
    }
    int i;
    //    for(i = 0;i<names.size();i++) cout << names.at(i) <<endl;
    
    vector<int> IDs;
    GenerateRandomIDs(IDs, (int)names.size());
    
    for(i = 0;i<names.size();i++){
        cout << IDs.at(i) << "\t\t" << names.at(i) << endl;
        studentV.push_back(Student(IDs.at(i), names.at(i)));
        studentL.push_back(Student(IDs.at(i), names.at(i)));
    }
}


double StudentList::sort_vector(){
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
    std::sort(studentV.begin(), studentV.end());
    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double,milli> time_span = std::chrono::duration_cast<std::chrono::duration<double,milli>>(t2-t1);
    
    return time_span.count();
}

double StudentList::sort_list(){
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
    studentL.sort();
    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double,milli> time_span = std::chrono::duration_cast<std::chrono::duration<double,milli>>(t2-t1);
    
    return time_span.count();
}

double StudentList::search_vector_by_id(int id){
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
	std::find_if(studentV.begin(), studentV.end(), [id](Student& a) { return id == a.getID(); });
    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double,milli> time_span = std::chrono::duration_cast<std::chrono::duration<double,milli>>(t2-t1);
    
    return time_span.count();
}

double StudentList::search_list_by_id(int id){
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    
	std::find_if(studentL.begin(), studentL.end(), [id](Student& a) { return id == a.getID(); });
    
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double,milli> time_span = std::chrono::duration_cast<std::chrono::duration<double,milli>>(t2-t1);
    
    return time_span.count();
}

ostream& operator<< (ostream& os,StudentList& list) {
	for(size_t i = 0; i < list.studentV.size(); i++){
    //for(std::vector<Student>::iterator i = list.studentV.begin(); i!= list.studentV.end();++i){
        cout << list.studentV.at(i).getID() << "\t\t" << list.studentV.at(i).getName() << endl;
    }
    return os;
}
