//ch17 drill1 配列とvectorの比較など


#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a){
    for(int i=0; i<10; ++i)
        os << a[i] << endl;
}

void print_array(ostream& os, int* a, int n){
    for (int i=0; i<n; ++i)
        os << a[i] << endl;
}

void create_vector(vector<int>& v, int n){
    for(int i=0; i<n; ++i)
        v[i] = i;
}


void print_vector(vector<int>& v){
    for (int i=0; i<v.size(); ++i)
        cout << v[i] << endl;
}

int main()
{
    int* p = new int[10];
    for(int i=0; i<10; ++i)
        cout << p[i] << endl;
    delete[] p;
    
    string name = "ch17_drill.txt";
    ofstream os(name.c_str());
    
    int* a = new int[10];
    print_array10(os, a);
    delete[] a;
    
    int* b = new int[10];
    for (int i=0; i<10; ++i)
        b[i] = 100+i;
    
    print_array10(os,b);
    delete[] b;
    
    int* c = new int[11];
    for (int i=0; i<11; ++i)
        c[i] = 100+i;
    print_array(os,c,11);
    delete[] c;
    
    int* d = new int[20];
    for (int i=0; i<20; ++i)
        d[i] = 100+i;
    print_array(os,d,20);
    delete[] d;
    
    vector<int> v_1(10);
    vector<int> v_2(11);
    vector<int> v_3(20);
    create_vector(v_1,10);
    create_vector(v_2,11);
    create_vector(v_3,20);
    
    cout << "print v1\n";
    print_vector(v_1);
    cout << "print v2\n";
    print_vector(v_2);
    cout << "print v3\n";
    print_vector(v_3);
    
}