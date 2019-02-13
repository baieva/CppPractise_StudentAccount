#pragma once
#ifndef StudentList_h
#define StudentList_h

#include <vector>
#include <list>
#include <string>
#include <time.h>
#include "Student.h"

using namespace std;
//class Student;


class StudentList {
private:
    vector <Student> studentV;
    list<Student> studentL;
    
public: StudentList(string file);
    double sort_vector();
    double sort_list();
    double search_vector_by_id(int id);
    double search_list_by_id(int id);
    friend ostream& operator<< (ostream& os,StudentList& list);
    
    static void GenerateRandomIDs(vector<int>& ids,const int number_of_ids){
        srand((unsigned)time(NULL));
        int i,n;
        for(i = 0; i < number_of_ids;i++){
            n = rand() % number_of_ids;
            if(i == 0){
                ids.push_back(n);
            }
            else {
                if(std::find(ids.begin(),ids.end(),n) != ids.end()){
                    i--;
                }
                else{
                    ids.push_back(n);
                }
            }
        }
    }
};

#endif /* StudentList_h */
