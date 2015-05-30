//
// I edit Graph.cpp and Graph.h
// please check rewite program.
// chapter13 from PPP

// ch13_e2 角丸四角形の描画。４つのラインと４つの弧のboxクラス。

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------
struct Arc_Circle : Shape {
        Arc_Circle(Point p, int rr, double A1, double A2);	// center and radius
        
        void draw_lines() const;
        
        Point center() const;
        
        void set_radius(int rr) { set_point(0,Point(center().x-rr,center().y-rr)); r=rr;  }
        int radius() const { return r; }
    private:
        int r;
		double a1;
		double a2;
    };

Arc_Circle::Arc_Circle(Point p, int rr, double A1, double A2)    // center and radius
    :r(rr), a1(A1), a2(A2)
    {
        add(Point(p.x-r,p.y-r));       // store top-left corner
    }
    
    //------------------------------------------------------------------------------
    
    Point Arc_Circle::center() const
    {
        return Point(point(0).x+r, point(0).y+r);
    }
    
    //------------------------------------------------------------------------------
    
    void Arc_Circle::draw_lines() const
    {
        if (fill_color().visibility()) {	// fill
            fl_color(fill_color().as_int());
            fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,a1,a2);
            fl_color(color().as_int());	// reset color
        }
        
        if (color().visibility()) {
            fl_color(color().as_int());
            fl_arc(point(0).x,point(0).y,r+r,r+r,a1,a2);
        }
    }

struct Box : Shape {
		Box(Point xy, int ww, int hh) : w(ww), h(hh)
        {
            add(xy);
            if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
			
        }
        
        Box(Point x, Point y) : w(y.x-x.x), h(y.y-x.y)
        {
            add(x);
            if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
		
        }

        void draw_lines() const;
        
        int height() const { return h; }
        int width() const { return w; }
		
    private:
        int h;    // height
        int w;    // width
		

};
     void Box::draw_lines() const
    {
        if (fill_color().visibility()) {    // fill
            fl_color(fill_color().as_int());
            fl_rectf(point(0).x,point(0).y,w,h);
            fl_color(color().as_int());    // reset color
        }
        
        if (color().visibility()) {    // lines on top of fill
            fl_color(color().as_int());
            fl_rect(point(0).x,point(0).y,w,h);
        }
		int arc_radius = 30;
		fl_arc(point(0).x, point(0).y, arc_radius, arc_radius, 90, 180); //top left
		fl_arc(point(0).x+w-arc_radius, point(0).y, arc_radius, arc_radius, 0, 90); //top right
		fl_arc(point(0).x, point(0).y+h-arc_radius, arc_radius, arc_radius, 180, 270); //bottom left
		fl_arc(point(0).x+w-arc_radius, point(0).y+h-arc_radius, arc_radius, arc_radius, 270, 360); //bottom right
    }

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

	Arc_Circle c(Point(100,200),10,0,90);
	Box b(Point(100,100),100,200);

	win.attach(c);
	win.attach(b);
	

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
