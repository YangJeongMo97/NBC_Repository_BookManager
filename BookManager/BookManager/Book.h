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

	//멤버 변수 값에 접근하기 위한 Get함수
	string GetTitle() const { return title; }
	string GetAuthor() const { return author; }
};

