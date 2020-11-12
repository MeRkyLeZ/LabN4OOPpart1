#pragma once

class CCircle {	// Объект
protected:
	int x, y, R;
public:
	CCircle() {	// Конструктор
		x = 0;
		y = 0;
		R = 0;
	}
	CCircle(int x, int y, int R) {	// Конструктор
		this->x = x;
		this->y = y;
		this->R = R;
	}
	CCircle(const CCircle& circle) {	// Конструктор копирования
		this->x = circle.x;
		this->y = circle.y;
		this->R = circle.R;
	}
	virtual ~CCircle() {	// Деструктор

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