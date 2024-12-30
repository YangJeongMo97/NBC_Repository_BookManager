#include "BookManager.h"
#include "BorrowManager.h"
#include <random>
#include <ctime>
#include <conio.h>

void borrowSystem(BorrowManager inBorrowManager);

int main() {
	srand((unsigned int)time(NULL));
	char c;

	BookManager BookManager;

	string inputValue;

	//å �߰� �׽�Ʈ
	BookManager.addBook("�ҳ��� �´�", "�Ѱ�");
	BookManager.addBook("��ó�� ����� �͵�", "Ŭ���� Ű��");
	BookManager.addBook("���� ���� ���� ����", "������");
	BookManager.addBook("��", "�Ѱ�");
	BookManager.addBook("���� ��ȭ�� ���� �а� �A�� ���� ����", "ä����");
	BookManager.addBook("���ǽ��� ��� ���� �����ϴ°�", "���̺�� �̱۸�");
	BookManager.addBook("�ڽ���", "Į ���̰�");
	BookManager.addBook("�̱��� ������", "��ó�� ��Ų��");
	BookManager.addBook("�̵���� ���� ����", "�̵��");
	BookManager.addBook("���ǿ���", "���� �϶�");
	BookManager.addBook("�� �� ��", "�緹�� ���̾Ƹ��");

	//�뿩 ������ ���� �� �ʱ�ȭ
	BorrowManager BorrowManager;

	vector<Book> BookList = BookManager.GetAllBook();

	for (int i = 0; i < BookList.size(); i++)
	{
		BorrowManager.initializeStock(BookList[i], rand() % 4 + 3);
	}

BOOKLIST:
	system("cls");

	//���� ����Ʈ ��� �׽�Ʈ
	cout << "------------------------------------------------------------------------------" << endl;
	BookManager.displayAllBooks();
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "1. å �̸����� �˻� | 2. �۰� �̸����� �˻� | 3. �뿩 | AnyKey. ����" << endl;

	c = _getch();

	system("cls");
	cout << "------------------------------------------------------------------------------" << endl;
	BookManager.displayAllBooks();
	cout << "------------------------------------------------------------------------------" << endl;

	switch (c)
	{
	case '1':
		cout << "�˻��� å�� ������ �Է��ϼ���. : ";
		getline(cin, inputValue);					//����(����)�� ���Խ�Ű�� ����
		system("cls");

		//���� �˻� �׽�Ʈ
		cout << "------------------------------------------------------------------------------" << endl;
		BookManager.searchByTitle(inputValue);
		cout << "------------------------------------------------------------------------------" << endl;

		_getch();
		goto BOOKLIST;
	case '2':
		cout << "�˻��� �۰��� �̸��� �Է��ϼ���. : ";
		getline(cin, inputValue);
		system("cls");

		//�۰� �˻� �׽�Ʈ
		cout << "------------------------------------------------------------------------------" << endl;
		BookManager.searchByAuthor(inputValue);
		cout << "------------------------------------------------------------------------------" << endl;

		_getch();
		goto BOOKLIST;
	case '3':
		borrowSystem(BorrowManager);
		goto BOOKLIST;
	default:
		break;
	}
	
	return 0;
}

void borrowSystem(BorrowManager inBorrowManager)
{
	system("cls");

BORROW:
	//�뿩 ���� ����Ʈ ��� �׽�Ʈ
	cout << "------------------------------------------------------------------------------" << endl;
	inBorrowManager.displayStock();
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "1. �뿩 ��û | 2. �ݳ� ��û | AnyKey. ���� �޴�" << endl;

	char c = _getch();
	string inputValue;

	system("cls");

	cout << "-----------------------------------------------------------------------------" << endl;
	inBorrowManager.displayStock();
	cout << "------------------------------------------------------------------------------" << endl;

	switch (c)
	{
	case '1':
		cout << "�뿩 �� ������ ������ �Է����ּ���. : ";
		getline(cin, inputValue);
		system("cls");

		//�뿩 �׽�Ʈ
		inBorrowManager.borrowBook(inputValue);
		goto BORROW;
	case '2':
		cout << "�ݳ� �� ������ ������ �Է����ּ���. : ";
		getline(cin, inputValue);
		system("cls");

		//�ݳ� �׽�Ʈ
		inBorrowManager.returnBook(inputValue);
		goto BORROW;
	default:
		break;
	}
}