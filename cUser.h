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
		string id;
	};
	User() = default;
	User(sUs_initials author);

	sUs_initials retName();
	vector<Book> retBooks();
	void putBook(Book cc);
private:
	sUs_initials initials;
	vector<Book> booksGoted = vector<Book>();
};

