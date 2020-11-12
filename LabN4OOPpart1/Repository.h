#pragma once
#include "CCircle.h"
#define nameObject CCircle	// Имя объекта

class Repository {	// Хранилище
protected:
	nameObject** arr;	// Массив элементов
	unsigned int size;	// Размер массива
	int count;	// Количество элементов
public:
	Repository() {	// Конструктор
		size = 0;
		count = 0;
		arr = new nameObject * [size];
		init(0);
	}
	Repository(unsigned int size) {	// Конструктор
		this->size = size;
		count = 0;
		arr = new nameObject * [size];
		init(0);
	}
	Repository(const Repository& rep) {	// Конструктор копирования
		arr = new nameObject * [rep.size];
		this->size = rep.size;
		this->count = rep.count;
		for (int i = 0; i < size; ++i) {
			arr[i] = new nameObject(*rep.arr[i]);
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
	void addObject(nameObject* point) {	// Добавление элемента
		int pos = 0;
		while (!isNull(pos) && pos < size) {
			pos++;
		}
		if (pos == size) {
			size++;
			nameObject** tmp = new nameObject * [size];
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
			nameObject** tmp = new nameObject * [size];
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
	nameObject& getObject(unsigned int pos) {	// Получение элемента
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