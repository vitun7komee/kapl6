#pragma once
#include <iostream> 
#include <fstream>
#include <functional>
#include <memory>
#include <vector>
#include <algorithm>

#include "Publication.h"

// в списке будут хранится умные указатели shared_ptr на родительский класс, но по факту мы будем хранить указатели на дочерние
using TInfo = std::shared_ptr<Publication>;

class Library
{
private:
	std::vector<TInfo> publicationVector; // вектор умных указателей на публикации (а на самом деле на книги и журналы)
	std::string name;
public:
	Library(std::string name="") : name(name) {}

	// метод добавления публикации в конец
	void add_publication_to_back(TInfo shptr);

	// метод сортировки (по полу в данном случае)
	void sort();

	// методы получения итераторов на начало и конец списка
	std::vector<TInfo>::iterator begin();
	std::vector<TInfo>::iterator end();

	// оператор вывода в консоль/файл
	friend std::ostream& operator<<(std::ostream& out, const Library& obj);
};

