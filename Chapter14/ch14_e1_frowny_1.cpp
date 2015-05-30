/*
 ch14_e1
 smileyとfrownyの二つのクラスの定義。どちらもcircleの派生クラスで２つの目と１つの口をもつ。
 次にsmiley,frownyから派生クラスを作成しそれぞれに帽子の追加。
 */




#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {

struct Frowny : Circle {
    using Circle::Circle;
    Frowny(Point p);
    
	Circle reye;
	Circle leye;
	Circle face;
    
    Open_polyline mouth;

	void draw_lines() const;
};
    
Frowny::Frowny(Point p)
    :reye(Point(p.x+100,p.y+100),50), leye(Point(p.x+300,p.y+100),50), face(Point(p.x+200,p.y+200),300)
    {
    reye.set_color(Color::black);
    leye.set_color(Color::black);
    face.set_color(Color::black);
        
    mouth.add(Point(p.x+100,p.y+300));
    mouth.add(Point(p.x+200,p.y+250));
    mouth.add(Point(p.x+300,p.y+300));
    mouth.set_color(Color::black);
    }

void Frowny::draw_lines() const
{
	reye.draw_lines();
	leye.draw_lines();
	face.draw_lines();
    mouth.draw_lines();
}

}

int main()
{
	using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,800,"Canvas");    // make a simple window

	Point p(150,150);
    
	Frowny f(p);
    f.set_color(Color::black);
	win.attach(f);

	win.wait_for_button();
}
