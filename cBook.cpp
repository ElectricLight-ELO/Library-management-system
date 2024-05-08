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

void Book::PutDate(DateReceiv dRc, DateReturn dRt)
{
	dateRec = dRc;
	dateRet = dRt;
	taked++;
}

void Book::RemoveDate()
{
	DateReceiv d1;
	DateReturn d2;
	d1.day = 0;
	d1.month = 0;
	d1.year = 0;
	d2.day = 0;
	d2.month = 0;
	d2.year = 0;

	dateRec = d1;
	dateRet = d2;
}

Book::DateReceiv Book::GetDateReceiv()
{
	return dateRec;
}

Book::DateReturn Book::GetDateReturn()
{
	return dateRet;
}
