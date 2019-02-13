#include <iostream>
#include "StudentList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    StudentList student_list("names.csv");
    
    cout << student_list << endl;
    
    double duration_of_vector_sort = student_list.sort_vector();
    double duration_of_list_sort = student_list.sort_list();
    
    cout << student_list << endl;
    
    cout << "The vector sort took " << duration_of_vector_sort << " seconds.\n";
    cout << "The list sort took " << duration_of_list_sort << " seconds.\n";
    
    cout << "Press any key to continue ... ";
    char c;
    cin.get(c);
    
    double duration_of_vector_search = student_list.search_vector_by_id(750);
    double duration_of_list_search = student_list.search_list_by_id(750);
    
    cout << "The vector search took " << duration_of_vector_search << " seconds.\n";
    cout << "The list search took " << duration_of_list_search << " seconds.\n";
    
    cout << "Press any key to exit ... ";
    cin.get(c);
    return 0;
}

//Vector is faster at finding elements because of the usage of cache line. Since vector has elements contiguously arranged, when one element is accessed, the next element is already be set in the cache.
//But the processor use much more time on waiting for the data in the list.
//List is faster to sort the elements. Since the list don't perform any copy and only change the pointers to the elements. But vectors will do a lot of copies during swapping.

//The program can be run on the mac but not on the Windows. I couldn't solve it since the code in two systems are the same.