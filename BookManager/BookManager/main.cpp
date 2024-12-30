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

	//책 추가 테스트
	BookManager.addBook("소년이 온다", "한강");
	BookManager.addBook("이처럼 사소한 것들", "클레어 키건");
	BookManager.addBook("내가 나라서 정말 좋아", "김지훤");
	BookManager.addBook("흰", "한강");
	BookManager.addBook("지적 대화를 위한 넓고 얖은 지식 무한", "채사장");
	BookManager.addBook("무의식은 어떻게 나를 설계하는가", "데이비드 이글먼");
	BookManager.addBook("코스모스", "칼 세이건");
	BookManager.addBook("이기적 유전자", "리처드 도킨스");
	BookManager.addBook("이득우의 게임 수학", "이득우");
	BookManager.addBook("사피엔스", "유발 하라리");
	BookManager.addBook("총 균 쇠", "재레드 다이아몬드");

	//대여 관리자 생성 및 초기화
	BorrowManager BorrowManager;

	vector<Book> BookList = BookManager.GetAllBook();

	for (int i = 0; i < BookList.size(); i++)
	{
		BorrowManager.initializeStock(BookList[i], rand() % 4 + 3);
	}

BOOKLIST:
	system("cls");

	//도서 리스트 출력 테스트
	cout << "------------------------------------------------------------------------------" << endl;
	BookManager.displayAllBooks();
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "1. 책 이름으로 검색 | 2. 작가 이름으로 검색 | 3. 대여 | AnyKey. 종료" << endl;

	c = _getch();

	system("cls");
	cout << "------------------------------------------------------------------------------" << endl;
	BookManager.displayAllBooks();
	cout << "------------------------------------------------------------------------------" << endl;

	switch (c)
	{
	case '1':
		cout << "검색할 책의 제목을 입력하세요. : ";
		getline(cin, inputValue);					//공백(띄어쓰기)도 포함시키기 위함
		system("cls");

		//제목 검색 테스트
		cout << "------------------------------------------------------------------------------" << endl;
		BookManager.searchByTitle(inputValue);
		cout << "------------------------------------------------------------------------------" << endl;

		_getch();
		goto BOOKLIST;
	case '2':
		cout << "검색할 작가의 이름을 입력하세요. : ";
		getline(cin, inputValue);
		system("cls");

		//작가 검색 테스트
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
	//대여 가능 리스트 출력 테스트
	cout << "------------------------------------------------------------------------------" << endl;
	inBorrowManager.displayStock();
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "1. 대여 신청 | 2. 반납 신청 | AnyKey. 이전 메뉴" << endl;

	char c = _getch();
	string inputValue;

	system("cls");

	cout << "-----------------------------------------------------------------------------" << endl;
	inBorrowManager.displayStock();
	cout << "------------------------------------------------------------------------------" << endl;

	switch (c)
	{
	case '1':
		cout << "대여 할 도서의 제목을 입력해주세요. : ";
		getline(cin, inputValue);
		system("cls");

		//대여 테스트
		inBorrowManager.borrowBook(inputValue);
		goto BORROW;
	case '2':
		cout << "반납 할 도서의 제목을 입력해주세요. : ";
		getline(cin, inputValue);
		system("cls");

		//반납 테스트
		inBorrowManager.returnBook(inputValue);
		goto BORROW;
	default:
		break;
	}
}