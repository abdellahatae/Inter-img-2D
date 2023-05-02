#include <iostream>
#include <string.h>
#include <fstream>
#include <graphics.h>

using namespace std;
class point {
public:
    //arguments Du point
    int x;
    int y;

public:
    //methods Du point
    //constructer
    point(int a=0,int b=0)
    {
        this->x = a;
        this->y = b;

    }
    
    //setters
    void setc(int nvx,int nvy)
    {
     this->x = nvx;
     this->y = nvy;
    }
   
};

class cercles {
private:
    //arguments Du cercle
    int x;
    int y;
    int r;
    int clr;
public:
    //methods Du cercle
    //constructer
    cercles(int a=0,int b=0,int c=0,int st=14)
    {
        this->x = a;
        this->y = b;
        this->r = c; 
        this->clr = st; 
    }
    //color function
    void color_Cercle()
    {
        setcolor(clr);
    
    }
    //cercle function
    void drow_Cercle()
    {
    circle(x,y,r);
    }
    // void Cercle (int x,int y,int r)
    // {  
    // circle(x,y,r);
    // }
    //setters
    void setc(int nvx,int nvy)
    {
     this->x = nvx;
     this->y = nvy;
    }
    void setr(int nvr)
     {
      this->r = nvr;
    }
     void setclr(int clr)
    {
     this->clr = clr;
    }
};
class ellipses {
private:
    //arguments Du ellipse
    int x;
    int y;
    int xr;
    int yr;
    int clr;
public:
    //methods Du ellipse
    //constructer
    ellipses(int x=0,int y=0,int xr=0,int yr=0,int clr=14)
    {
        this->x = x;
        this->y = y;
        this->xr = xr;
        this->yr = yr;
        this->clr = clr;

    }
    //color function
    void color_Ellipse()
    {
        setcolor(clr);
    
    }
    //ellipse function
    void drow_Ellipse()
{
    // here is the starting angle
    // and end angle
    int start_angle = 0;
    int end_angle = 360;

    ellipse(x, y, start_angle,end_angle, xr, yr);
}
    //setters
    void setc(int nvx,int nvy)
    {
     this->x = nvx;
     this->y = nvy;
    }
    void setr(int nvxr,int nvyr)
     {
     this->xr = nvxr;
     this->yr = nvyr;

    }
     void setclr(int clr)
    {
     this->clr = clr;
    }
};
class arcs {
private:
    //arguments Du arc
    int x;
    int y;
    int ad;
    int ar;
    int l;
    int clr;

public:
    //methods Du arc
    //constructer
    arcs(int x=0,int y=0,int ad=0,int ar=0,int l=0,int clr=14)
    {
        this->x = x;
        this->y = y;
        this->ad = ad;
        this->ar = ar;
        this->l = l;
        this->clr = clr;

    }
    //color function
    void color_Arc()
    {
        setcolor(clr);
    
    }
    //arc function
    void drow_Arc ()
    {
    arc(x, y, ad, ar, l);
    }
    //setters
    void setc(int nvx,int nvy)
    {
     this->x = nvx;
     this->y = nvy;
    }
    void setang(int nvad,int nvar)
     {
     this->ad = nvad;
     this->ar = nvar;
    }
    void setl(int nvl)
    {
     this->l = nvl;
    }
     void setclr(int clr)
    {
     this->clr = clr;
    }

};
class lignes{
private:
    //arguments Du ligne
    int xd;
    int yd;
    int xr;
    int yr;
    int clr;
public:
    //methods Du ligne
    //constructer
    lignes(int xd=0,int yd=0,int xr=0,int yr=0,int clr=14)
    {
        this->xd = xd;
        this->yd = yd;
        this->xr = xr;
        this->yr = yr;
        this->clr = clr;
    }  
    //color function
    void color_Ligne()
    {
        setcolor(clr);
    
    }
    //ligne function
    void drow_Ligne ()
    {
    line(xd,yd,xr,yr);
    }
    //setters
    void setd(int nvxd,int nvyd)
    {
     this->xd = nvxd;
     this->yd = nvyd;
    }
    void setr(int nvxr,int nvyr)
     {
     this->xr = nvxr;
     this->yr = nvyr;

    }
     void setclr(int clr)
    {
     this->clr = clr;
    }
};
class rectangles{
private:
    //arguments Du rectangle
    int xd;
    int yd;
    int hr;
    int wr;
    int clr;
public:
    //methods Du rectangle
    //constructer
    rectangles(int xd=0,int yd=0,int hr=0,int wr=0,int clr=14)
    {
        this->xd = xd;
        this->yd = yd;
        this->hr = hr;
        this->wr = wr;
        this->clr = clr;
    }
    //color function
    void color_Rectangle()
    {
        setcolor(clr);
    }
    //rectangle function
    void drow_Rectangle()
    {

    // rectangle function
    rectangle(xd, yd, hr, wr);
    }
    //setters
    void setd(int nvxd,int nvyd)
    {
     this->xd = nvxd;
     this->yd = nvyd;
    }
    void setl(int nvl,int nvw)
     {
     this->hr = nvl;
     this->wr = nvw;

    }
     void setclr (int clr)
    {
     this->clr = clr;
    }
};
class carres{
private:
    //arguments Du carre
    int xd;
    int yd;
    int h;
    int clr;
public:
    //methods Du carre
    //constructer
    carres(int xd=0,int yd=0,int h=0,int clr=14)
    {
        this->xd = xd;
        this->yd = yd;
        this->h = h;
        this->clr = clr;       

    }
    //color function
    void color_Carre()
    {
        setcolor(clr);
    
    }
    //carre function
   void drow_Carre ()
{
    rectangle(xd, yd, h, h);
}
    //setters
    void setd(int nvxd,int nvyd)
    {
     this->xd = nvxd;
     this->yd = nvyd;
    }
    void setl(int nvl)
     {
     this->h = nvl;

    }
     void setclr(int clr)
    {
     this->clr = clr;
    }
};
class triangles{
private:
    //arguments Du ligne
    int xd;
    int yd;
    int xa;
    int ya;
    int xr;
    int yr;
    int clr;

public:
    //methods Du triangle
    //constructer
    triangles(int xd=0,int yd=0,int xa=0,int ya=0,int xr=0,int yr=0,int clr=14)
    {
        this->xd = xd;
        this->yd = yd;
        this->xa = xa;
        this->ya = ya;
        this->xr = xr;
        this->yr = yr;
        this->clr = clr;

    }
    //color function
    void color_Triangle()
    {
        setcolor(clr);
    }
    //triangle function
    void drow_Triangle ()
    {

    line(xd,yd,xa,ya);
    line(xa,ya,xr,yr);
    line(xr,yr,xd,yd);

    }

    //setters
    void setd(int nvxd,int nvyd)
    {
     this->xd = nvxd;
     this->yd = nvyd;
    }
    void seta(int nvxa,int nvya)
    {
     this->xa = nvxa;
     this->ya = nvya;
    }

    void setr(int nvxr,int nvyr)
     {
     this->xr = nvxr;
     this->yr = nvyr;

    }
    void setclr(int clr)
    {
        this->clr = clr;
    }
};
int main(){
    
int gd = DETECT ,gm;
initgraph(&gd,&gm,(char*)"");


point pc1(300,250);
point p2(250,220);
point p3(10,400);
point p4(250,370);
point p5(250,430);
cercles Ce1(250,250,200);
Ce1.drow_Cercle();
cercles Ce2(350,250,100);
Ce2.drow_Cercle();
cercles Ce3(150,250,100);
Ce3.drow_Cercle();
cercles Ce4(100,250,30);
Ce4.drow_Cercle();
cercles Ce5(400,250,30);
Ce5.drow_Cercle();
ellipses El1(250,400,80,30);
El1.drow_Ellipse();
lignes Ln1(p4.x,p4.y,p5.x,p5.y);
Ln1.drow_Ligne();
lignes Ln2(280,375,280,425);
Ln2.drow_Ligne();
lignes Ln3(220,375,220,425);
Ln3.drow_Ligne();
rectangles Re1(50,250,p3.x,p3.y);
Re1.drow_Rectangle();
rectangles Re2(450,250,500,400);
Re2.drow_Rectangle();
rectangles Re3(5,10,510,470);
Re3.drow_Rectangle();
arcs Ar6(250,50,50,100,200);
Ar6.drow_Arc();
lignes Ln4(50,100,500,100);
Ln4.drow_Ligne();
getch();
closegraph();
return 0;
}
