/*
9.7
Implement the "paint fill" function that one might see on many image editing
programs. That is, given a screen (represented by a two-dimensional array of
colors), a point, and a new color, fill in the surrounding area until the color
changes from the original color.
*/

#include <iostream>

struct Point {
	int x;
	int y;
	Point(int x, int y) { this->x = x; this->y = y; }
};
	
class Solution {
public:
	void fill(vector<vector<int> >&screen, int width, int height, Point p, vector<vector<int> >&visited, int origcolor, int color) {
		vector<Point> pvector;
		pvector.push_back(Point(p.x-1, p.y));
		pvector.push_back(Point(p.x+1, p.y));
		pvector.push_back(Point(p.x, p.y+1));
		pvector.push_back(Ponit(p.x, p.y-1));
			
		for (int i = 0; i<pvector.size(); i++) {	
			Point tmp = pvector[i];
			if (tmp.x >= 0 && tmp.x <height && tmp.y >=0 && tmp.y < width && 0 == visited[tmp.x][tmp.y] && origcolor == screen[tmp.x][tmp.y]) {
				screen[tmp.x][tmp.y] = color;
				visited[tmp.x][tmp.y] = 1;
				fill(screen, width, height, tmp, visited, origcolor, color);
			}
		}
			
	}
 
	void paint_fill(vector<vector<int> > &screen, Point p, int color) {
		if (0 == screen.size()) return;
		int width = screen[0].size();
		int height = screen.size();
		if (p.x >= height || p.x < 0) return;
		if (p.y >= width || p.y < 0) return;
		if (color == screen[p.x][p.y]) return;
		vector<vector<int> > visited(height, vector<int>(width, 0));
		visited[p.x][p.y] = 1;
		fill(screen, width, height, p, visited, screen[p.x][p.y], color);
	}
		
};
