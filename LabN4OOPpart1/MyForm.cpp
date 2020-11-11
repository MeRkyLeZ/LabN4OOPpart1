#include "MyForm.h"
#include <Windows.h>

using namespace LabN4OOPpart1;

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
};

class Repository {	// ���������
protected:
	CCircle** arr;	// ������ ���������
	unsigned int size;	// ������ �������
	int count;	// ���������� ���������
public:
	Repository() {	// �����������
		size = 0;
		count = 0;
		arr = new CCircle * [size];
		init(0);
	}
	Repository(unsigned int size) {	// �����������
		this->size = size;
		count = 0;
		arr = new CCircle * [size];
		init(0);
	}
	Repository(const Repository& rep) {	// ����������� �����������
		arr = new CCircle * [rep.size];
		this->size = rep.size;
		this->count = rep.count;
		for (int i = 0; i < size; ++i) {
			arr[i] = new CCircle(*rep.arr[i]);
		}
	}
	virtual ~Repository() {	// ����������
		for (int i = 0; i < size; ++i) {
			if (!isNull(i))
				delete arr[i];
			arr[i] = 0;
		}
		delete[] arr;
	}
	void addObject(CCircle* point) {	// ���������� ��������
		int pos = 0;
		while (!isNull(pos) && pos < size) {
			pos++;
		}
		if (pos == size) {
			size++;
			CCircle** tmp = new CCircle * [size];
			for (int i = 0; i < size - 1; ++i) {
				tmp[i] = arr[i];
			}
			delete[] arr;
			arr = tmp;
		}
		arr[pos] = point;
		count++;
	}
	void delObject(unsigned int pos) {	// �������� �������
		delete arr[pos];
		arr[pos] = 0;
		count--;
	}
	void setObject(unsigned int pos, CCircle* point) {	// ��������� ��������
		if (pos >= size) {
			int oldsize = size;
			size = pos + 1;
			CCircle** tmp = new CCircle * [size];
			for (int i = 0; i < size - 1; ++i) {
				tmp[i] = arr[i];
			}
			delete[] arr;
			arr = tmp;
			init(oldsize);
		}
		delete arr[pos];
		arr[pos] = point;
	}
	CCircle& getObject(unsigned int pos) {	// ��������� ��������
		return *arr[pos];
	}
	int getCount() {	// ��������� ���������� ��������
		return count;
	}
	int getSize() {	// ��������� ������� ���������
		return size;
	}
	bool isNull(unsigned int pos) {	// �������� �������
		if (arr[pos] == 0)
			return true;
		return false;
	}
private:
	void init(int start) {	// ������������� ���������
		for (int i = start; i < size; ++i) {
			arr[i] = 0;
		}
	}
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}