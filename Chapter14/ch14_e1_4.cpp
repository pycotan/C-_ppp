/*
 ch14_e1
 smileyとfrownyの二つのクラスの定義。どちらもcircleの派生クラスで２つの目と１つの口をもつ。
 次にsmiley,frownyから派生クラスを作成しそれぞれに帽子の追加。
 */



#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {

struct Smiley : Shape {
    Smiley(Point p);
    
	Circle reye;
	Circle leye;
	Circle face;
    
    Open_polyline mouth;

	void draw_lines() const;
};
    
Smiley::Smiley(Point p)
    :reye(Point(p.x+100,p.y+100),50), leye(Point(p.x+300,p.y+100),50), face(Point(p.x+200,p.y+200),300)
    {
    reye.set_color(Color::black);
    leye.set_color(Color::black);
    face.set_color(Color::black);
        
    mouth.add(Point(p.x+100,p.y+300));
    mouth.add(Point(p.x+200,p.y+350));
    mouth.add(Point(p.x+300,p.y+300));
    mouth.set_color(Color::black);
    }

void Smiley::draw_lines() const
{
	reye.draw_lines();
	leye.draw_lines();
	face.draw_lines();
    mouth.draw_lines();
}
    
struct Hat : Smiley {
    Hat(Point p);
    
    Rectangle hr;
    Lines hl;
    
    void draw_lines() const;
};
    
Hat::Hat(Point p)
    :Smiley(p), hr(Point(p.x, p.y-150),400,150)
    {
        hr.set_color(Color::black);
        hl.add(Point(p.x-100,p.y),Point(p.x+500,p.y));
        hl.set_color(Color::black);
    }
    
void Hat::draw_lines() const
{
    hr.draw_lines();
    hl.draw_lines();
}

}

int main()
{
	using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,800,"Canvas");    // make a simple window

	Point p(200,200);
    
	Smiley s(p);
    s.set_color(Color::black);
	win.attach(s);
    
    Hat h(p);
    h.set_color(Color::black);
    win.attach(h);

	win.wait_for_button();
}
