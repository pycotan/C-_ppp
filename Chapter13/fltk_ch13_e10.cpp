//
//
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// ch13_e10 regular_polugonクラス。中心、辺の数、中心から角までの距離をコンストラクタの引数として使用。

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

struct Regular_polygon : Closed_polyline {
	Regular_polygon(Point p, int rr, int n) : radius(rr), side_num(n)
	{
		if(n<4) error("we need side num more than 3.");
		double deg = 360.0/n;
		double PI = 3.141592;
		radian = deg*PI/180.0;
		add(Point(p.x,p.y-rr));
		int cx = p.x;
		int cy = p.y-rr;
		
		int i=1;
		while(i<n){
				int A = cx - p.x;
				int B = cy - p.y;
				cx = (A*cos(radian))-(B*sin(radian))+p.x;
				cy = (A*sin(radian))+(B*cos(radian))+p.y;
				add(Point(cx,cy));
				++i;
		}
	}
	 
	void draw_lines() const;

	int Radius() const { return radius; }
	double Radian() const {return radian;}

	private:
		int radius;
		double radian;
		int side_num;

};

void Regular_polygon::draw_lines() const
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
	int n=12;
    Regular_polygon rp(Point(a,b),r,n);       
	

    win.attach(rp);           // connect poly to the window
	



    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
