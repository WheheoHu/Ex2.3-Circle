#pragma once
class CoordinateXY
{
public:
	CoordinateXY(int coorX,int coorY);
	CoordinateXY(int coorX, int coorY,int Color);
	CoordinateXY();
	~CoordinateXY();
	void setX(int x);
	void setY(int y);
	void plusnum();
	void setColor(int iColor); 

	//获得x坐标
	int getCoorX() {
		
		return CoordinateX;
	}

	//获得Y坐标
	int getCoorY() {
		return CoordinateY;
	}

	int getpointnum() {
		return point_num;
	}

	int getColor();
	

private:
	int CoordinateX;
	int CoordinateY;
	int point_num;
	int point_color;
};

