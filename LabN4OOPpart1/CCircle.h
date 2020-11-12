#pragma once

class CCircle {	// Объект
protected:
	double x, y, R;
public:
	CCircle() {	// Конструктор
		x = 0;
		y = 0;
		R = 0;
	}
	CCircle(double x, double y, double R) {	// Конструктор
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
	void Paint() {

	}
};