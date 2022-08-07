#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	int width = 800;
	int height = 800;

	// Initialize GLFW
	glfwInit();
	
	// Tell GLFW what version of OpenGL we are using, 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile only modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Tell GLFW we can resizing the window
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	
	//Create Window
	GLFWwindow* window = glfwCreateWindow(width, height, "SimpleOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	while (!glfwWindowShouldClose(window)) {
		// Get the size of the actual frame buffer
		glfwGetFramebufferSize(window, &width, &height);
		// Specify the viewport of OpenGL in the Window
		glViewport(0, 0, width, height);

		// Set window color to blue
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}