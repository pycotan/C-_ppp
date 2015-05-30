//
//
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// ch13_drill 8*8のグリッドを配置し、左上隅から始まる８個の正方形の色を赤にする。
// 200*200ピクセルの画像（melody.jpg,Husky.gif、アップしていない）をnextボタンがクリックされたら次の正方形に移動させる。

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "GUI.h"
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,800,1000,"Canvas");    // make a simple window

	int x_size = 800;
	int y_size = 800;
	const int x_grid = 100;
	const int y_grid = 100;

	Lines grid;
	for(int x = x_grid; x<x_size; x+=x_grid)
		grid.add(Point(x,0),Point(x,y_size));
	for(int y = y_grid; y<y_size; y+=y_grid)
		grid.add(Point(0,y),Point(x_size,y));

	win.attach(grid);

	Vector_ref<Rectangle> vr;

	int x = 0;
	int y = 0;
	for(int i=0; i<8; ++i){
		vr.push_back(new Rectangle (Point(x,y),100,100));
		x += x_grid;
		y += y_grid;
	}
	for(int i=0; i<8; ++i){
		vr[i].set_fill_color(Color::red);
		win.attach(vr[i]);
	}

	Image melody_1(Point(200,0),"melody.jpg");
	Image melody_2(Point(400,0),"melody.jpg");
	Image melody_3(Point(400,200),"melody.jpg");
	win.attach(melody_1);
	win.attach(melody_2);
	win.attach(melody_3);

	Image Husky(Point(0,0),"Husky.gif");
	win.attach(Husky);

	int count = 1;
	int a = 0;
	int b = 0;
    while(win.wait_for_button() && count<64){
		if((count%8 == 0) && (count!=0)){
			Husky.move(-700,y_grid);
		}
		else
			Husky.move(x_grid,0);
		++count;
	}

	win.wait_for_button();
}

//------------------------------------------------------------------------------
