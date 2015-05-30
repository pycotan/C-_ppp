//
// 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// ch12_e5 画面の高さの４分の３、幅の３分の２の長方形の周りに１/４インチの赤いフレームを描画せよ。

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

    Rectangle r_in(Point(100,100),450,300);
	Rectangle r_out(Point(25,25),600,450);
	r_out.set_fill_color(Color::red);
	r_in.set_fill_color(Color::white);
	win.attach(r_out);
	win.attach(r_in);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
