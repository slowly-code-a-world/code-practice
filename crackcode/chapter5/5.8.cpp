/*
5.8 A monochrome screen is stored as a single array of bytes, allowing eight consec-
   utive pixels to be stored in one byte.The screen has width w, where w is divisible
  by 8 (that is, no byte will be split across rows).The height of the screen, of course,
 can be derived from the length of the array and the width. Implement a function
drawHorizontall_ine(byte[] screen, int width, int xl, int x2,
int y) which draws a horizontal line from (xl, y ) t o ( x 2 , y).

*/

#include <iostream>

class Solution {
public:
	void drawHorizontall_line(vector<unsigned char>&screen, int width, int x1, int x2, int y) {
		if (x1 < 0 || x1 >= width) {	
			std::cout << "invalid x1" << std::endl;
			return;
		} 

		if (x2 < 0 || x2 >= width) {
			std::cout << "invalid x2" << std::endl;
			return;
		}

		int height = 8*screen.size()/width;
		if (y < 0 || y >= height) {
			std::cout << "invalid y" << std::endl;
			return;
		}
	
		if (x1 > x2) {
			std::cout << "invalid x1 and x2" << std::endl;
			return;
		}

		int pos1 = x1/8; int left1 = x1%8;
		int pos2 = x2/8; int left2 = x2%8;
		if (pos1 != pos2) {
			for (int i = pos1+1; i<pos2; i++) {
				for (int j = 0; j < 8; j++)
					screen[y*width/8 + i] = 255;
			}
		}

		for (int i = left1; i<8; i++)
			screen[y*width/8 + pos1] = screen[y*width/8 + pos1] | (1 << (7 - i));

		for (int i = 0; i<=left2; i++)
			screen[y*width/8 + pos2] = screen[y*width/8 + pos2] | (1 << (7 - i));	

		return;
	}		
};
