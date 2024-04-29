#pragma once
#include "imports.h"
#include "cBook.h"
class User
{
public:
	struct sUs_initials
	{
		string name;
		string second_name;
	};
	User() = default;
	User(sUs_initials author);

	sUs_initials retName();
	vector<Book> retBooks();

private:
	sUs_initials initials;
	vector<Book> books = vector<Book>();
};