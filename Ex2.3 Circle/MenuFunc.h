#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "glut.h"
#include "CoordinateXY.h"

using namespace std;

#define WHITE 0
#define RED 1
#define GREEN 2
#define	BLUE 3
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
//����Բ�ĽǶ��������Ƕ�ֵ
#define CIRCLE_POINT_NUM 50
//Բ�İ뾶
#define CIRCLE_R 50.0

static int iColor = WHITE;
static CoordinateXY   coorxy;
vector< CoordinateXY> datapoint;
fstream datafile;

//��ʼ���˵�
void InitMenu();

//����ɫ�Ӳ˵��ص�
void ColorMenu(int MenuID);
void CircleMenu_CB(int MenuID);
//���˵��ص�
void Main_menu(int MenuID);
//��������
void savedata(vector<CoordinateXY> datapoint);
//��ȡData.txt����
void loaddata(fstream &datafile);
//����&��������
void removeall(fstream &datafile);
//��Բ
void RenderACircle(int CiclePointNum);
//����xy����
void setXY(int x, int y);


void setXY(int x, int y) {
	coorxy.setX(x);
	coorxy.setY(y);
	coorxy.setColor(iColor);
	coorxy.plusnum();
	datapoint.push_back(CoordinateXY(x, y, iColor));
}

void InitMenu()
{
	int MainMenu, ColorPointMenu, CircleMenu;

	ColorPointMenu = glutCreateMenu(ColorMenu);
	//glutSetMenu(ColorPointMenu);
	glutAddMenuEntry("White", 0);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("SAVE", 4);
	glutAddMenuEntry("LOAD", 5);
	glutAddMenuEntry("CLEAN ALL!", 6);

	CircleMenu = glutCreateMenu(CircleMenu_CB);
	glutAddMenuEntry("Circle50", 1);
	glutAddMenuEntry("CircleLines", 2);


	MainMenu = glutCreateMenu(Main_menu);
	//glutSetMenu(MainMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddSubMenu("ColorPoint", ColorPointMenu);
	glutAddSubMenu("Circles", CircleMenu);
	glutAddMenuEntry("EXIT", 0);


}



void ColorMenu(int MenuID) {
	switch (MenuID)
	{
	case 0: {
		iColor = WHITE;
		glColor3f(1, 1, 1);
		break;
	}
	case 1: {
		iColor = RED;
		glColor3f(1, 0, 0);
		break;
	}
	case 2: {
		iColor = GREEN;
		glColor3f(0, 1, 0);
		break;
	}
	case 3: {
		iColor = BLUE;
		glColor3f(0, 0, 1);
		break;
	}
	case 4: {
		savedata(datapoint);
		break;
	}
	case 5: {
		loaddata(datafile);
		break;
	}
	case 6: {

		removeall(datafile);
		break;
	}
	}
}

inline void CircleMenu_CB(int MenuID)
{
	switch (MenuID)
	{
	case 1: {
		RenderACircle(CIRCLE_POINT_NUM);
		break;
	}
	}
}

void Main_menu(int MenuID) {
	switch (MenuID)
	{
	case 0: {
		exit(0);
		break; }

	
	}

}



void savedata(vector<CoordinateXY> datapoint)
{
	//remove("Data.txt");
	datafile.open("Data.txt", ios::out | ios::app);
	for (vector<CoordinateXY>::iterator iter = datapoint.begin(); iter != datapoint.end(); iter++)
	{
		datafile << iter->getCoorX() << " " << iter->getCoorY() << " " << iter->getColor() << endl;
	}
	datafile.close();
}

void loaddata(fstream & datafile)
{
	datafile.open("Data.txt", ios::in);
	int coorx;
	int coory;
	int pointcolor;

	while (!datafile.eof())
	{
		datafile >> coorx;
		datafile >> coory;
		datafile >> pointcolor;
		iColor = pointcolor;
		switch (iColor)
		{
		case RED: {
			glColor3f(1, 0, 0);
			break;
		}
		case GREEN: {
			glColor3f(0, 1, 0);
			break;
		}
		case BLUE: {
			glColor3f(0, 0, 1);
			break;
		}
		case WHITE: {
			glColor3f(1, 1, 1);
			break;
		}
		}
		glBegin(GL_POINTS);
		glVertex2i(coorx, coory);
		glEnd();
		glutPostRedisplay();
	}
	datafile.close();
}

void removeall(fstream & datafile)
{
	datafile.open("Data.txt", ios::out);
	datafile.close();
	loaddata(datafile);
	glClear(GL_COLOR_BUFFER_BIT);
}

inline void RenderACircle(int CiclePointNum)
{
	int coorx;
	int coory;
	glPointSize(2);
	glBegin(GL_POINTS);
	for (float angle = 0; angle <= 360; angle += 360. / CiclePointNum)
	{
		coorx = CIRCLE_R * cos(angle) + WINDOW_WIDTH / 2;
		coory = CIRCLE_R * sin(angle) + WINDOW_HEIGHT / 2;
		cout << coorx << " " << coory << endl;
		glVertex2i(coorx, coory);
	}
	glEnd();
	glutPostRedisplay();
}
