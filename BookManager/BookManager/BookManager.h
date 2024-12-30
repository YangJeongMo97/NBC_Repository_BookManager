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

	//å �߰�
	void addBook(string title, string author) {
		Book newBook(title, author);
		books.push_back(newBook);
	}

	//��� å ���
	void displayAllBooks()
	{
		if (books.size() == 0)
		{
			cout << "å�� �����ϴ�." << endl;
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

	//�������� �˻�
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
		if (count == 0) cout << "ã���ô� ������ å�� �����ϴ�." << endl;
	}

	//�۰��� �˻�
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
		if (count == 0) cout << "ã���ô� �۰��� å�� �����ϴ�." << endl;
	}

	//��ϵ� ��� å ����
	vector<Book> GetAllBook() const { return books; }

	//��� ���
	void printList(const string inTitle, const string inAuthor) {
		cout.width(40);
		cout.fill(' ');
		cout << left << inTitle;
		cout << right << " | " << inAuthor << endl;
	}
};