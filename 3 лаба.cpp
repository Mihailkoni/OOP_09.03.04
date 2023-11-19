#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Figure {
	string stroke = "none";
	double stroke_width = 1;
	string fill = "none";
	Figure(string stroke,double stroke_width, string fill) :stroke(stroke), stroke_width(stroke_width),fill(fill){};
	
};



struct Line :Figure {
	int x1;
	int y1;
	int x2;
	int y2;
	Line(int x1, int y1, int x2, int y2,string stroke,double stroke_width,string fill) :x1(x1), y1(y1), x2(x2), y2(y2),Figure(stroke,stroke_width,fill){};
};
ostream& operator<<(ostream& os, const Line& line) {
	os << "<line x1=\"" << line.x1 << "\" y1=\"" << line.y1 << "\" x2=\"" << line.x2 << "\" y2=\"" << line.y2 << "\" stroke=\"" << line.stroke << "\" stroke-width=\"" << line.stroke_width << "\" fill=\"" << line.fill << "\"/>";
	return os;
}



struct Circle :Figure {
	int x;
	int y;
	int r;
	Circle(int x, int y, int r, string stroke, double stroke_width, string fill) :x(x), y(y), r(r), Figure(stroke, stroke_width, fill) {};
};
ostream& operator <<(ostream& os, const Circle circle) {
	os << "<circle cx=\"" << circle.x << "\" cy=\"" << circle.y << "\" r=\"" << circle.r << "\" stroke=\"" << circle.stroke << "\" stroke-width=\"" << circle.stroke_width << "\" fill=\"" << circle.fill << "\"/>";
	return os;
}



struct Rectangle :Figure {
	int x;
	int y;
	int width;
	int height;
	string transform;
	string x1 = to_string(x);
	string y1 = to_string(y);
	Rectangle(int x, int y, int width, int height,string transform, string stroke, double stroke_width, string fill) :x(x), y(y), width(width), height(height),transform(transform), Figure(stroke, stroke_width, fill) {};
};
ostream& operator <<(ostream& os, const Rectangle rect) {
	os << "<rect x=\"" << rect.x << "\" y=\"" << rect.y << "\" width=\"" << rect.width << "\" height=\"" << rect.height << "\" transform=\"" << "rotate(" + rect.transform + " " + rect.x1 + " " + rect.y1 + ")" << "\" stroke=\"" << rect.stroke << "\" stroke-width=\"" << rect.stroke_width << "\" fill=\"" << rect.fill << "\"/>";
	return os;
}




struct Polygon : Figure {
	string x1, y1, x2, y2, x3, y3, x4, y4;
	Polygon(string x1, string y1, string x2, string y2, string x3, string y3, string x4, string y4, string stroke, double stroke_width, string fill) :x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4), Figure(stroke, stroke_width, fill) {};
};
ostream& operator <<(ostream& os, const Polygon pol) {
	os << "<polygon points=\"" << pol.x1 + "," + pol.y1 + " " + pol.x2 + "," + pol.y2 + " " + pol.x3 + "," + pol.y3 + " " + pol.x4 + "," + pol.y4 << "\" stroke=\"" << pol.stroke << "\" stroke-width=\"" << pol.stroke_width << "\" fill=\"" << pol.fill << "\"/>";
	return os;
}



struct Polyline : Figure {
	int x1, x2, x3, y1, y2, y3;
	Polyline(int x1, int y1, int x2, int y2, int x3, int y3, string stroke, double stroke_width, string fill):x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3),Figure(stroke,stroke_width,fill) {};
};
std::ostream& operator<<(std::ostream& os, const Polyline& polyline) {
	os << "<polyline points=\"" << polyline.x1 << " " << polyline.y1 << "," << polyline.x2 << " " << polyline.y2 << "," << polyline.x3 << " " << polyline.y3 <<"\" stroke=\"" << polyline.stroke << "\" stroke-width=\""<< polyline.stroke_width << "\" fill=\"" << polyline.fill << "\" opacity=\"" << "\" />";
	return os;
}



int main() {
	std::ofstream f("picture.svg");
	f << "<svg viewBox = \"0 -0 410 410\" xmlns = \"http://www.w3.org/2000/svg\" xmlns:xlink = \"http://www.w3.org/1999/xlink\">";
	
	// база картины
	Rectangle r{0,0,410,410,"0","none",0,"#FCE6BF"};
	f << r;

	Rectangle r1{ 5,5,400,400,"0","black",1,"#FCE6BF"};
	f << r1;
	//

	Polygon p13{ "355","82","372","72","388","220","366","215","none",0,"red" };
	f << p13;

	Polygon p11{ "5.5","240","5.5","208","49","275","37","283","none",0,"red" };
	f << p11;

	Polygon p1{ "285","5.5","319","5.5","344","26","329","39","none",0,"red" };
	f << p1;

	Rectangle r8{ 54,284,120,40,"50","none",0,"red" };
	f << r8;

	Rectangle r2{ 42,270,385,40,"-40","none",0,"black"};
	f << r2;

	Rectangle r3{ 43,321,400,30,"-40","black",1,"#D5AD70"};
	f << r3;

	Circle c{206, 174, 138, "none", 0, "red" };
	f << c;

	Rectangle r4{ 127,74,152,147,"0","#FCE6BF",1,"black"};
	f << r4;

	Line l{ 13,284,27,301,"black",1,"none" };
	f << l;

	Rectangle r5{13,301,18,2,"50","black",1,"#FCE6BF"};
	f << r5;
	
	Rectangle r6{ 136,22,30,2,"-9","black",1,"#FCE6BF" };
	f << r6;

	Rectangle r7{ 137,19,3,3,"-9","none",0,"red" };
	f << r7;

	Line l1{ 357,298,391,238,"red",1,"none" };
	f << l1;

	Rectangle r9{ 366,256,60,2,"-70","black",1,"#FCE6BF" };
	f << r9;

	Polygon p{"404.5","5.5","404.5","63","400","69","345","5.5","none",0,"red"};
	f << p;

	Polygon p2{ "387","65","392.5","60","405","75","400","80","none",0,"black" };
	f << p2;
	
	Polygon p3{ "5.5","30","26","5.5","70","5.5","28","49","none",0,"red" };
	f << p3;

	Polygon p4{ "39","18","52","5.2","58","5.2","43","22","black",1,"#FCE6BF" };
	f << p4;

	Polygon p5{ "330","405","305","372","349","346","405","405","none",0,"black" };
	f << p5;

	Polygon p6{ "349","353","368","336","405","365","405","405","none",0,"red" };
	f << p6;

	Polygon p7{ "370","404.5","358","389","362","385","377","404.5","black",1,"#FCE6BF" };
	f << p7;

	Polygon p8{"380","404.5","370","390","372","388","384","404.5","black",1,"#FCE6BF"};
	f << p8;

	Polygon p9{ "148","334","150","329","201","339","200","345","none",0,"red" };
	f << p9;

	Line l2{136,5,83,38,"black",1,"none"};
	f << l2;

	Line l3{ 71,19,90,49,"black",1,"none" };
	f << l3;

	Line l4{ 90,49,87,51,"black",1,"none" };
	f << l4;

	Line l5{ 71,19,68,21,"black",1,"none" };
	f << l5;

	Rectangle r10{ 83,38,18,10,"-122","none",0,"black" };
	f << r10;

	Rectangle r11{ 75,32,18,8,"55","none",0,"red" };
	f << r11;

	Line l6{ 76,47,66,55,"black",1,"none" };
	f << l6;

	Line l7{ 66,55,44,32,"black",1,"none" };
	f << l7;

	Polygon p10{ "5.5","110","49","38","58","47","5.5","142","none",0,"red" };
	f << p10;

	Polyline poly{ 405,365,395,357,405,345,"none",0,"black" };
	f << poly;

	Polygon p12{ "352","323","360","314","395","344","387","353","none",0,"black" };
	f << p12;

	Polyline poly1{ 321,347,299,292,348,326,"none",0,"red" };
	f << poly1;

	Polyline poly2{ 333,291,317,257,355,260,"none",0,"red" };
	f << poly2;

	Polyline poly3{ 361,287,350,276,365,282,"none",0,"black" };
	f << poly3;

	Polygon p14{ "391","175","387","131","405","131","405","174","black",1,"#FCE6BF" };
	f << p14;

	Polygon p15{ "177","363","178","344","295","319","304","334","none",0,"black" };
	f << p15;

	Line l8{ 55,59,9,165,"black",3,"none" };
	f << l8;

	Line l9{ 9,164,25,225,"black",3,"none" };
	f << l9;

	f.close();
	return 0;
}

