#include<iostream>
#include<math.h>
#include<graphics.h>
#define pi 3.14159
using namespace std;

class shape
{
protected:
    int x,y;
public:
    virtual void getdata()=0;
    virtual void display()=0;
    virtual void area()=0;
    virtual void perimeter()=0;
};
class point : public shape
{
    void getdata()
    {
        cout<<"Give The Co-ordinate of Point:";
        cin>>x>>y;
    }
    void display()
    {
        putpixel(x,y,WHITE);
    }
    void area()
    {
        cout<<"A point has Zero area.\n";
    }
    void perimeter()
    {
        cout<<"A point has Zero perimeter.\n ";
    }
};
class Ellip : public shape
{
protected:
    int a,b;
public:
    void getdata()
    {
        cout<<"Give The Co-ordinates of Center:";
        cin>>x>>y;
        cout<<"Give Length of Axes in X & Y direction Respectively:";
        cin>>a>>b;
    }
    void display()
    {
        fillellipse(x,y,a,b);
    }
    void area()
    {
        cout<<" Area is "<<pi*a*b<<" units.\n";
    }
    void perimeter()
    {
        cout<<" Perimeter is "<<pi*(3*(a+b)-sqrt((3*a+b)*(a+3*b)))<<" units.\n";
    }
};
class Circle : public Ellip
{
public:
    void getdata()
    {
        cout<<"Give The Co-ordinates of Center:";
        cin>>x>>y;
        cout<<"Give Radius:";
        cin>>a;
        b=a;
    }
};
class Rect : public shape
{
protected:
    int a,b;
public:
    void getdata()
    {
        cout<<"Give Co-ordinates for top left corner:";
        cin>>x>>y;
        cout<<"Give Co-ordinates for bottom right corner:";
        cin>>a>>b;
    }
    void display()
    {
        rectangle(x,y,a,b);
    }
    void area()
    {
        cout<<"Area is "<<abs((a-x)*(y-b))<<" units.\n";
    }
    void perimeter()
    {
        cout<<"Perimeter is "<<2*(abs(a-x)+abs(y-b))<<" units.\n";
    }
};
class Square : public Rect
{
    int l;
public:
    void getdata()
    {
        cout<<"Give Co-ordinates for top left corner:";
        cin>>x>>y;
        cout<<"Give the length of side:";
        cin>>l;
        a = l+x;
        b = l+y;
    }
};
class quadrilateral : public shape
{
public:
    int x2,y2,x3,y3,x4,y4;
    void getdata()
    {
        cout<<"Give the Four Co-ordinates of Quadrilateral [x , y]:";
        cin>>x>>y>>x2>>y2>>x3>>y3>>x4>>y4;
    }
    void display()
    {
        line(x,y,x2,y2);
        line(x2,y2,x3,y3);
        line(x3,y3,x4,y4);
        line(x4,y4,x,y);
    }
    void area()
    {
        cout<<"The Area is "<<abs((x*(y2 - y3) + x2*(y3 - y) + x3*(y - y2))/2.0)+abs((x*(y4 - y3) + x4*(y3 - y) + x3*(y - y4))/2.0)<<" units.\n";
    }
    void perimeter()
    {
        cout<<"The Perimeter is "<<2*(sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) + sqrt((x4 - x)*(x4 - x) + (y4 - y)*(y4 - y)))<<" units.\n";
    }
};
class parallelogram : public quadrilateral
{
public:
    void getdata()
    {
        cout<<"Give Three Cyclic Co-ordinates of Parallelogram [ x , y ]:";
        cin>>x>>y>>x2>>y2>>x3>>y3;
        x4 = x + x3 - x2;
        y4 = y + y3 - y2;
    }
};
class rhombus : public parallelogram
{
public:
    void getdata()
    {
        cout<<"Give Three Cyclic Co-ordinates of Parallelogram [ x , y ]:";
        cin>>x>>y>>x2>>y2>>x3>>y3;
        x4 = x + x3 - x2;
        y4 = y + y3 - y2;
        //int a=abs(((y4-y2)*(y3-y))/((x3-x)*(x4-x2)));
        if( sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) != sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)) )
        {
            cout<<"For Given Co-ordinates Rhombus is Not Possible\nSo ";
            x=x2=x3=x4=0;
            y=y2=y3=y4=0;
        }
    }
};
class polygon:public shape
{
protected:
	int *pt,*x,*y,num,i,j,k;
	double ar=0,pr;
	public:
	void getdata()
	{
		cout<<"\n\nEnter The No. Of Vertex Of Polygon:";
		cin>>num;
		pt = new int [2*num+2];
		x  = new int [num+1];
		y  = new int [num+1];
		cout<<"\n\nEnter The Coordinates Of The Points :-";
		for(i=0;i<(2*num);i+=2)
		{
			cin>>pt[i]>>pt[i+1];
		}
		pt[i]=pt[0];
		pt[i+1]=pt[1];
	}
	void display()
	{
		drawpoly(num+1,pt);
	}
	void area()
	{
		j=0;k=0;
		for(i=0;i<(2*num);i++)
		{
			if(i%2==0)
			{
				x[j]=pt[i];
				j++;
			}
			else
            {
                y[k]=pt[i];
				k++;
            }
		}
		j=num-1;
		for(i=0;i<num;i++)
		{
			ar=ar+(x[j]+x[i])*(y[j]-y[i]);
			j=i;
		}
		cout<<"\n\n\t Area Of Given Shape Is: "<<abs(ar/2)<<" .\n";
	}
	void perimeter()
	{
		j=num-1;
		pr=0;
		for(i=0;i<num;i++)
		{
			pr=pr+sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			j=i;
		}
		cout<<"\n\n\t Perimeter Of Given Shape Is: "<<pr<<" .\n";
	}
};
class Line : public shape
{
    int a,b;
public:
    void getdata()
    {
        cout<<"Give Co-ordinates of initial point:";
        cin>>x>>y;
        cout<<"Give Co-ordinates of Final Point:";
        cin>>a>>b;
    }
    void display()
    {
        line(x,y,a,b);
    }
    void area()
    {
        cout<<"A line has Zero area\n";
    }
    void perimeter()
    {
        cout<<"The Perimeter of line is "<<sqrt((a-x)*(a-x)+(b-y)*(b-y))<<" units.\n";
    }
};
class Triangle : public shape
{
    int x2,y2,x3,y3;
    void getdata(){
    cout<<"Give The Co-ordinates For Triangle\n First Point:";
    cin>>x>>y;
    cout<<"Second Point:";
    cin>>x2>>y2;
    cout<<"Third Point:";
    cin>>x3>>y3;
                  }
    void display()
    {
        line(x,y,x2,y2);
        line(x3,y3,x2,y2);
        line(x,y,x3,y3);
    }
    void area()
    {
        cout<<"The Area Of Triangle is "<<abs((x*(y2 - y3) + x2*(y3 - y) + x3*(y - y2)) / 2)<<" units.\n";
    }
    void perimeter()
    {
        cout<<"The Perimeter Is "<<sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) + sqrt((x3 - x)*(x3 - x) + (y3 - y)*(y3 - y))+sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3))<<" units.\n";
    }
};
int main()
{
    int gd = DETECT ,gm,num;
    initgraph(&gd ,&gm ,"..\\BGI");
    setcolor(BLUE);
    shape *s;
    cout<<"Choose the Figure for Analysis:\n1.Point   \t\t\t2.Line\n3.Circle \t\t\t4.Rectangle\n5.Ellipse\t\t\t6.Triangle\n7.Square \t\t\t8.Parallelogram\n9.Quadrilateral\t\t\t10.Rhombus\n11.Polygon\n";
    cin>>num;
    if(num==1)
    {
        point obj;
        s = &obj;
    }
    else if(num==2)
    {
       Line obj;
       s = &obj;
    }
    else if(num==3)
    {
        Circle obj;
        s = &obj;
    }
    else if(num==4)
    {
        Rect obj;
        s = &obj;
    }
    else if(num==5)
    {
        Ellip obj;
        s = &obj;
    }
    else if(num==6)
    {
        Triangle obj;
        s = &obj;
    }
    else if(num==7)
    {
        Square obj;
        s = &obj;
    }
    else if(num==8)
    {
        parallelogram obj;
        s = &obj;
    }
    else if(num==9)
    {
        quadrilateral obj;
        s = &obj;
    }
    else if(num==10)
    {
        rhombus obj;
        s = &obj;
    }
    else if(num==11)
    {
        polygon obj;
        s = &obj;
    }
    s -> getdata();
    s -> display();
    s -> area();
    s -> perimeter();
    getch();
    closegraph();
    return 0;
}
