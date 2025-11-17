#include <stdio.h>
#include <string.h>

// 1. 변수 및 배열 선언

#define MAX_BOOKS 5  // 최대 도서 수

// 도서 정보 구조체 정의
struct Book {
    char name[100];        // 도서 이름
    char author[50];       // 저자 이름
    int publishYear;       // 출판 년도
    char genre[30];        // 장르
};

struct Book books[MAX_BOOKS];  // 최대 5권의 도서를 저장할 배열
int count = 0;  // 현재 저장된 도서 수

// 2. 핵심 기능 함수들 선언

// 도서 추가 함수
void addBook();

// 도서 삭제 함수
void deleteBook();

// 도서 검색 함수
void searchBook();

// 도서 수정 함수
void modifyBook();

// 도서 목록 출력 함수
void printBooks();

int main() {
    int choice;

    printf("--- 도서 관리 프로그램 시작! ---\n");

    // 3. 메인 함수의 흐름 구현
    do {
        // 메뉴 출력
        printf("\n메뉴:\n");
        printf("1. 도서 추가\n");
        printf("2. 도서 삭제\n");
        printf("3. 도서 검색\n");
        printf("4. 도서 수정\n");
        printf("5. 도서 목록 출력\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        // 메뉴 선택에 따른 함수 호출
        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                modifyBook();
                break;
            case 5:
                printBooks();
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다. 다시 입력하세요.\n");
                break;
        }
    } while (choice != 0);  // 사용자가 0을 입력할 때까지 반복

    return 0;
}

// 4. 도서 추가 함수 구현
void addBook() {
    if (count >= MAX_BOOKS) {
        printf("도서 추가 불가! 최대 도서 수에 도달했습니다.\n");
        return;
    }

    printf("도서 이름: ");
    scanf(" %[^\n]", books[count].name);  // 공백 포함 입력 받기
    printf("저자 이름: ");
    scanf(" %[^\n]", books[count].author);
    printf("출판 년도: ");
    scanf("%d", &books[count].publishYear);
    printf("장르: ");
    scanf(" %[^\n]", books[count].genre);

    count++;  // 도서 추가 후 도서 수 증가
    printf("도서가 추가되었습니다.\n");
}

// 5. 도서 삭제 함수 구현
void deleteBook() {
    int bookNumber;
    printf("삭제할 도서 번호 (1부터 %d까지): ", count);
    scanf("%d", &bookNumber);

    if (bookNumber < 1 || bookNumber > count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    // 삭제하려는 도서 번호를 배열에서 삭제하고 뒤의 도서들 한 칸씩 앞으로 이동
    for (int i = bookNumber - 1; i < count - 1; i++) {
        books[i] = books[i + 1];  // 한 칸씩 앞으로 이동
    }

    count--;  // 도서 수 감소
    printf("도서가 삭제되었습니다.\n");
}

// 6. 도서 검색 함수 구현
void searchBook() {
    char query[100];
    printf("검색할 도서 이름 또는 저자 이름: ");
    scanf(" %[^\n]", query);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].name, query) != NULL || strstr(books[i].author, query) != NULL) {
            printf("도서 번호: %d, 도서 이름: %s, 저자: %s, 출판 년도: %d, 장르: %s\n",
                   i + 1, books[i].name, books[i].author, books[i].publishYear, books[i].genre);
            found = 1;
        }
    }

    if (!found) {
        printf("검색 결과가 없습니다.\n");
    }
}

// 7. 도서 수정 함수 구현
void modifyBook() {
    int bookNumber;
    printf("수정할 도서 번호 (1부터 %d까지): ", count);
    scanf("%d", &bookNumber);

    if (bookNumber < 1 || bookNumber > count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    // 수정할 도서의 정보 입력받기
    printf("새로운 도서 이름: ");
    scanf(" %[^\n]", books[bookNumber - 1].name);
    printf("새로운 저자 이름: ");
    scanf(" %[^\n]", books[bookNumber - 1].author);
    printf("새로운 출판 년도: ");
    scanf("%d", &books[bookNumber - 1].publishYear);
    printf("새로운 장르: ");
    scanf(" %[^\n]", books[bookNumber - 1].genre);

    printf("도서 정보가 수정되었습니다.\n");
}

// 8. 도서 목록 출력 함수 구현
void printBooks() {
    if (count == 0) {
        printf("도서 목록이 비어 있습니다.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("도서 번호: %d, 도서 이름: %s, 저자: %s, 출판 년도: %d, 장르: %s\n",
               i + 1, books[i].name, books[i].author, books[i].publishYear, books[i].genre);
    }
}
