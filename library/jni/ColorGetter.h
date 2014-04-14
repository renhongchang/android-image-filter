/*
 * ColorGetter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef COLORGETTER_H_
#define COLORGETTER_H_

#define COLOR_UPPER_BOUND 255.0
#define COLOR_LOWER_BOUND 0.0

static inline int ARGB2Color(int alpha, int r, int g, int b) {
	return alpha << 24 | r << 16 | g << 8 | b;
}

static inline int RGB2Color(int r, int g, int b) {
	return 255 << 24 | r << 16 | g << 8 | b;
}

class Color {
public:
	Color():color(-1) {}
	Color(int color):
		color(color) {}
	Color(int r, int g, int b) { color = RGB2Color(r, g, b); }
	int alpha() { return (color & 0xFF000000) >> 24; }
	int R() { return (color & 0x00FF0000) >> 16; }
	int G() { return (color & 0X0000FF00) >> 8; }
	int B() { return (color & 0x000000FF); }
	int grayScale() {
		return (R() + G() + B()) / 3;
	}
	int getColor() { return color; }
	bool isInvalid() { return color == -1; }
private:
	int color;
};



#endif /* COLORGETTER_H_ */