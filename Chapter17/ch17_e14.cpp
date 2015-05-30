/*
 ポインタに関する１７章。ベクタやフリーストアについて。
 ch17_e14
 リストとリンクの使い方の練習。テキストにでてきたサンプルコードを元に北欧神話の神を短いリストで表現した。
 
 */


#include "std_lib_facilities.h"


struct God {
	God(string n, string m, string v, string w)
		:name(n), mythology(m), vehicle(v), weapon(w) { }
	string name;
	string mythology;
	string vehicle;
	string weapon;
};

class Link {
public:
	God god;

	Link(const God& g, Link* p = 0, Link* s = 0)
		:god(g), prev(p), succ(s) { }
	
	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s);
	const Link* find(const string& s) const;
	Link* advance(int n);
	Link* next() const { return succ; }
	Link* previous() const { return prev; }

private:
	Link* prev;
	Link* succ;

};

Link* Link::insert(Link* n)
{
	if (n==0) return this;
	if (this==0) return n;
	n->succ = this;
	if(this->prev) this->prev->succ = n;
	n->prev = this->prev;
	this->prev = n;
	return n;
}

Link* Link::add(Link* n)
{
	if (n==0) return this;
	if (this==0) return n;
	n->prev = this;
	if(this->succ) this->succ->prev = n;
	n->succ = this->succ;
	this->succ = n;
	return n;
}

Link* Link::erase()
{
	if(this==0) return 0;
	if(this->next()) this->succ->prev = this->previous();
	if(this->previous()) this->prev->succ = this->next();
	return this->next();
}

Link* Link::find(const string&s)
{
    Link* p = this;
	while(p){
		if(p->god.name == s) return p;
		p = p->succ;
	}
	return 0;
}

Link* Link::advance(int n)
{
    Link* p = this;
	if(p==0) return 0;
	if(0<n){
		while(n--){
			if(p->next() == 0) return 0;
			p = p->succ;
		}
	}
	else if(n<0){
		while(n++){
			if(p->previous() == 0) return 0;
			p = p->prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while(p) {
		cout << p->god.name << " , " << p->god.mythology << " , " << p->god.vehicle << " , " << p->god.weapon;
		if(p=p->next()) cout << " \n ";
	}
	cout << " }";
}

int main()
{
	God Thor("thor", "nourse", "goat", "hammer");
	God Odin("odin", "nourse", "horse", "wisdom");
	God Freia("freia", "nourse", "cat", "love");	

	God Hera("hera", "greek", "cow", "marriage");
	God Athena("athena", "greek", "owl", "intelligence");
	God Ares("ares", "greek", "wolf", "war");
	God Poseidon("poseidon", "greek", "dolphin", "sea");

	Link* nourse_gods = new Link(Thor);
	nourse_gods = nourse_gods->insert(new Link(Odin));
	nourse_gods = nourse_gods->insert(new Link(Freia));

	Link* greek_gods = new Link(Hera);
	greek_gods = greek_gods->insert(new Link(Athena));
	greek_gods = greek_gods->insert(new Link(Ares));
	greek_gods = greek_gods->insert(new Link(Poseidon));

	print_all(nourse_gods);
	cout << endl;
	print_all(greek_gods);
	cout << endl;
}
