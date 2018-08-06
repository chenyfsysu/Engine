#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

void render(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0, .5);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(-.5, -.5);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(.5, -.5);
	}
	glEnd();
}

int start()
{
	GLFWwindow* win;
	if (!glfwInit()) {
		return -1;
	}
	win = glfwCreateWindow(640, 480, "OpenGL Base Project", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
	}
	if (!glewInit())
	{
		return -1;
	}
	glfwMakeContextCurrent(win);
	while (!glfwWindowShouldClose(win)) {
		render();
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwTerminate();

	return 0;
}

int main()
{
	start();
}