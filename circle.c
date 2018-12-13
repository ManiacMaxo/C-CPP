#include <stdio.h>
#include <math.h>

struct circle_t {
	int r;
	int center_x;
	int center_y;
};

float circleCircumference(struct circle_t circle) {
	return 2 * M_PI * circle.r;
}

float circleArea(struct circle_t circle) {
	return M_PI * circle.r * circle.r;
}

int main() {
	struct circle_t circle;
	

	return 0;
}