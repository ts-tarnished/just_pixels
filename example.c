#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// include just pixels
#define JUST_PIXELS_IMPLEMENTATION
#include "just_pixels.h"

#define WIDTH 800
#define HEIGHT 600

int main (void) {

	// the pixels
	uint32_t *frame_buffer = malloc(WIDTH * HEIGHT * sizeof(uint32_t));
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			uint32_t color = 0xFF0000; //red
			frame_buffer[x + y * WIDTH] = color;
		}
	}


	// create window
	Jup_Window *window = Jup_CreateWindow(WIDTH, HEIGHT, "Window Title", frame_buffer);

	while (!Jup_WindowShouldClose(window)) {
		Jup_DrawPixels(window);
	} 

	Jup_FreeAndClose(window); //also frees frame_buffer

	return 0;
}
