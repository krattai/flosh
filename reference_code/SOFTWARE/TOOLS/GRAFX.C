/* GRAFX.C: Graphics Toolkit

	Mouse left 	- hand left
	Mouse right	- hand right
	Mouse up	- hand up
	Mouse down	- hand down
	Cursor up	- hand in
	Cursor down	- hand out

	Created by:		Kevin Rattai
	Date created:	May 1, 1993

*/

#include<bios.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"grafx2.h"

float x=0.0,y=0.0,z=0.0;
float sx=0.0,sy=0.0;
float xa=0.0,ya=0.0,za=0.0;
float sxa=0.0,sya=0.0,sxb=0.0,syb=0.0;
float sxs=0.0,sys=0.0;
float d=1200.0;
double r1=5.68319;
double r2=6.28319;
double r3=5.79778;
double sr1=0.0,sr2=0.0,sr3=0.0;
double cr1=0.0,cr2=0.0,cr3=0.0;
float msx=0.0,msy=0.0,msz=-350.0;
int maxx=639,minx=0,maxy=199,miny=0;
float screen_x=639,screen_y=199;
float rx=0.0,ry=0.0;
int t1=0,t2=0;
int p1=0;

int array1[][3]={
	30,-30,30,30,-30,-30,-30,-30,-30,-30,-30,30,30,-30,30,
	30,30,-30,-30,30,-30,-30,-30,-30,30,-30,-30,30,30,-30,
	-30,30,-30,-30,30,30,-30,-30,30,-30,-30,-30,-30,30,-30,
	-30,30,30,30,30,30,30,-30,30,-30,-30,30,-30,30,30,
	30,30,30,30,30,-30,30,-30,-30,30,-30,30,30,30,30,
	-30,30,-30,30,30,-30,30,30,30,-30,30,30,-30,0,-0};

int !rray2[][1  `αδ30,0,23,4,-30,-30,30,
	-30,-30,30,30,-30,30,0,-30,-23,-30,-30,30,
	-30,-30,30,0,-30,-23,0,23,4,-30,-30,30,
	30,-30,30,0,23,4,0,-30,-23,30,-30,30};

int c0=0,c1=1,c2=2,c3=3,c4=4,c5=5,c6=6,c7=7,c8=8,c9=9,c10=10,
	c11=11,c12=12,c13=13,c14=14,c15=15,mode_flag=0;
float sx1,sy1,sx2,sy2;
float x_res,y_res;

void newpos(void)
{
	cleardevice();
	x=0.0;y=0.0;z=0.0;
	sx=0.0;sy=0.0;
	xa=0.0;ya=0.0;za=0.0;
	sxa=0.0;sya=0.0;sxb=0.0;syb=0.0;
	sxs=0.0;sys=0.0;
	sr1=0.0;sr2=0.0;sr3=0.0;
	cr1=0.0;cr2=0.0;cr3=0.0;
	msx=0.0;msy=0.0;
	rx=0.0;ry=0.0;
	t1=0;t2=0;
	p1=0;
	rotation();
/*	for(t2=1;t2<=6;t2++) */
	for(t2=1;t2<=4;t2++)
	{
		setlinestyle(USERBIT_LINE,0xffff,NORM_WIDTH);

		/* get starting position */
/*		x=array1[p1][0];
		y=array1[p1][1];
		z=array1[p1][2]; */
		x=array2[p1][0];
		y=array2[p1][1];
		z=array2[p1][2];
		calc_3d();
		windows();
		sxa=sx;sya=sy;

		/* finish displaying side */
/*		for(t1=1;t1<=4;t1++) */
		for(t1=1;t1<=3;t1++)
		{
			p1++;
/*			x=array1[p1][0];
			y=array1[p1][1];
			z=array1[p1][2]; */
			x=array2[p1][0];
			y=array2[p1][1];
			z=array2[p1][2];
			calc_3d();
			windows();
			sxs=sx;
			sys=sy;
			sxb=sx;
			syb=sy;
			moveto(sxa,sya);
			lineto(sxb,syb);
			sxa=sxs;
			sya=sys;
		}
		p1++;
	}
}

void rotation(void)
{
	sr1=sin(r1);
	sr2=sin(r2);
	sr3=sin(r3);
	cr1=cos(r1);
	cr2=cos(r2);
	cr3=cos(r3);
	return;
}

void calc_3d(void)
{
	/* rotate */
	x=(-1)*x;
	xa=cr1*x-sr1*z;
	za=sr1*x+cr1*z;
	x=cr2*xa+sr2*y;
	ya=cr2*y-sr2*xa;
	z=cr3*za-sr3*ya;
	y=sr3*za+cr3*ya;

	/* translate */
	x=x+msx;
	y=y+msy;
	z=z+msz;
	if(z==0) z=0.00000001;

	/* project */
	sx=d*x/z;
	sy=d*y/z;
	if(z==0.00000001) z=0.0;
	return;
}

void windows(void)
{
	sx=sx+399;
	sy=sy+299;
	rx=screen_x/799;
	ry=screen_y/599;
	sx=sx*rx;
	sy=sy*ry;
	return;
}

void keyboard(void)
{
	if(bioskey(1)==0)
		return;
	else
		quit_pgm();
}

void quit_pgm(void)
{
	cleardevice();
	restorecrtmode();
	exit(0);
}

void graphics_setup(void)
{
	int graphics_adapter,gr_mode;

	graphics_adapter=VGA;gr_mode=VGAHI;
	initgraph(&graphics_adapter,&gr_mode,"");
	x_res=640;
	y_res=480;
	mode_flag=1;
	maxx=639;
	minx=0;
	maxy=479;
	miny=0;
	screen_x=639;
	screen_y=479;
	setcolor(7);
	return;
}