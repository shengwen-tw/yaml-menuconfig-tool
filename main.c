#include <string.h>
#include <curses.h>
#include <stdlib.h>

#define BACKGROUND_PAIR 2
#define CONTEXT_PAIR 3
#define SHADE_PAIR 4

void draw_column(int x, int y, char c, int pair, int len)
{
	attron(COLOR_PAIR(pair));
	for(int i = 0; i < len; i++) {
		mvaddch(x + i, y, c);
	}
	attroff(COLOR_PAIR(pair));
}

void draw_line(int x, int y, char c, int pair, int len)
{
	attron(COLOR_PAIR(pair));
	for(int i = 0; i < len; i++) {
		mvaddch(x, y + i, c);
	}
	attroff(COLOR_PAIR(pair));
}

void draw_background(void)
{
	/* title in the background */
	char *title = " proj_config.mk - NCRL Flight Controller configuration";
	attron(COLOR_PAIR(BACKGROUND_PAIR));
	for(int j = 0; j < COLS; j++) {
		if(j < strlen(title)) {
			mvaddch(0, j, title[j]);
		} else {
			mvaddch(0, j, ' ');
		}
	}
	for(int j = 0; j < COLS; j++) {
		if((j == 0) || (j == (COLS - 1))) {
			mvaddch(1, j, ' ');
		} else {
			mvaddch(1, j, '-');
		}
	}
	attroff(COLOR_PAIR(BACKGROUND_PAIR));

	/* left/right background */
	draw_column(2, 0, ' ', BACKGROUND_PAIR, COLS - 2);
	draw_column(2, 1, ' ', BACKGROUND_PAIR, COLS - 2);
	draw_column(2, COLS-1, ' ', BACKGROUND_PAIR, COLS-2);
	draw_column(2, COLS-2, ' ', BACKGROUND_PAIR, 1);
	draw_column(2, COLS-3, ' ', BACKGROUND_PAIR, 1);

	/* lower background */
	draw_line(LINES-2, 2, ' ', BACKGROUND_PAIR, 2);
	draw_line(LINES-1, 2, ' ', BACKGROUND_PAIR, COLS - 3);

	/* dialog lower buttons */
	draw_line(LINES-4, 3, ' ', CONTEXT_PAIR, COLS - 7);

	/* dialog left border */
	draw_column(2, 2, '|', CONTEXT_PAIR, LINES - 4);

	/* dialog right border */
	draw_column(2, COLS-4, '|', CONTEXT_PAIR, LINES - 4);

	/* dialog lower border */
	draw_line(LINES-3, 3, '-', CONTEXT_PAIR, COLS - 7);

	/* dialog botton shadow */
	draw_line(LINES-2, 4, ' ', SHADE_PAIR, COLS - 6);

	/* dialog inner left border */
	draw_column(6, 3, ' ', CONTEXT_PAIR, LINES - 10);
	draw_column(6, 4, '|', CONTEXT_PAIR, LINES - 10);

	/* dialog inner right border */
	draw_column(6, COLS-5, ' ', CONTEXT_PAIR, LINES - 10);
	draw_column(6, COLS-6, '|', CONTEXT_PAIR, LINES - 10);

	/* dialog inner top border */
	draw_line(6, 5, '-', CONTEXT_PAIR, COLS - 11);

	/* dialog inner lower border */
	draw_line(LINES-5, 5, '-', CONTEXT_PAIR, COLS - 11);

	/* dialog title area */
	draw_line(2, 3, '-', CONTEXT_PAIR, COLS - 7);

	/* description area */
	draw_line(3, 3, ' ', CONTEXT_PAIR, COLS - 7);
	draw_line(4, 3, ' ', CONTEXT_PAIR, COLS - 7);
	draw_line(5, 3, ' ', CONTEXT_PAIR, COLS - 7);

	/* options area */
	draw_line(7, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(8, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(9, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(10, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(11, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(12, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(13, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(14, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(15, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(16, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(17, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(18, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(19, 5, ' ', CONTEXT_PAIR, COLS - 11);
	draw_line(20, 5, ' ', CONTEXT_PAIR, COLS - 11);

}

int main(void)
{
	int ch;

	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();

	if (has_colors() == FALSE) {
		endwin();
		printf("your terminal does not support color\n");
		exit(1);
	}

	start_color();
	init_pair(BACKGROUND_PAIR, COLOR_WHITE, COLOR_BLUE);
	init_pair(CONTEXT_PAIR, COLOR_BLACK, COLOR_WHITE);
	init_pair(SHADE_PAIR, COLOR_BLACK, COLOR_BLACK);

	clear();
	draw_background();

	do {
		ch = getch();
	} while ((ch != 'q') && (ch != 'Q'));

	endwin();

	exit(0);
}