#include "cUser.h"

User::User(sUs_initials auth)
{
	initials = auth;
}

User::sUs_initials User::retName()
{
	return initials;
}

vector<Book>& User::retBooks()
{
	return booksGoted;
}

void User::putBook(Book cc)
{
	booksGoted.push_back(cc);
}
