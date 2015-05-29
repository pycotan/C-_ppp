/* this is the answer for the chapter 11 drill .*/
/* the text book is "programming - principle and practice using c++ -" by bjarne stroustrup "*/
/* i am a student. if you find any errors, please contact me! */

#include "std_lib_facilities.h"

// this program is a practice for various output.
// point : dec hex oct, floating point format, field.

struct friends
{
    friends(string f1, string f2, string f3, string f4, string f5)
    :friend1(f1),friend2(f2),friend3(f3),friend4(f4),friend5(f5){}
    
    string friend1;
    string friend2;
    string friend3;
    string friend4;
    string friend5;
};

struct address
{
    address(string l, string f, string t, string e,friends F)
    :last_name(l),first_name(f),telephone_number(t),email(e),fivefriends(F){}
    string last_name;
    string first_name;
    string telephone_number;
    string email;
    friends fivefriends;
};

void create_sample_li(vector<string>& sample_li, address& sample_ad, friends& sample_fr)
{
    if(sample_li.size() != 9) error("sample_li is not enough size");
    sample_li[0] = sample_ad.last_name;
    sample_li[1] = sample_ad.first_name;
    sample_li[2] = sample_ad.telephone_number;
    sample_li[3] = sample_ad.email;
    sample_li[4] = sample_fr.friend1;
    sample_li[5] = sample_fr.friend2;
    sample_li[6] = sample_fr.friend3;
    sample_li[7] = sample_fr.friend4;
    sample_li[8] = sample_fr.friend5;
}

int main()
{
    // problem no.1
    // practice dec, hex, oct
    
    int birth_year;
    birth_year = 1987; // my birth year
    
    cout << dec << birth_year << "\t(decimal)" << endl << hex << birth_year << "\t(hexadecimal)" << endl << oct << birth_year << "\t(octal)" << endl;
    
    int my_age;
    my_age = 25; // personal information
    cout << dec << my_age << "\t(decimal)" << endl;
    
    int a;
    int b;
    int c;
    int d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    
    /*
    answer:
    input is "1234 1234 1234 1234" 
    output is "1234 668 4660 4660"
    
    summary:
    1234 (in oct)(to decimal) 668
    2322 (in hex)(to decimal) 4660
    
    */
    
    // problem no.9
    // practice floating point format
    
    cout << general << 1234567.89 << "\t(general)\n" << fixed << 1234567.89 << "\t(fixed)\n" << scientific << 1234567.89 << "\t(scientific)" << endl; 
    
    // problem no.10
    // practice field
    
    friends sample_fr("nana","aki","natsu","fuyumi","harue");
    address sample_ad("nyle","roseia","090-9999-9999","happy@gmail.com",sample_fr);

    vector<string> sample_li(9);
    
    create_sample_li(sample_li,sample_ad,sample_fr);
    
    for(int i=0; i<9; ++i){
        int char_size = sample_li[i].size();
        cout << '|' << setw(char_size) << sample_li[i] << '|' << endl;
        }
    
    return 0;
}