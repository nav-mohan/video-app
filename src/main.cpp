#include <stdio.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv){
	printf("Heeeey Wurrrrlllld\n");
	GLFWwindow* window;
	if(!glfwInit()){
		printf("No glfwInit()\n");
		return 1;
	}

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window){
		printf("Couildn't create window");
		return 1;
	}
	
        // MAKE A BUFFER FOR HOLDING 100*100 RGBs
	unsigned char* data = new unsigned char[100*100*3];
	for (int y = 0; y < 100; ++y){
		for (int x = 0; x < 100; ++x){
			data[y*100*3 + x*3    ] = 0xff;
			data[y*100*3 + x*3 + 1] = 0x00;
			data[y*100*3 + x*3 + 2] = 0x00;
		}
	}

	// WINDOW STAY OPEN
	glfwMakeContextCurrent(window);
	while(!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);

		glfwWaitEvents();
	}

	return 0; 
}
