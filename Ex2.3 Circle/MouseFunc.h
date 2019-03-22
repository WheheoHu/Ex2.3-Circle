#pragma once
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WHITE 0
#define RED 1
#define GREEN 2
#define	BLUE 3
bool creak = false;

//鼠标操作，将坐标传递给cooxy
void mouseProcess(int button, int state, int x, int y);

void mouseProcess(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		creak = true;
		setXY(x, WINDOW_HEIGHT - y);
	}
	glutPostRedisplay();

}

