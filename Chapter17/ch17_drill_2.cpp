//ch17 drill2  ポインタと配列など

#include "std_lib_facilities.h"

/*
void print_array(ostream& os, int* a, int n){
    for (int i=0; i<n; ++i)
        os << a[i] << endl;
}
 */

int main()
{
    string name = "ch17_drill.txt";
    ofstream os(name.c_str());
    
    int* p1 = new int(7);
    cout << "point is " << p1 << " and val is " << *p1 << endl;
    
    int* p2 = new int[7];
    for(int i=0; i<7; ++i)
        p2[i] = i;
    cout << "point is " << p2 << " and val is " << *p2 << endl;

    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    
    cout << "point is " << p1 << " and val is " << *p1 << endl;
    cout << "point is " << p2 << " and val is " << *p2 << endl;
    
    delete[] p1;
    delete[] p2;
    

}