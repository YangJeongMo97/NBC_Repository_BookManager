#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book
{
protected:
	string title;
	string author;

public:
	Book() : title("NULL"), author("NULL") {}
	Book(const string inTitle, const string inAuthor) : title(inTitle), author(inAuthor) {}
	~Book() {}

	//��� ���� ���� �����ϱ� ���� Get�Լ�
	string GetTitle() const { return title; }
	string GetAuthor() const { return author; }
};

