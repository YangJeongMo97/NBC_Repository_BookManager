#pragma once
#include "Book.h"
#include <vector>
#include <algorithm>

class BookManager
{
private:
	vector<Book> books;

public:
	BookManager() {}
	~BookManager() {}

	//책 추가
	void addBook(string title, string author) {
		Book newBook(title, author);
		books.push_back(newBook);
	}

	//모든 책 출력
	void displayAllBooks()
	{
		if (books.size() == 0)
		{
			cout << "책이 없습니다." << endl;
			return;
		}

		cout << "BookList" << endl;
		for (int i = 0; i < books.size(); i++)
		{
			cout.width(2);
			cout.fill('0');
			cout << i + 1 << ". ";
			printList(books[i].GetTitle(), books[i].GetAuthor());
		}
	}

	//제목으로 검색
	void searchByTitle(string title)
	{
		int count = 0;
		cout << "Title Search Result" << endl;

		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].GetTitle().find(title) != string::npos)
			{
				cout.width(2);
				cout.fill('0');
				cout << ++count << ". ";
				printList(books[i].GetTitle(), books[i].GetAuthor());
			}
		}
		if (count == 0) cout << "찾으시는 제목의 책이 없습니다." << endl;
	}

	//작가로 검색
	void searchByAuthor(string author)
	{
		int count = 0;
		cout << "Author Search Result" << endl;

		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].GetAuthor().find(author) != string::npos)
			{
				cout.width(2);
				cout.fill('0');
				cout  << ++count << ". ";
				printList(books[i].GetTitle(), books[i].GetAuthor());
			}
		}
		if (count == 0) cout << "찾으시는 작가의 책이 없습니다." << endl;
	}

	//등록된 모든 책 리턴
	vector<Book> GetAllBook() const { return books; }

	//출력 양식
	void printList(const string inTitle, const string inAuthor) {
		cout.width(40);
		cout.fill(' ');
		cout << left << inTitle;
		cout << right << " | " << inAuthor << endl;
	}
};