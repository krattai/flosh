#include<dos.h>
#include<conio.h>

void main(void)
{
	char freq=0;
	int x=1;

/*
		1 - sound
		2 - delay
		3 - nosound
		4 - repeat
		5 - end repeat

		eg:
			4,3,1,100,2,400,3,2,5,5,1,80,2,1500,3

			equals

			for(x=0;x<=2;x++)
			{
				sound(100);
				delay(400);
				nosound();
				delay(5);
			}
			sound(80);
			delay(1500);
			nosound();

			therefore, (something like this)

			while(!end)
			{
				if(!repeat) get instruction
				switch(instruction)
				{
					case 1:	get value
							sound(value);
							break;
					case 2: get value
							delay(value);
							break;
					case 3: nosound();
							break;
					case 4:	get repeat length
							break;
					case 5: repeat start
							break;
				}
				repeat length --
			}

			note:  this won't quite work

*/
	clrscr();
	/*	*/
	sound(x);
	while(!kbhit() && freq < 3)
	{
		gotoxy(1,1);
		c�	����DX�[����#��F�4( $'������X'$
		else
		{
			x=0;
			freq++;
		}
		sound(x);
	}
	nosound();
	delay(1000);
	/*	*/
	for(x=0;x<=2;x++)
	{
		sound(100);
		delay(600);
		nosound();
		delay(5);
	}
	sound(80);
	delay(1500);
	nosound();
	delay(250);
	for(x=0;x<=2;x++)
	{
		sound(90);
		delay(600);
		nosound();
		delay(5);
	}
	sound(75);
	delay(1500);
	nosound();
	delay(1000);
	/*	*/
	sound(200);
	delay(900);
	sound(250);
	delay(400);
	sound(300);
	delay(400);
	sound(185);
	delay(500);
	sound(200);
	delay(100);
	sound(225);
	delay(100);
	sound(200);
	delay(400);
	nosound();
	delay(30);
	sound(335);
	delay(350);
	nosound();
	sound(335);
	delay(350);
	/*	*/
	sound(300);
	delay(300);
	sound(400);
	delay(300);
	sound(300);
	delay(300);
	nosound();
	/* */
	delay(5);
	sound(300);
	delay(100);
	sound(270);
	delay(100);
	sound(250);
	delay(100);
	sound(270);
	delay(100);
	sound(250);
	delay(400);
	nosound();
	delay(1000);
	/*	*/
	sound(100);
	delay(400);
	nosound();
	delay(5);
	sound(100);
	delay(400);
	nosound();
	delay(5);
	sound(100);
	delay(400);
	nosound();
	delay(5);
	sound(80);
	delay(1500);
	nosound();
	delay(250);
	sound(90);
	delay(400);
	nosound();
	delay(5);
	sound(90);
	delay(400);
	nosound();
	delay(5);
	sound(90);
	delay(400);
	nosound();
	delay(5);
	sound(75);
	delay(1500);
	nosound();
	delay(1000);
	/*	*/
	sound(200);
	delay(200);
	sound(275);
	delay(300);
	sound(200);
	delay(200);
	sound(275);
	delay(300);
	sound(200);
	delay(200);
	sound(275);
	delay(500);
	nosound();
	delay(20);
	sound(200);
	delay(200);
	sound(275);
	delay(150);
	sound(310);
	delay(150);
	sound(275);
	delay(150);
	sound(250);
	delay(150);
	sound(275);
	delay(150);
	sound(310);
	delay(800);
	nosound();
}