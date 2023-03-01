#pragma once
#include <string>

// базовй класс Издание

class Publication
{
protected:
	std::string name, publisher; // название, издательство
	size_t pageCount; // кол-во страниц
public:
	Publication(std::string name = "", std::string publisher = "", size_t pageCount = 0) : name(name), publisher(publisher), pageCount(pageCount) {}

	// геттеры и сеттеры

	std::string get_name() { return name; }
	void set_name(std::string value) { name = value; }

	std::string get_publisher() { return publisher; }
	void set_publisher(std::string value) { publisher = value; }

	size_t get_page_count() { return pageCount; }

	// компоратор для сравнения двух изданий благодаря которой произойдет сортировка по значенимя поля Издательство
	int compare(const Publication& obj) {
		int result = 1;
		if (publisher < obj.publisher)
			result = -1;
		else if (name == obj.name && publisher == obj.publisher)
			result = 0;
		return result;
	}

	// виртуальный метод перевода информации класса в string который в дочерних классах будет перегружен
	virtual std::string to_string() {
		return name + " : " + publisher + " " + std::to_string(pageCount) + "p";
	}
};

