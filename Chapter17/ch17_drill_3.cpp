//ch17 drill3 ポインタと配列など


#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n){
    for (int i=0; i<n; ++i)
        os << a[i] << endl;
}

void print_vector(vector<int>& v){
    for(int i=0; i<v.size(); ++i)
        cout << v[i] << endl;
}


int main()
{
    string name = "ch17_drill.txt";
    ofstream os(name.c_str());
    
    int* p1 = new int[10];
    for(int i=0; i<10; ++i)
        p1[i] = i*2;
    
    int* p2 = new int[10];
    for(int i=0; i<10; ++i)
        p2[i] = p1[i];
    
    print_array(os, p1, 10);
    print_array(os, p2, 10);

    delete[] p1;
    delete[] p2;
    
    vector<int> v1(10);
    for(int i=0; i<10; ++i)
        v1[i] = i*2;
    
    vector<int> v2(10);
    for(int i=0; i<10; ++i)
        v2[i] = v1[i];
    
    print_vector(v1);
    print_vector(v2);
}