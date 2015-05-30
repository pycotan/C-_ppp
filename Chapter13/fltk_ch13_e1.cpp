//
// I edit Graph.cpp and Graph.h
// please check rewite program.
// chapter13 from PPP

// ch13_e1 楕円の一部を描画するarkクラスを定義せよ。

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------
 struct Arc_ellipse : Shape {
        Arc_ellipse(Point p, int ww, int hh, double A1, double A2)	// center, min, and max distance from center
		:w(ww), h(hh), a1(A1),a2(A2) { add(Point(p.x-ww,p.y-hh)); }
        
        void draw_lines() const;
        
        Point center() const { return Point(point(0).x+w,point(0).y+h); }
        Point focus1() const {
			if (h<=w)// foci are on the x-axis:
                return Point(center().x+int(sqrt(double(w*w-h*h))),center().y);
			else	// foci are on the y-axis:
                return Point(center().x,center().y+int(sqrt(double(h*h-w*w))));
        }
        
        Point focus2() const {
			if (h<=w)
                return Point(center().x-int(sqrt(double(w*w-h*h))),center().y);
			else
                return Point(center().x,center().y-int(sqrt(double(h*h-w*w))));
        }
        //Point focus2() const { return Point(center().x-int(sqrt(double(abs(w*w-h*h)))),center().y); }
        
        void set_major(int ww) { set_point(0,Point(center().x-ww,center().y-h)); w=ww; }
        int major() const { return w; }
        void set_minor(int hh) { set_point(0,Point(center().x-w,center().y-hh)); h=hh; }
        int minor() const { return h; }
    private:
        int w;
        int h;
		double a1;
		double a2;
    };
    
  void Arc_ellipse::draw_lines() const
    {
        if (fill_color().visibility()) {	// fill
            fl_color(fill_color().as_int());
            fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,a1,a2);
            fl_color(color().as_int());	// reset color
        }
        
        if (color().visibility()) {
            fl_color(color().as_int());
            fl_arc(point(0).x,point(0).y,w+w,h+h,a1,a2);
        }
    }

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

	Circle c(Point(100,200),50);

	Arc_ellipse a(Point(100,200),75,25,0,120);

	win.attach(c);
	
	win.attach(a);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
