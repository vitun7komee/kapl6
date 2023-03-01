#pragma once
#include "Publication.h"

// дочерний класс  нига
class Book : public Publication 
{
private:
	std::string author, genre; // автор, жанр
	bool binding; // переплЄт : 0 - м€гкий, 1 - твЄрдый
public:
	Book(std::string name = "", std::string publisher = "", size_t pageCount = 0, std::string author = "", std::string genre = "", bool binding = 0)
		: Publication(name, publisher, pageCount), author(author), genre(genre), binding(binding) {}

	// геттеры и сеттеры

	std::string get_author() { return author; }

	std::string get_genre() { return genre; }
	void set_genre(std::string value) { genre = value; }

	// false = soft, true = hard
	bool get_binding() { return binding; }

	// перегруженный метод перевода информации в string
	std::string to_string() override {
		return "Book: " + Publication::to_string() + ' ' + author + ' ' + genre + (binding ? " Hard" : " Soft");
	}
};