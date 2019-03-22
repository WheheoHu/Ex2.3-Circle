#include "CoordinateXY.h"

CoordinateXY::CoordinateXY(int coorX, int coorY)
{
	CoordinateX = coorX;
	CoordinateY = coorY;
	point_num = 0;
}

CoordinateXY::CoordinateXY(int coorX, int coorY, int Color)
{
	CoordinateX = coorX;
	CoordinateY = coorY;
	point_color = Color;
	point_num = 0;
}

CoordinateXY::CoordinateXY()
{
	point_num = 0;
}

CoordinateXY::~CoordinateXY()
{
}

void CoordinateXY::setX(int x)
{
	CoordinateX = x;
}

void CoordinateXY::setY(int y)
{
	CoordinateY = y;
}

void CoordinateXY::plusnum()
{
	point_num++;
}

void CoordinateXY::setColor(int iColor)
{
	point_color = iColor;
}

int CoordinateXY::getColor()
{
	return point_color;
}
