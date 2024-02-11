#include "isometric.hpp"

std::vector<int> worldToIzoGrid(float x, float z, float y, int width, int height) {
	int ix = (int)(x * 0.5 * width + z * -0.5 * width);
	int iy = (int)(x * 0.25 * height + z * 0.25 * height - y*height/2);
	int h = (int)(-y*height);
	std::vector<int> ret = {ix, h, iy};
	return ret;
}
