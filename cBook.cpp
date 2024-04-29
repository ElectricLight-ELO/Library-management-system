#include "cBook.h"

Book::Book(string nam, sAuthor auth)
{
	name = nam;
	author = auth;
}

string Book::GetName()
{
	return name;
}

Book::sAuthor Book::GetAuthor()
{
	return author;
}

int Book::GetInfoTaking()
{
	return taked;
}

Book::DateReceiv Book::GetDateReceiv()
{
	return dateRec;
}

Book::DateReturn Book::GetDateReturn()
{
	return dateRet;
}
