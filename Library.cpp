#include "Library.h"

void Library::add_publication_to_back(TInfo shptr)
{
	publicationVector.push_back(std::move(shptr));
}

void Library::sort()
{
	std::sort(publicationVector.begin(), publicationVector.end(), [](const TInfo& uptr1, const TInfo& uptr2) {return uptr1->compare(*uptr2) == -1; });
}

std::vector<TInfo>::iterator Library::begin()
{
	return publicationVector.begin();
}

std::vector<TInfo>::iterator Library::end()
{
	return publicationVector.end();
}

std::ostream& operator<<(std::ostream& out, const Library& obj)
{
	// перебор коллекции
	for (const TInfo& shptr : obj.publicationVector)
		out << shptr->to_string() << '\n'; // вывод информации об объекте с помощью метода to_string()
	return out;
}
