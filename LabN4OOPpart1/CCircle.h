#pragma once

class CCircle {	// ������
protected:
	double x, y, R;
public:
	CCircle() {	// �����������
		x = 0;
		y = 0;
		R = 0;
	}
	CCircle(double x, double y, double R) {	// �����������
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
	void Paint() {

	}
};