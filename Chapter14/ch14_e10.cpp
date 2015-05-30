#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#define _USE_MATH_DEFINES

/*
 それほど思い切った作業をしなくても作成できる、Windowとよく似たPseudo_windowクラスを定義せよ。
 Pseudo_windowは角が丸く、ラベルと制御アイコンをもつ。画像などの偽のコンテンツを追加してもいいだろう。
 Pseudo_windowは実際には何もしなくてよい。それをSimple_window内に表示してもかまわない。（実際にはそれが推奨される。）
 */

namespace Graph_lib {

struct Pseudo_window : Window {
    Pseudo_window(Point xy, int w, int h, const string& title);
    bool wait_for_button(); // simple event loop
    
private:
    Button next_button;     // the "next" button
    bool button_pushed;     // implementation detail
    
    static void cb_next(Address, Address); // callback for next_button
    void next();



};
    
Pseudo_window::Pseudo_window(Point xy, int w, int h, const string& title) :
Window(xy,w,h,title),
next_button(Point(x_max()-100,0), 100, 50, "NEXT", cb_next),
button_pushed(false)
{
    attach(next_button);
}
    
    //------------------------------------------------------------------------------
    
bool Pseudo_window::wait_for_button()
    // modified event loop:
    // handle all events (as per default), quit when button_pushed becomes true
    // this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
        // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
        // To handle the case where the user presses the X button in the window frame
        // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}
    
    //------------------------------------------------------------------------------
    
void Pseudo_window::cb_next(Address, Address pw)
    // call Simple_window::next() for the window located at pw
{
    reference_to<Pseudo_window>(pw).next();
}
    
    //------------------------------------------------------------------------------
    
void Pseudo_window::next()
{
    button_pushed = true;
    hide();
}
    



}


int main()
{
	using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left corner of window

    Simple_window win(tl,500,500,"Canvas");    // make a simple window

    Point pt(200,200);
    Pseudo_window pwin(pt,250,250,"Pseudo_window");
    


	win.wait_for_button();
    pwin.wait_for_button();
    
    
}
