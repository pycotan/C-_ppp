/*
 ch18_drill ベクタと配列に関する章
 */
#include "std_lib_facilities.h"
/*
output is
init la
0	2	4	6	8	10	12	14	16	18	
init p
0	2	4	6	8	10	12	14	16	18	
init aa
1	1	2	6	24	120	720	5040	40320	362880	
init la
0	2	4	6	8	10	12	14	16	18	
init p
1	1	2	6	24	120	720	5040	40320	362880	
*/
int* ga = new int[10];

void f(int* a, int n)
{
	int* la = new int[10];

	cout << "init la" << endl;	

	for(int i=0; i<10; ++i)
	{
		la[i] = ga[i];
		cout << la[i] << "\t";
	}
	
	cout << endl;
	
	int* p = new int[10];

	cout << "init p" << endl;

	for(int i=0; i<10; ++i)
	{
		p[i] = a[i];
		cout << p[i] << "\t";
	}
	
	cout << endl;

	delete[] p;
}

int main()
{
	for(int i=0; i<10; ++i)
	{
		ga[i] = i*2;
	}	

	f(ga, 10);

	int* aa = new int[10];

	cout << "init aa" << endl;

	for(int i=0; i<10; ++i)
	{
		if(i==0)
			aa[i] = 1;
		else
			aa[i] = aa[i-1]*i;
		
		cout << aa[i] << "\t";
	}
	
	cout << endl;

	f(aa, 10);

	return 0;
}
