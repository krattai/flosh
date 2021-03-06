/* GRFXTEST.C: Tests possiblity of getimage()'ing and putimage()'ing to and
			from a file by redirecting the image pointer to a file pointer.

	Created by:		Kevin Rattai
	Date created:	May 23, 1993

*/

#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<alloc.h>

int save_screen(void far *buf[4], FILE *fptr);
void restore_screen(FILE *fptr, unsigned size);

int maxx, maxy;

int main(void)
{
	int gdriver=DETECT, gmode, errorcode;
	unsigned size;
	void far *ptr[4];
	FILE *fptr;

	/* auto-detect the graphics driver and mode */
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult(); /* check for any errors */
	if(errorcode != grOk)
	{
		printf("Graphics error: %s\n",grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();

	/* draw an image on the screen */
	rectangle(0,0,maxx,maxy);
	line(0,0,maxx,maxy);
	line(0,maxy,maxx,0);

	fptr=fopen("TEST.PIC","w");
	size = save_screen(ptr,fptr);
	fclose(fptr);
	getch();
	cleardevice();
	fptr=fopen("TEST.PIC","r");
	restore_screen(fptr,size);
	fclose(fptr);
	getch();

	closegraph();
	return 0;
}

int save_screen(void far *buf[4], FILE *fptr)
{
	unsigned size;
	int ystart=0,yend,yincr,block;

	yincr=(maxy+1)/4;
	yend=yincr;
	size=imagesize(0,ystart,maxx,yend);

	for(block=0;block<=3;block++)
	{
		if((buf[block] = farmalloc(size)) == NULL)
		{
			closegraph();
			printf("Error: not enough heap size in save_screen().\n");
			exit(1);
		}

		getimage(0,ystart,maxx,yend,buf[block]);
		fwrite(buf[block],size,1,fptr);
		farfree(buf[block]);
		ystart=yend+1;
		yend+=yincr+1;
	}
	return(size);
}

void restore_screen(FILE *fptr, unsigned size)
{
	int ystart=0,yend,yincr,x;
	void far *ptr[4];

	yincr=(maxy+1)/4;
	yend=yincr;

	for(x=0;x<=3;x++)
	{
		if((ptr[x] = farmalloc(size)) == NULL)
		{
			closegraph();
		�	��PD�dNg<
B��y��@C �p�vm�l�6.��f�	���P(�	� �7a��{ �t@琟�v}�J����ead(ptr[x],size,1,fptr);
		putimage(0,ystart,ptr[x],COPY_PUT);
		ystart=yend+1;
		yend+=yincr+1;
		farfree(ptr[x]);
	}
}