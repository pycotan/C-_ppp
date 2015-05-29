/*
 ch11_exercise15
 
 Write a program to read a file of whitespace-sparated numbers and output them to in order (lowest value first), one value per line. Write a value only once, and if it occurs more than once write the count of its occurence on its line. For example, "7 5 5 7 3 117 5" should give
 3
 5 3
 7 2
 117
 */

#include "std_lib_facilities.h"
#include <fstream>
#include <vector>


int main()
{
    string name = "ch11_e15_data1.txt";
    ifstream ifs(name.c_str());
    int n;
    ifs >> n;
    vector<int> numbers;
    
    while(ifs.good()){
        numbers.push_back(n);
        ifs >> n;
    }
    
    
    sort(numbers.begin(), numbers.end());
    
    vector<int> kind;   //store if new val
    vector<int> range;  //store same val
    vector<int> range_size; //store size of all range
    
    for(int i=0; i<numbers.size(); ++i){
        if(i==0){
            kind.push_back(numbers[i]);
            range.push_back(numbers[i]);
        }
        else{
            if(kind.back()!=numbers[i]){
                kind.push_back(numbers[i]);
                range_size.push_back(range.size());
                range.clear();
                range.push_back(numbers[i]);
            }
            else{
                range.push_back(numbers[i]);
            }
        }
    }
    if(kind.size()!=range_size.size()) // if there are many value in the last range, we need this check.
        range_size.push_back(range.size());
    
    ofstream ofs;
    ofs.open("ch11_e15_data2.txt", ofstream::out);
    
    for(int i=0; i<kind.size(); ++i){
        ofs << kind[i] << "\t";
        if(range_size[i]!=1)
            ofs << range_size[i];
        ofs << "\n";
    }
    
    return 0;
}
