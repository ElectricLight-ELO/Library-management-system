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
        datePart.push_back(std::stoi(part)); // Преобразование строки в int
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
        if (usrs[i].retName().id == idUser) // поиск пользователя в базе
        {
            if (existBook(bk, bok))  // поиск книги и проверка забрал ли её кто-то(2 в 1)
            {
                for (int j = 0; j < bk.size(); j++)
                {
                    if (bk[j].GetName() == bok.GetName())  // ищем книгу по массиву, опираясь на имя
                    {
                        bk[j].PutDate(dateRec, dateRet);  // установка даты выдачи/возврата
                        usrs[i].putBook(bk[j]); // помещаем найденую книгу к пользователю
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

void OccupiedBook(vector<User>& usrs)
{
    for (int i = 0; i < usrs.size(); i++)
    {
        vector<Book> bookGoted = usrs[i].retBooks();
        if (bookGoted.size() > 0)
        {
            cout << "Пользователь: ID- " << usrs[i].retName().id << " Фамилия: " << usrs[i].retName().second_name << endl;
            for (Book t : bookGoted)
            {
                cout  << "Название: " << t.GetName() << "\nАвтор: " << t.GetAuthor().name << " " << t.GetAuthor().second_name << "\n";
                cout << "Дата выдачи: " << t.GetDateReceiv().day << "." << t.GetDateReceiv().month << "." << t.GetDateReceiv().year <<"\n";
                cout << "Дата возврата: " << t.GetDateReturn().day << "." << t.GetDateReturn().month << "." << t.GetDateReturn().year << "\n";
            }

            cout << endl << endl;
        }
    }
}

bool RemoveBook(vector<Book>& bk, Book& bok)
{
    for (int i = 0; i < bk.size(); i++)
    {
        if (bk[i].GetName() == bok.GetName())
        {
            bk.erase(bk.begin() + i);
            return true;
        }
    }

    return false;
}

bool RemoveDate(vector<Book>& bk, Book& bok)
{
    for (int i = 0; i < bk.size(); i++)
    {
        if (bk[i].GetName() == bok.GetName())
        {
            bk[i].RemoveDate();
            return true;
        }
    }

    return false;
}
//bool is_date_valid(const std::string& str) {
//    std::regex pattern("^\\d{2}\\.\\d{2}\\.\\d{2}$");
//    return std::regex_match(str, pattern);
//}

bool is_date_valid(const std::string& str) {
    if (str.size() != 8) {
        return false;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (i == 2 || i == 5) {
            if (str[i] != '.') {
                return false;
            }
        }
        else {
            if (!isdigit(str[i])) {
                return false;
            }
        }
    }

    return true;
}

bool RemoveBookOnUser(vector<User>& usrs, vector<Book>& bk, Book& bok)
{
    if (!existBook(bk, bok))
    {
        for (int i = 0; i < usrs.size(); i++)
        {
            vector<Book>& books = usrs[i].retBooks();
            for (int c = 0; c < books.size(); c++)
            {
                if (books[c].GetName() == bok.GetName())
                {
                    RemoveBook(books, books[c]);
                    RemoveDate(bk, bok);
                }
            }
        }
    }

    return false;
}