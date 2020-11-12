#pragma once

class CCircle {	// ������
protected:
	int x, y, R;
public:
	CCircle() {	// �����������
		x = 0;
		y = 0;
		R = 0;
	}
	CCircle(int x, int y, int R) {	// �����������
		this->x = x;
		this->y = y;
		this->R = R;
	}
	CCircle(const CCircle& circle) {	// ����������� �����������
		this->x = circle.x;
		this->y = circle.y;
		this->R = circle.R;
	}
	virtual ~CCircle() {	// ����������

	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getR() {
		return R;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
};