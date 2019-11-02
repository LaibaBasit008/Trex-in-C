//NAME                                  CMS ID
//Laiba Basit                           255374
//Alina Tabish                          242920
//Ayesha Mauqeem                        244369
//Haris Riaz                            178239
//T-REX GAME
//BSCS 8B
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

/* GLOBAL VARIBLES*/

char ch, q;
int flag = 0, k, i, l, t = 2, max;
void ds(int, int);
static int x = 0, scr = 0;
int minute = 0, second = 0, millisecond = 0;
int w;

/* DELAY FUNCTION */

void delay(unsigned int mseconds) // FUNCTION USED TO DELAY THE OUTPUT BY MILLISECONDS
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

/*GOTOXY FUNCTION*/

void gotoxy(int x, int y) // FUNCTION USED TO SET THE COORDINATES 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	w = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


/* FUNCTION TO CREATE A TIMER */

void printClock()
{
	gotoxy(62, 6);
	HANDLE colour_change;

	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //Changing the colour of clock to white
	gotoxy(2,2);
	printf(" %d:%d:%d\n", minute, second, millisecond);  //output the data
	

	// clear output buffer
	fflush(stdout);
	// update minute, second, millisecond
	millisecond++;

	if (millisecond == 50) {
		second += 1;
		millisecond = 0;
	}
	if (second == 60) {
		minute += 1;
		second = 0;
		millisecond = 0;
	}
	if (minute == 60) {
		minute = 0;
		second = 0;
		millisecond = 0;
	}
}


/* MENU FUNCTION */

void menu(char q) // Menu which is displayed at the start of the game
{

	/* Graphic Symbols used to write "T-REX GAME" */
	gotoxy(23, 18);
	printf("€ﬂﬂ€ﬂﬂ€     €ﬂﬂﬂ€  €ﬂﬂﬂﬂ   €     €       €ﬂﬂﬂﬂ  €ﬂﬂﬂ€  €     €  €ﬂﬂﬂﬂ \n");
	gotoxy(23, 19);
	printf("   €        €   €  €        €‹ ‹€        €      €   €  €ﬂ‹ ‹ﬂ€  €      \n ");
	gotoxy(23, 20);
	printf("   €        €€ﬂﬂﬂ  €ﬂﬂﬂﬂ     ‹€‹         €      €ﬂﬂﬂ€  €  ﬂ  €  €ﬂﬂﬂﬂ    \n   ");
	gotoxy(23, 21);
	printf("   €  ﬂﬂﬂﬂ  € €    €        €   €        €  ﬂ€  €   €  €     €  €         \n");
	gotoxy(23, 22);
	printf("   €        €  €   €‹‹‹‹   €     €       €‹‹‹€  €   €  €     €  €‹‹‹‹      \n        ");



	
	/* Menu displyed at the start */
	gotoxy(45, 25);
	if (q == 'y')
	{
		printf("WELCOME TO THE T-REX GAME \n");

		gotoxy(42, 27);

		printf("Press Space to Play or X to Exit\n");
	}
	else // if player presses 'x'

	{
		printf(" GOODBYE HAVE A NICE DAY!");
		return 0;
	}

}



/* SCORE FUNCTION */

int top = 0;
void score()
{
	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //Changing the colour of dinosaur to green
	system("cls");  // to clear the output console
	gotoxy(16, 3);
	printf("Press X to Exit, Press Space to Jump");
	gotoxy(62, 4);
	printf("High Score : %d", max);
	gotoxy(62, 2);
	printf("SCORE : %d", scr);
}
/* STARTUP MENU FUNCTION */

void startup_menu()
{
	gotoxy(34, 20);


	system("cls");
	menu(q);  // menu function called
	while (!_kbhit()) // while loop runs until user hits any key
	{
		ds(0, 400); // dinosaur function is called with arguments jump and speed
	}

	score(); // score function called
	gotoxy(1, 25);
	for (int x = 0; x < 79; x++)
		printf("ﬂ"); // graphic symbol
}

/* DINOSAUR FUNCTION */

int  speed = 40;
int jump = 0;
void ds(int jump, int speed)  // jump = position of dinosuar, speed = movement speed of dinosaur
{
	int p = 0;
	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN); //Changing the colour of dinosaur to green
	static int a = 1;  //  using static int so it stays till the end of the program


	if (jump == 0)  // when the argument is 0
		t = 0;
	else if (jump == 2) // when the argument is 2
		t--;
	else t++; // when the argument is something else

	/* Graphics Symbols used to create the DINOSAUR */
	gotoxy(t, 15 - t);
	printf("                      ");
	gotoxy(t, 16 - t);

	printf("         ‹€ﬂ€€€€‹   ");
	if (t > 0 || t < 0)
		printf("                       ");
	gotoxy(0 + t, 17 - t);
	printf("         €€€€€€€€  ");
	if (t > 0 || t < 0)
		printf("               ");
	gotoxy(0 + t, 18 - t);
	printf("         €€€€€ﬂﬂﬂ");
	if (t > 0 || t < 0)
		printf("             ");
	gotoxy(t, 19 - t);
	printf(" €      ‹€€€€ﬂﬂﬂ ");
	if (t > 0 || t < 0)
		printf("                          ");

	if (t > 0 || t < 0)
	{
		gotoxy(0, 20 - t);
		printf("   ");
	}
	gotoxy(t, 20 - t);
	printf(" €€‹  ‹€€€€€€‹‹‹ ");
	if (t > 0 || t < 0)
		printf("                             ");
	gotoxy(t, 21 - t);
	printf(" ﬂ€€€€€€€€€€€  ﬂ ");
	if (t > 0 || t < 0)
		printf("                         ");
	gotoxy(t, 22 - t);
	printf("   ﬂ€€€€€€€ﬂ     ");
	if (t > 0 || t < 0)
		printf("                            ");
	gotoxy(t, 23 - t);
	if (jump == 1 || jump == 2) {

		printf("    €€ﬂ ﬂ€       ");
		if (t > 0 || t < 0)
			printf("                              ");
		gotoxy(t, 24 - t);
		printf("    €‹   €‹      ");
		if (t > 0 || t < 0)
			printf("                           ");
		if (p <= 4 && w <= 20)
			gotoxy(t + 8, 25 - t - p);
		printf("   ");
		p++;
	}
	else if (a == 1)
	{
		printf("    ﬂ€€ﬂ  ﬂﬂﬂ    ");
		if (t > 0 || t < 0)
			printf("                ");
		gotoxy(t, 24 - t);

		printf("      €‹         ");
		if (t != 0)
		{
			gotoxy(t + 0, 16 - t);
			printf("                            ");
		}
		a = 2;
	}
	else if (a == 2)
	{
		printf("     ﬂ€‹ ﬂ€      ");
		if (t > 0 || t < 0)
		{
			gotoxy(t + 0, 17 - t);
			printf("               ");
		}
		gotoxy(t, 24 - t);
		if (t > 0 || t < 0)
		{
			gotoxy(t + 0, 16 - t);
			printf("                                  ");
		}
		if (t > 0 || t < 0)
		{
			gotoxy(15, 16 - t);
			printf("                       ");
		}
		printf("          €‹    ");
		if (t != 0)
		{
			gotoxy(0, 16 - t);
			printf("                                     ");

		}
		a = 1;
	}
	gotoxy(0, 25 - t);
	if (jump != 0) {
		printf("                ");
	}

	else
	if (speed == 40)
	{
		colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); //Changing the colour of ground to white

		/* Graphics Symbols used to create the GROUND beneath the dinosaur*/
		printf("ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ"); // graphic symbols

		for (k = 0; k < 25; k++) // loop used to create a border of the game using graphic symbols
		{
			gotoxy(78, 24 - k);
			printf("€"); // graphics symbol
		}
	}
	delay(speed);  // setting the speed of the dinosaur's movement
}
/* GAME FUNCTION */

void game()  // Function used to display the gameplay
{
	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); // setting the color of the scoreboard to white
	if (x == 73)
	{
		x = 0;
		scr++;
		gotoxy(70, 2);
		printf("     ");
		gotoxy(70, 2);
		printf("%d", scr);  // printing the score when game restarts
		if (speed > 20)
			speed--;
		printClock();
	}
	if (x == 58 && t < 6)
	{
		if (scr == 1)
			max = scr;
		else
		if (max<scr)
		max = scr;
		scr = 0;
		speed = 40;
		gotoxy(36, 8);
		printf("\a Game Over"); // when user loses the game
		gotoxy(70, 2);
		printf("%d", scr);  // printing the score

		// resetting the clock
		millisecond = 0;
		second = 0;
		minute = 0;

		_getch();
		gotoxy(36, 8);
		printf("            ");
		if (max >=scr)
		{

			
			gotoxy(62, 4);
			printf("High Score : %d", max);  // printing the highscore
			scr = 0;


			gotoxy(36, 8);
			printf("         ");
			scr = 0;
		}
	}
}
/*  FUNCTIONS FOR DIFFERENT OBSTACLES */


void cactus() /* FUNCTION FOR CREATING A CACTUS*/

{
	game();

	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN); //Changing the colour of cactus to green

	/* Creating a CACTUS using graphic symbols*/
	gotoxy(74 - x, 20);
	printf("  €  ");
	gotoxy(74 - x, 21);
	printf("€ € € ");

	gotoxy(74 - x, 22);
	printf("€‹€‹€ ");

	gotoxy(74 - x, 23);
	printf("  €    ");

	gotoxy(74 - x, 24);
	printf("  €  ");

	x++;


}
void flower() /* FUNCTION TO CREATE A FLOWER */
{
	game();

	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_RED); // changing the color of flower petals to red

	/* Creating a FLOWER using graphic symbols*/

	gotoxy(74 - x, 20);
	printf("  ‹€‹   ");
	gotoxy(74 - x, 21);
	printf("  €€€  ");
	gotoxy(74 - x, 22);
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN); // changing the color of flower stem to green
	printf(" €‹€‹€ ");
	gotoxy(74 - x, 23);
	printf("   €    ");
	gotoxy(74 - x, 24);
	printf("   €    ");
	x++;
	


}



void bird()  /* FUNCTION TO CREATE A BIRD */


{

	game();
	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_RED | FOREGROUND_GREEN); // changing the color of bird to yellow

	/* Creating a BIRD using graphic symbols */
	gotoxy(73 - x, 20);
	gotoxy(73 - x, 20);
	printf("        ");
	gotoxy(73 - x, 21);
	printf("  ‹‹‹‹  ‹       ");
	gotoxy(73 - x, 22);
	printf(" ‹€‹€€‹ﬂ         ");
	gotoxy(73 - x, 23);
	printf("  €€€€€€€        ");
	gotoxy(73 - x, 24);
	printf("          ");
	x++;


}




void spikes() /* FUNCTION TO CREATE SPIKES */

{

	game();


	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_BLUE | FOREGROUND_GREEN); //Changing the colour of spikes to light blue

	/* Creating SPIKES using graphic symbols*/
	gotoxy(73 - x, 24);
	printf("€‹€‹€ ");
	x++;

}

void cone() /* FUNCTION TO CREATE A TRAFFIC CONE */

{
	game();
	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_RED); //Changing the colour of cone to red

	gotoxy(73 - x, 22);
	printf("  €€ ");
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // changing the color of cone to white

	gotoxy(73 - x, 23);
	printf(" €€€€ ");
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_RED); //Changing the colour of cone back to red
	gotoxy(73 - x, 24);
	printf("€€€€€€ ");


	x++;

}

/* FUNCTIONS FOR PLACING THE OBTACLES IN THE GAME */

void OB1()  /* PLACING THE BIRD OBSTACLE */
{
	while (!_kbhit()) // while the user doesn't hit any key
	{
		printClock();
		ds(0, 40);  // dinosaur moves
		bird(); // bird is placed 
	}
	ch = _getche();  // 'getche' is used so there is no need to press enter after hitting space
	if (ch == ' ')  // when the user hits space
	{
		printClock();

		for (i = 0; i < 10; i++)
		{
			printClock();
			ds(1, 40); // dinosaur jumps
			bird();
		}
		for (i = 0; i < 10; i++)
		{
			printClock();
			ds(2, 40); // dinosaur comes back to the ground
			bird();
		}
		printClock();

	}

}
void OB2() /* PLACING THE TRAFFIC CONE OBSTACLE */
{
	while (!_kbhit())
	{
		printClock();

		ds(0, 40);
		cone();


	}
	ch = _getche();
	if (ch == ' ')
	{
		printClock();

		for (i = 0; i < 10; i++)
		{
			printClock();
			ds(1, 40);
			cone();
		}
		for (i = 0; i < 10; i++)
		{
			printClock();
			ds(2, 40);
			cone();
		}
		printClock();

	}

}
void OB3() /* PLACING THE FLOWER OBSTACLE */
{
	while (!_kbhit())
	{
		printClock();

		ds(0, 40);
		flower();

	}
	ch = _getche();
	if (ch == ' ')
	{
		printClock();

		for (i = 0; i < 10; i++)
		{
			printClock();


			ds(1, 40);
			flower();
		}
		for (i = 0; i < 10; i++)
		{
			printClock();


			ds(2, 40);
			flower();
		}
		printClock();
	}

}
void OB4() /* PLACING THE CACTUS OBSTACLE */
{
	while (!_kbhit())
	{
		printClock();

		ds(0, 40);
		cactus();

	}
	ch = _getche();
	if (ch == ' ')
	{
		printClock();

		for (i = 0; i < 10; i++)
		{
			printClock();


			ds(1, 40);
			cactus();
		}
		for (i = 0; i < 10; i++)
		{
			printClock();


			ds(2, 40);
			cactus();
		}
		printClock();

	}

}

void OB5() /* PLACING THE SPIKES OBSTACLES */
{
	while (!_kbhit())
	{
		printClock();

		ds(0, 40);
		spikes();

	}
	ch = _getche();
	if (ch == ' ')
	{
		printClock();

		for (i = 0; i < 10; i++)
		{
			printClock();


			ds(1, 40);
			spikes();
		}
		for (i = 0; i < 10; i++)
		{
			printClock();


			ds(2, 40);
			spikes();
		}
		printClock();

	}
}
/* STARTUP MENU */
void startup_choice() // player is given choice whether to start the game or not
{
	printf("******************************************************************************");
	printf("\n\n\n\t\t Would you like to play the T-rex game?\n\t\t  Press 'y' to play and 'x' to Exit");
	printf("\n\n\n\t             PRESS ANY KEY TO GIVE COMMAND ");
	printf("\n\n\n******************************************************************************");
	scanf_s(" %c", &q);
}

void exit_game()
{
	scr = 0;
	HANDLE colour_change;
	colour_change = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour_change, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	system("cls");
	gotoxy(30, 18);
	printf("ARE YOU SURE ? PRESS X TO EXIT OR Y TO CONTINUE PLAYING:");
	scanf_s(" %c", &q);
	system("cls");
}

/* MAIN FUNCTION */

int main()
{
	system("mode con: lines=38 cols=120");     // defining console window size
	startup_choice();                          // calling the sartup_choice function for user to decide
	startup_menu();                            // calling the startup_menu function when user takes the decision


	while (q == 'y')              // while the user hits 'y' key
	{
		score();                  // displaying the scoreboard

		srand(time(NULL));
		int y = rand() % 5 + 1;  // calling the functions randomly


		switch (y)
		{
		case 1:

		{
				  OB1();                // if case is 1, bird obstacle is placed in game
				  break; }
		case 2:
		{
				  OB2();                // if case is 2, cone obstacle is placed in game
				  break;
		}
		case 3:
		{
				  OB3();                // if case is 3, flower obstacle is placed in game
				  break;
		}
		case 4:
		{
				  OB4();               // if case is 4, cactus obstacle is placed in game
				  break;
		}
		case 5:
		{
				  OB5();               // if case is 5, spikes obstacle is placed in game
				  break;
		}
		}
		top++;

		if (ch == 'x')

		{
			exit_game();   // if user hit 'x', user is given choice 
		}
		if (q != 'y')  // if the user exits the game
		{
			system("cls");
			gotoxy(48, 20);
			printf("GOODBYE");
			break;
		}
	}
	if (q != 'y')
	{
		system("cls");

		gotoxy(48, 20);
		printf("GOODBYE");
	}
	_getch();
	return 0;
}