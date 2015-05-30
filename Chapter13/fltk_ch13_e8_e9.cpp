//
// 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// ch13_e8,e9 六角形クラスの定義。その後８つの六角形のタイル表示。

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

struct Regular_hexagon : Closed_polyline {
	Regular_hexagon(Point p, int rr) : r(rr)
	{
		Point p1(p.x, p.y-r);
		Point p2(p.x+(r*sqrt(3)/2), p.y-(r/2));
		Point p3(p.x+(r*sqrt(3)/2), p.y+(r/2));
		Point p4(p.x, p.y+r);
		Point p5(p.x-(r*sqrt(3)/2), p.y+(r/2));
		Point p6(p.x-(r*sqrt(3)/2), p.y-(r/2));	
		add(p1);
		add(p2);
		add(p3);
		add(p4);
		add(p5);
		add(p6);
	}

	void draw_lines() const;

	int radius() const { return r; }

	private:
		int r;
};

void Regular_hexagon::draw_lines() const
{
	Closed_polyline::draw_lines();
}

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

	int a=200;
	int b=200;
	int r=100;
    Regular_hexagon rh0(Point(a,b),r);       
	Regular_hexagon rh1(Point(a+(r*sqrt(3)),b),r);
	Regular_hexagon rh2(Point(a+(r*sqrt(3)*2),b),r);
	Regular_hexagon rh3(Point(a-(r*sqrt(3)/2),b+(r/2*3)),r);
	Regular_hexagon rh4(Point(a+(r*sqrt(3)/2),b+(r/2*3)),r);
	Regular_hexagon rh5(Point(a+(r*sqrt(3)/2*3),b+(r/2*3)),r);
	Regular_hexagon rh6(Point(a,b+3*r),r);
	Regular_hexagon rh7(Point(a+(r*sqrt(3)),b+3*r),r);


    win.attach(rh0);           // connect poly to the window
	win.attach(rh1);
	win.attach(rh2);
	win.attach(rh3);
	win.attach(rh4);
	win.attach(rh5);
	win.attach(rh6);
	win.attach(rh7);



    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
