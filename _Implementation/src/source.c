#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>

#define P M_PI/180

class MOUSE
{
private:
	union REGS i,o;
	int Button,x,y;
public:
	int initmouse();
	void hidemouse();
	void showmouse();
	void getmousepos(int &x,int &y,int &Button);
	void restrictmouse(int x1,int y1,int x2,int y2);
	void mouse();
}m;

int MOUSE::initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}

void MOUSE::hidemouse()
{
i.x.ax=2;
int86(0x33,&i,&o);
}

void MOUSE::showmouse()
{
i.x.ax=1;
int86(0x33,&i,&o);
}

void MOUSE::restrictmouse(int x1,int y1,int x2,int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
}

void MOUSE::getmousepos(int &x,int &y,int &Button)
{
i.x.ax=3;
int86(0x33,&i,&o);
Button=o.x.bx;
x=o.x.cx;
y=o.x.dx;
}

void MOUSE::mouse()
{
setviewport(0,0,639,479,1);
initmouse();
showmouse();
}


class BUTTON
{
public:
	int x,y;
	char *ch;
	int len;
	int brd;
	int t;
public:
	BUTTON(){};
	BUTTON(int a,int b,int c,int d,int e,char *k){x=a;y=b;t=c;len=d;brd=e;ch=k;};
	void box(int,int);
	void bkbox(int,int);
	void upside(int,int);
	void dwnside(int,int);
	void rside(int,int);
	void lside(int,int);
	void text();
	void draw();
	void initialize();

}button[]={  BUTTON (230,200,3,30,15,"7"),
	     BUTTON (265,200,3,30,15,"8"),
	     BUTTON (300,200,3,30,15,"9"),
	     BUTTON (335,200,3,30,15,"OFF"),
	     BUTTON (370,200,3,30,15,"CE"),

	     BUTTON (230,225,3,30,15,"4"),
	     BUTTON (265,225,3,30,15,"5"),
	     BUTTON (300,225,3,30,15,"6"),
	     BUTTON (335,225,3,30,15,"*"),
	     BUTTON (370,225,3,30,15,"/"),

	     BUTTON (230,250,3,30,15,"1"),
	     BUTTON (265,250,3,30,15,"2"),
	     BUTTON (300,250,3,30,15,"3"),
	     BUTTON (335,250,3,30,15,"+"),
	     BUTTON (370,250,3,30,15,"-"),

	     BUTTON (230,275,3,30,15,"0"),
	     BUTTON (265,275,3,30,15,"."),
	     BUTTON (300,275,3,30,15,"^"),
	     BUTTON (335,275,3,30,15,"DEL"),
	     BUTTON (370,275,3,30,15,"="),

	     BUTTON (230,300,3,30,15,"Tan"),
	     BUTTON (265,300,3,30,15,"Sin"),
	     BUTTON (300,300,3,30,15,"Cos"),
	     BUTTON (335,300,3,30,15,"Log"),
	     BUTTON (370,300,3,30,15,"Pow"),};



class WINDOW:public BUTTON
{
public:
	WINDOW(){};
	WINDOW(int a, int b,int c,int d,int e){x=a;y=b;t=c;len=d;brd=e;};
	void interior(int);
	void draw();
	void border();
}cabinate(220,100,8,200,250),display(240,120,2,160,30);

class SELECT:public BUTTON
{
private:
	char *num[11];
	char *operat;
	int oncedon;
	float number;
	int top,dot;
public:
	SELECT(){top=-1;dot=0;oncedon=0;number=0.0;};
	int check();
	float convert();
	void result_out(float);
	void reset();
	void take_num(int);
	float calculate();
	void output();
	void effect(int);
	void task(int);
}choice;



void SELECT::effect(int i)
{
button[i].lside(9,9);
button[i].dwnside(9,9);
button[i].bkbox(7,15);
button[i].text();
}

void BUTTON::text()
{
setcolor(0);
settextstyle(SMALL_FONT,HORIZ_DIR,0);
settextjustify(CENTER_TEXT,CENTER_TEXT);
outtextxy(x+15,y+6,ch);
}

float SELECT::convert()
{
float sum=0.0;
int cond=0,t=0;
int c=0;
for(int i=top;i>=0;i--,c++)
{
if((*num[i])!='.' && cond==0)
{
sum=sum+((*num[i])-48)*pow(10,c);
}
else if(cond==0)
{
sum=sum*pow(10,-(c));
cond=1;
i--;
}
if(cond==1 && i>=0)
{
sum=sum+((*num[i])-48)*pow(10,t);
t++;
}
}
return(sum);
}

void SELECT::reset()
{
top=-1;
oncedon=0;
dot=0;
output();
settextstyle(SMALL_FONT,HORIZ_DIR,6);
setcolor(4);
outtextxy(385,132,"00");
}

void SELECT::output()
{
int dx=390;
for(int x=243;x<=398;x++)
{
setcolor(15);
line(x,121,x,145);
}
for(int i=top;i>=0;i--)
{
settextstyle(SMALL_FONT,HORIZ_DIR,6);
setcolor(4);
outtextxy(dx,132,num[i]);
dx-=10;
}
}

void SELECT::result_out(float numb)
{
int i=0,dx=400;
char c[5];
char res[30];
for(x=243;x<=398;x++)
{
setcolor(15);
line(x,121,x,145);
}
sprintf(res,"%.4f",numb);
settextstyle(SMALL_FONT,HORIZ_DIR,6);
setcolor(4);
while(i<=strlen(res))
{
sprintf(c,"%c",res[strlen(res)-i]);
outtextxy(dx,132,c);
i++;
dx-=10;
}
}

float SELECT::calculate()
{
if(*operat=='+')
number=number+convert();
else if(*operat=='-')
number=number-convert();
else if(*operat=='*')
number=number*convert();
else if(*operat=='/')
number=number/convert();
else if(*operat=='^')
number=pow(number,0.5);
else if(*operat=='t')
{
if(convert()/90==1)
{
settextstyle(SMALL_FONT,HORIZ_DIR,6);
setcolor(4);
outtextxy(340,132,"UNDEFINED");
}
else
number=sin(convert()*P)/cos(convert()*P);
}
else if(*operat=='s')
number=sin(convert()*P);
else if(*operat=='c')
number=cos(convert()*P);
else if(*operat=='p')
number=pow(number,convert());
else if(*operat=='l')
number=log10(convert());
else if(*operat=='=')
number=number;

return(number);
}

void SELECT::take_num(int tsk)
{
if(top<=10)
{
if(tsk==16 && dot==0)
{
dot=1;
top++;
num[top]=button[tsk].ch;
}
else if(tsk!=16)
{
top++;
num[top]=button[tsk].ch;
}
}
}

void SELECT::task(int tsk)
{
if(tsk==4)
{
reset();
return;
}

if(tsk==18)
{
top--;
output();
}

if(tsk==3){
closegraph();
exit(1);
}

if(tsk==20 || tsk==21 || tsk==22 || tsk== 23)
{
if(tsk==20)
*operat='t';
if(tsk==21)
*operat='s';
if(tsk==22)
*operat='c';
if(tsk==23)
*operat='l';
oncedon=1;
}

if((tsk<=2 && tsk>=0) || tsk==16 || (tsk<=7 && tsk>=5) || (tsk<=12 && tsk>=10) || tsk==15)
{
take_num(tsk);
output();
}

if(tsk==8 || tsk==9  || tsk==13 || tsk==14 || tsk==17 || tsk==24)
{
if(oncedon==0)
{
number=convert();
if(tsk==24)
*operat='p';
else
operat=button[tsk].ch;
top=-1;
dot=0;
oncedon=1;
return;
}
}

if(tsk==19 || tsk==8 || tsk==9  || tsk==13 || tsk==14 || tsk==17 )
{
if(oncedon==1)
{
number=calculate();

if(tsk==19)
operat=operat;
else
operat=button[tsk].ch;

result_out(number);
top=-1;
dot=0;
}
}
}


int SELECT::check()
{
int x1,y1,b;
int cond=0;
m.getmousepos(x1,y1,b);
if(b==1)
{
for(int i=0;i<25;i++)
{
if(x1<(button[i].x+button[i].len) && x1>button[i].x && y1<(button[i].y+button[i].brd) && y1>button[i].y)
{
while(b==1 && x1<(button[i].x+button[i].len) && x1>button[i].x && y1<(button[i].y+button[i].brd) && y1>button[i].y)
{
m.getmousepos(x1,y1,b);
m.hidemouse();
effect(i);
m.showmouse();
delay(20);
}
cond=1;
break;
}
}
if(cond==1)
{
m.hidemouse();
button[i].draw();
m.showmouse();
}
return(i);
}
return(100);
}

void WINDOW::interior(int bcol)
{
setcolor(bcol);
line(x,y+brd,x+t,y+brd-t);
line(x+t,y+brd-t,x+len,y+brd-t);
line(x+t,y+brd-t,x+t,y);
}

void WINDOW::border()
{
setcolor(8);
setfillstyle(2,7);
rectangle(1,1,638,478);
rectangle(5,5,634,474);
setfillstyle(6,7);
floodfill(2,3,8);
}

void WINDOW::draw()
{
border();
cabinate.box(9,1);
cabinate.upside(11,8);
cabinate.rside(11,8);
display.box(15,16);
display.interior(8);

setcolor(7);
settextstyle(2,0,5);
outtextxy(248,160,"TENDY'Z CALCULATOR");
line(248,175,388,175);
setcolor(12);
settextstyle(2,0,4);
outtextxy(20,425,"CALCULATOR IN C++");
outtextxy(20,440,"CODING BY  - TONMOY SAHA (N.I.T DGP)");
outtextxy(20,455,"CONTACT ME - alwayshotme@yahoo.co.uk");

}

void BUTTON::box(int col,int bcol)
{
setcolor(bcol);
setfillstyle(SOLID_FILL,col);
rectangle(x,y,x+len,y+brd);
floodfill(x+len/2,y+brd/2,bcol);
}

void BUTTON::bkbox(int col,int bcol)
{
setcolor(bcol);
setfillstyle(SOLID_FILL,col);
rectangle(x+t,y-t,x+len+t,y+brd-t);
floodfill(x+t+len/2,y+t+brd/2,bcol);
}

void BUTTON::upside(int col,int bcol)
{
setcolor(bcol);
setfillstyle(SOLID_FILL,col);
line(x,y,x+t,y-t);
line(x+t,y-t,x+len+t,y-t);
line(x+len+t,y-t,x+len,y);
line(x,y,x+len,y);
floodfill(x+len/2,y-t/2,bcol);
}

void BUTTON::dwnside(int col,int bcol)
{
setcolor(bcol);
setfillstyle(SOLID_FILL,col);
line(x,y+brd,x+t,y-t+brd);
line(x+t,y-t+brd,x+len+t,y-t+brd);
line(x+len+t,y-t+brd,x+len,y+brd);
line(x,y+brd,x+len,y+brd);
floodfill(x+len/2,y+brd-t/2,bcol);
}

void BUTTON::rside(int col,int bcol)
{
setcolor(bcol);
setfillstyle(SOLID_FILL,col);
line(x+len,y,x+len+t,y-t);
line(x+len+t,y-t,x+len+t,y+brd-t);
line(x+len+t,y+brd-t,x+len,y+brd);
line(x+len,y+brd,x+len,y);
floodfill(x+len+t/2,y+t,bcol);
}

void BUTTON::lside(int col,int bcol)
{
setcolor(bcol);
setfillstyle(SOLID_FILL,col);
line(x,y,x+t,y-t);
line(x+t,y-t,x+t,y+brd-t);
line(x+t,y+brd-t,x,y+brd);
line(x,y+brd,x,y);
floodfill(x+t/2,y+t,bcol);
}


void BUTTON::initialize()
{
for(int i=0;i<25;i++)
{
button[i].draw();
}
}

void BUTTON::draw()
{
box(8,8);
upside(7,8);
rside(7,8);
text();
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"\\tc\\bgi");
m.mouse();
m.hidemouse();
cabinate.draw();
button[0].initialize();
m.showmouse();
while(1)
{
choice.task(choice.check());
}
}
