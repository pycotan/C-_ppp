//
//
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//　ch13_e7 RGBカラーチャートの作成

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

    Vector_ref<Rectangle> vr;

	
	for(int i=0; i<16; ++i)
		for(int j=0; j<16; ++j){
			vr.push_back(new Rectangle(Point(i*20,j*20),20,20));
		}

	int i=0;
	while(i<216){
		for(int r=0; r<=255; r+=51)
			for(int g=0; g<=255; g+=51)
				for(int b=0; b<=255; b+=51){
					vr[i].set_fill_color(fl_rgb_color(r,g,b));
					win.attach(vr[i]);
					++i;
				}
	}
	while(i<256){
		vr[i].set_fill_color(Color::black);
		win.attach(vr[i]);
		++i;
	}

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
