#pragma once
#include "Book.h"
#include <unordered_map>

class BorrowManager
{
private:
	unordered_map<string, int> stock;
	unordered_map<string, int> currentStock;

public:
	void initializeStock(Book book, int quantity = 3) {
		stock[book.GetTitle()] = quantity;
		currentStock[book.GetTitle()] = quantity;
	}

	void borrowBook(string title){
		if (stock.find(title) != stock.end())
		{
			if (currentStock[title] > 0)
			{
				cout << "\'" << title << "\'도서 대여에 성공했습니다. (" << --currentStock[title] << "/" << stock[title] << ")" << endl;
			}
			else cout << "해당 책은 모두 대여중입니다." << endl;
		}
		else
		{
			cout << "해당 책을 찾을 수 없습니다." << endl;
		}
	}

	void returnBook(string title) {
		if (stock.find(title) != stock.end())
		{
			if (currentStock[title] < stock[title])
			{
				cout << "\'" << title << "\'도서를 반납하였습니다." << endl;
				currentStock[title]++;
			}
			else cout << "전산 시스템 상 해당 도서의 최대 권수를 넘었습니다. 반납 신청을 반려합니다." << endl;
		}
		else
		{
			cout << "해당 책은 저희 도서관 소유가 아닙니다. 정보가 올바르게 입력되었는지 확인해주세요." << endl;
		}
	}

	void displayStock() {
		cout << "Stock List" << endl;
		for (auto book : currentStock)
		{
			if (book.second <= 0) continue;
			cout.width(40);
			cout << left << book.first;
			cout << right << "\t남은 수량 : " << book.second << endl;
		}
	}
};

