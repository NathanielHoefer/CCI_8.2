/*
	Nathaniel Hoefer
	4/7/2017

	8.2 Robot in a Grid: Cracking the Coding Interview

	Imagine a robot sitting on the upper left corner of grid with
	r rows and c columns. The robot can only move in two directions,
	right and down, but certain cells are "off limits" such that the
	robot cannot step on them. Design an algorithm to find a path for
	the robot from the top left to the bottom right

	Originally solved problem in notepad++ and brought to eclipse to test,
	thats when switched over to char to make reading easier

	Time take to solve: 1.5 hrs

	Items looked up:
	- Multidimensional Vector initialization
	- Integer to String conversion

	Notes:
	[0][x][ ][ ]
	[ ][ ][ ][x]
	[ ][ ][x][ ]
	[x][ ][ ][ ]

	[ ][x][ ][ ][ ][ ][ ][ ]
	[ ][ ][ ][x][ ][ ][ ][ ]
	[ ][ ][ ][x][ ][ ][ ][ ]
	[ ][ ][ ][ ][ ][ ][x][ ]
	[ ][ ][ ][x][x][x][ ][ ]
	[ ][ ][ ][ ][ ][ ][ ][x]
	[ ][ ][ ][x][ ][x][x][ ]
	[ ][ ][ ][ ][ ][ ][ ][ ]

	Loop {
	0. If at end, stop
	1. Robot check if it can go right
	if so, move right
	2. If not, robot check if it can go down
	if so, move down
	3. If not, go back and do opposite step
	}

	Assumptions:
	- Always starting at 0,0
	- Always at least one path
	- Format:
	0's for all empty spaces
	1's for all robot movements
	-1's for all obsticles
 */

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void robotMaze(vector<vector<char> > &maze);
char robotMaze(vector<vector<char> > &maze, int x, int y);
void printMaze(vector<vector<char> > &maze);

static const char OBSTACLE = '~';
static const char BLANK = ' ';
static const char PATH = 'X';

int main() {

	// Initializes maze1
	vector<vector<char> > maze1(4, vector<char>(4, BLANK));
	maze1[0][0] = PATH;
	maze1[0][1] = OBSTACLE;
	maze1[1][3] = OBSTACLE;
	maze1[2][2] = OBSTACLE;
	maze1[3][0] = OBSTACLE;

	cout << "Maze 1:" << endl;
	printMaze(maze1);
	robotMaze(maze1);

	// Initializes maze2
	vector<vector<char> > maze2(8, vector<char>(8, BLANK));
	maze2[0][0] = PATH;
	maze2[0][1] = OBSTACLE;
	maze2[1][3] = OBSTACLE;
	maze2[2][3] = OBSTACLE;
	maze2[3][6] = OBSTACLE;
	maze2[4][3] = OBSTACLE;
	maze2[4][4] = OBSTACLE;
	maze2[4][5] = OBSTACLE;
	maze2[5][7] = OBSTACLE;
	maze2[6][3] = OBSTACLE;
	maze2[6][5] = OBSTACLE;
	maze2[6][6] = OBSTACLE;

	cout << "Maze 2:" << endl;
	printMaze(maze2);
	robotMaze(maze2);
}

// Solves the maze with a robot only able to move right and down
// Preconditions:
void robotMaze(vector<vector<char> > &maze) {
	if (robotMaze(maze, 0, 0) == PATH) {
		cout << "Result:" << endl;
		printMaze(maze);
	} else {
		cout << "Unable to complete" << endl;
	}
}

// Completes the entered maze
//	Returns: PATH if end is found or move made, NULL if invalid option
char robotMaze(vector<vector<char> > &maze, int x, int y) {

	// Base Case
	// 0. If at end, stop
	if (x + 1 == (int) maze[y].size() && y + 1 == (int) maze.size()) {
		return PATH;
	}

	// General Case
	// 1. Robot check if it can go right(wall and obstacle)
	if (x + 1 < (int) maze[y].size() && maze[y][x + 1] != OBSTACLE) {
		maze[y][x + 1] = PATH;
		if (robotMaze(maze, x + 1, y) == PATH) {
			return PATH;
		} else {
			maze[y][x + 1] = BLANK;
		}

	}

	// 2. If not, robot check if it can go down
	if (y + 1 < (int) maze.size() && maze[y + 1][x] != OBSTACLE) {
		maze[y + 1][x] = PATH;
		if (robotMaze(maze, x, y + 1) == PATH) {
			return PATH;
		} else {
			maze[y + 1][x] = BLANK;
		}

	}

	// 3. If not, go back and do opposite step
	return '\0';
}

// Prints out the current maze
void printMaze(vector<vector<char> > &maze) {
	string val;
	for (int i = 0; i < (int) maze.size(); i++) {
		for (int j = 0; j < (int) maze[i].size(); j++) {
			stringstream ss;
			ss << maze[i][j];
			val = ss.str();
			cout << "[" + val + "]";
		}
		cout << endl;
	}
	cout << endl;
}
