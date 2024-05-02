#include "imports.h"
#include "cControlFunctions.h"
#include "cBook.h"
#include "cUser.h"

vector<User> users = vector<User>();
vector<Book> books = vector<Book>();
/*
Структура кода такова. 
Имеется классы User и Book. User под пользователя(имя, фамка, ид)
Book имеет название, дату выдачи/возврата. Инициалы автора.

Принцип главной(на данный момент функции) Putdata таков, что задача найти и проверить, 
находится ли книга в библиотеке(по дате, дата не мб 0).
Соответственно, дальше надо найти пользователя, и присвоить ему книгу, а ей предварительно выдать дату.
*/
int main()
{
	setlocale(0, "RU");
	while (true)
	{
		int n = 0;
		cout << "Создать нового пользователя 1" << endl;
		cout << "Добавить книгу 2" << endl;
		cout << "Выдать книгу 3" << endl;
		cout << "Вывести всех пользователей 4" << endl;
		cout << "Введите вариант работы: " << endl;
		cin >> n;

		switch (n)
		{
		case 1:
		{
			string n1;
			string n2;
			cout << "Введите имя: " << endl;
			cin >> n1;
			cout << "Введите фамилию: " << endl;
			cin >> n2;
			User::sUs_initials cc;
			cc.name = n1;
			cc.second_name = n2;
			cc.id = generateRandomString(15);
			User tmp(cc);

			createUser(users, cc);
			break;
		}
		case 2:
		{
			string bName;
			string aName;
			string aName2;
			cout << "Впишите название книги: \n";
			cin >> bName;
			cout << "Имя автора: \n";
			cin >> aName;
			cout << "Фамилия автора: \n";
			cin >> aName2;

			Book::sAuthor c;
			c.name = aName;
			c.second_name = aName2;
			Book bo(bName, c);
			createBook(books, bo);
			break;
		}
		case 3:
		{
			string id;
			string bookName;
			string dRc;
			string dRt;
			vector<std::vector<int>> dateRec;
			vector<std::vector<int>> dateRet;
			cout << "Впишите ID пользователя: " << endl;
			cin >> id;
			cout << "Впишите название книги: " << endl;
			cin >> bookName;
			cout << "Впишите дату выдачи: " << endl;
			cin >> dRc;
			cout << "Впишите дату возврата: " << endl;
			cin >> dRt;
			dateRec = convertDateStringToVector(dRc);
			dateRet = convertDateStringToVector(dRt);
			Book::sAuthor author;
			Book tmp(bookName, author);
			Book::DateReceiv Drecv;
			Book::DateReturn Dretu;

			Drecv.day = dateRec[0][0];
			Drecv.month = dateRec[1][0];
			Drecv.year = dateRec[2][0];

			Dretu.day = dateRet[0][0];
			Dretu.month = dateRet[1][0];
			Dretu.year = dateRec[2][0];
			PassBook(users, id, books, tmp, Drecv, Dretu);
			break;
		}
		case 4:
		{
			for (User us : users)
			{
				User::sUs_initials init = us.retName();

				cout << "Фамилия: " << init.second_name << endl;
				cout << "Имя: " << init.name << endl;
				cout << "ID:" << init.id << endl << endl;
			}
			break;
		}
		default:
		{
			break;
		}
			
		}
	}

	
}
