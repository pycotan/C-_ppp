#include "std_lib_facilities.h"

class B1{
	public:
		virtual void vf() { cout << "B1::vf()\n"; };
		void f() { cout << "B1::f()\n"; }
		virtual void pvf() = 0;
};

struct D1 :B1{
	void vf(){ cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
};

struct D2 :D1{
	void pvf() { cout << "D2::pvf()\n"; }
};

void call(B1& b1){
	b1.vf();
	b1.f();
}

int main()
{
	
	B1 b1;

	b1.vf();
	b1.f();

	D1 d1;

	d1.vf();
	d1.f();

	call(d1);
	

	D2 d2;
	
	d2.vf();
	d2.f();
	d2.pvf();

}

