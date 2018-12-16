#include <stdio.h>
#include <math.h>

int circleQuads[4] = {0};

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

void whichQuads(struct circle_t circle) {
	int z = sqrt(pow(circle.center_x, 2) + pow(circle.center_y, 2));
	printf("r = %d, x = %d, y = %d\n", circle.r, circle.center_x, circle.center_y);

	if (z < circle.r) {
		// left & right & top & bot
	} else {
		if (abs(circle.center_x) < circle.r) {
			// left & right
		} else {
			if (circle.center_x > circle.r) {
				// right
			} else {
				// left
			}
		}

		if (abs(circle.center_y) < circle.r) {
			// top & bot
		} else {
			if (circle.center_y > circle.r) {
				// top
			} else {
				// bot
			}
		}
	}

/*
	if (circle.center_x == 0) {
		if (circle.center_y == 0) {
			circleQuads[0] = 1;
			circleQuads[1] = 1;
			circleQuads[2] = 1;
			circleQuads[3] = 1;
		} else {
			if (circle.center_y)
		}
	} else if () {

	} else if (circle.center_x > 0 && circle.center_y > 0) { // Quad 1
		printf("center quadrant 1\n");
		circleQuads[0] = 1;
		if (circle.center_x - circle.r <= 0) { // Quad 2
			circleQuads[1] = 1;
		}
		if (circle.center_y - circle.r <= 0) { // Quad 4
			circleQuads[3] = 1;
		}
		if (z  < circle.r) { // Quad 3
			circleQuads[2] = 1;
		}
	} else if (circle.center_x < 0 && circle.center_y > 0) { // Quad 2
		printf("center quadrant 2\n");
		circleQuads[1] = 1;
		if (circle.center_x + circle.r >= 0) { // Quad 1
			circleQuads[0] = 1;
		}
		if (circle.center_y - circle.r <= 0) { // Quad 3
			circleQuads[2] = 1;
		}
		if (z  < circle.r) { // Quad 4
			circleQuads[3] = 1;
		}
	} else if (circle.center_x < 0 && circle.center_y < 0) { // Quad 3
		printf("center quadrant 3\n");
		circleQuads[2] = 1;
		if (circle.center_x + circle.r >= 0) { // Quad 4
			circleQuads[3] = 1;
		}
		if (circle.center_y + circle.r >= 0) { // Quad 2
			circleQuads[1] = 1;
		}
		if (z  < circle.r) { // Quad 1
			circleQuads[0] = 1;
		}
	} else { // Quad 4
		printf("center quadrant 4\n");
		circleQuads[3] = 1;
		if (circle.center_x - circle.r <= 0) { // Quad 3
			circleQuads[2] = 1;
		}
		if (circle.center_y + circle.r >= 0) { // Quad 1
			circleQuads[0] = 1;
		}
		if (z < circle.r) { // Quad 2
			circleQuads[1] = 1;
		}
	}
	*/
}

int main() {
	short unsigned i;
	struct circle_t circle = {
		.r = 10,
		.center_x = 30,
		.center_y = -20,
	};
	
	whichQuads(circle);
	printf("Quadrants: ");
	for (i=0; i<3; i++) {
		if (circleQuads[i]) {
			printf("%d ", i+1);
		}
	}
	printf("\n");
	return 0;
}
