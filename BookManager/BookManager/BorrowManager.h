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
				cout << "\'" << title << "\'���� �뿩�� �����߽��ϴ�. (" << --currentStock[title] << "/" << stock[title] << ")" << endl;
			}
			else cout << "�ش� å�� ��� �뿩���Դϴ�." << endl;
		}
		else
		{
			cout << "�ش� å�� ã�� �� �����ϴ�." << endl;
		}
	}

	void returnBook(string title) {
		if (stock.find(title) != stock.end())
		{
			if (currentStock[title] < stock[title])
			{
				cout << "\'" << title << "\'������ �ݳ��Ͽ����ϴ�." << endl;
				currentStock[title]++;
			}
			else cout << "���� �ý��� �� �ش� ������ �ִ� �Ǽ��� �Ѿ����ϴ�. �ݳ� ��û�� �ݷ��մϴ�." << endl;
		}
		else
		{
			cout << "�ش� å�� ���� ������ ������ �ƴմϴ�. ������ �ùٸ��� �ԷµǾ����� Ȯ�����ּ���." << endl;
		}
	}

	void displayStock() {
		cout << "Stock List" << endl;
		for (auto book : currentStock)
		{
			if (book.second <= 0) continue;
			cout.width(40);
			cout << left << book.first;
			cout << right << "\t���� ���� : " << book.second << endl;
		}
	}
};

