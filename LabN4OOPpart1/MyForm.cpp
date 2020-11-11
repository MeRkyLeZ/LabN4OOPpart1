#include "MyForm.h"
#include <Windows.h>

using namespace LabN4OOPpart1;

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
};

class Repository {	// Хранилище
protected:
	CCircle** arr;	// Массив элементов
	unsigned int size;	// Размер массива
	int count;	// Количество элементов
public:
	Repository() {	// Конструктор
		size = 0;
		count = 0;
		arr = new CCircle * [size];
		init(0);
	}
	Repository(unsigned int size) {	// Конструктор
		this->size = size;
		count = 0;
		arr = new CCircle * [size];
		init(0);
	}
	Repository(const Repository& rep) {	// Конструктор копирования
		arr = new CCircle * [rep.size];
		this->size = rep.size;
		this->count = rep.count;
		for (int i = 0; i < size; ++i) {
			arr[i] = new CCircle(*rep.arr[i]);
		}
	}
	virtual ~Repository() {	// Деструктор
		for (int i = 0; i < size; ++i) {
			if (!isNull(i))
				delete arr[i];
			arr[i] = 0;
		}
		delete[] arr;
	}
	void addObject(CCircle* point) {	// Добавление элемента
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
	void delObject(unsigned int pos) {	// Удаление объекта
		delete arr[pos];
		arr[pos] = 0;
		count--;
	}
	void setObject(unsigned int pos, CCircle* point) {	// Изменение элемента
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
	CCircle& getObject(unsigned int pos) {	// Получение элемента
		return *arr[pos];
	}
	int getCount() {	// Получение количества объектов
		return count;
	}
	int getSize() {	// Получение размера хранилища
		return size;
	}
	bool isNull(unsigned int pos) {	// Проверка наличия
		if (arr[pos] == 0)
			return true;
		return false;
	}
private:
	void init(int start) {	// Инициализация элементов
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