#pragma once
#include "imports.h"
#include "cUser.h"
#include "cBook.h"

std::string generateRandomString(size_t length) {
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, 35);
    const std::string allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    std::string randomString;
    randomString.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        randomString += allowedChars[distribution(generator)];
    }

    return randomString;
}
std::vector<std::vector<int>> convertDateStringToVector(const std::string& dateString) {
    std::vector<std::vector<int>> dateVector;
    std::stringstream ss(dateString);
    std::string part;
    int i = 0;

    while (getline(ss, part, '.')) {
        std::vector<int> datePart;
        datePart.push_back(std::stoi(part)); // �������������� ������ � int
        dateVector.push_back(datePart);
        i++;
    }

    return dateVector;
}

void createUser(vector<User>& usrs, User::sUs_initials s)
{
	User newUs(s);

	usrs.push_back(newUs);
}

void createBook(vector<Book>& bk, Book c)
{
    Book newUs(c);

    bk.push_back(newUs);
}
bool existBook(vector<Book>& bk, Book book)
{
    for (int i = 0; i < bk.size(); i++)
    {
        if (bk[i].GetName() == book.GetName())
        {
            if (bk[i].GetDateReceiv().day == 0)
            {
                return true;
            }
            break;
        }
    }

    return false;
}

bool PassBook(vector<User>& usrs, string idUser, vector<Book>& bk, Book& bok, Book::DateReceiv dateRec, Book::DateReturn dateRet)
{
    for (int i = 0; i < usrs.size(); i++)
    {
        if (usrs[i].retName().id == idUser) // ����� ������������ � ����
        {
            if (existBook(bk, bok))  // ����� ����� � �������� ������ �� � ���-��(2 � 1)
            {
                for (int j = 0; j < bk.size(); j++)
                {
                    if (bk[j].GetName() == bok.GetName())  // ���� ����� �� �������, �������� �� ���
                    {
                        bk[j].PutDate(dateRec, dateRet);  // ��������� ���� ������/��������
                        usrs[i].putBook(bk[j]); // �������� �������� ����� � ������������
                        break;
                    }
                }

                return true;
            }
            break;
        }
    }

    return false;
}