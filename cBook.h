#pragma once
#include "imports.h"

class Book
{
public:
	struct sAuthor
	{
		string name;
		string second_name;
	};
	struct DateReceiv
	{
		int day = 0;
		int month = 0;
		int year = 0;
	};
	struct DateReturn
	{
		int day = 0;
		int month = 0;
		int year = 0;
	};
	Book() = default;
	Book(string nam, sAuthor auth);
	string GetName();
	sAuthor GetAuthor();
	int GetInfoTaking();

	void PutDate(DateReceiv dRc, DateReturn dRt);
	void RemoveDate();
	DateReceiv GetDateReceiv();
	DateReturn GetDateReturn();
private:
	string name;
	sAuthor author;
	int taked = 0;

	DateReceiv dateRec;
	DateReturn dateRet;
};