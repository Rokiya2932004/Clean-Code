#include <string>
#include <deque>
#include <iostream>
using namespace std;
class Book
{
private:
    string BookName;
    int Book_ID;
    string Book_Author;

public:
    Book(string book_name, string book_author, int book_id)
    {
        BookName = book_name;
        Book_Author = book_author;
        Book_ID = book_id;
    }
    string getBookName() { return BookName; }
    int getBook_ID() { return Book_ID; }
    string getBook_Author() { return Book_Author; }
};
class patron
{
private:
    string patronName;
    int patron_SSN;
    deque<Book> BorrowedBooks;

public:
    patron(string patron_name, int patron_ssn)
    {
        patronName = patron_name;
        patron_SSN = patron_ssn;
    }
    string getPatronName()
    {
        return patronName;
    }
    int getPatronSSN()
    {
        return patron_SSN;
    }
    void borrowBook(Book Wantedbook)
    {
        BorrowedBooks.push_back(Wantedbook);
    }
    bool isBorrowedBook(int BorrowbookID)
    {
        for (Book is_borrowed_Book : BorrowedBooks)
        {
            if (is_borrowed_Book.getBook_ID() == BorrowbookID)
            {
                return true;
            }
        }
        return false;
    }
};
class library
{
    deque<Book> Available_books;
    bool Is_borrowed_Book = false;

public:
    library()
    {
        Available_books.push_back(Book("Amarita", "Omar AbdELhamid", 123));
        Available_books.push_back(Book("Harry Potter", "Joanne Rowling", 456));
        Available_books.push_back(Book("Sherlock Holmes", "Arthur Conan", 789));
        Available_books.push_back(Book("Hoker", "Nicola Haddad", 101));
    }
    void ViewAvailableBooks()
    {
        cout << "The Available books are :" << endl;
        for (auto showAvilabelBook : Available_books)
        {
            cout << "Book ID : " << showAvilabelBook.getBook_ID() << "  ,   Title : " << showAvilabelBook.getBookName() << "  ,   Author : " << showAvilabelBook.getBook_Author() << endl;
        }
    }
} library_object;
int main()
{
    cout << "HELLO !! " << endl;
    library_object.ViewAvailableBooks();
    patron patorn_data("Asil", 13305);
    cout << "Is this your first time? (y , n)" << endl;
    bool is_first_time = false;
    char theAnswer;
    cin >> theAnswer;
    if (theAnswer == 'y')
    {
        is_first_time = true;
    }
    bool end_programe = false;
    char answer_to_end_program;
    while (!end_programe)
    {
        if (is_first_time)
        {
            string bookName, bookAuthor;
            int bookID;
            cout << "Enter Book Name: ";
            cin.ignore();
            getline(cin, bookName);

            cout << "Enter Book Author: ";
            getline(cin, bookAuthor);

            cout << "Enter Book ID: ";
            cin >> bookID;

            Book wantedBook(bookName, bookAuthor, bookID);
            patorn_data.borrowBook(wantedBook);
            cout << "\nBook borrowed successfully." << endl;
            cout << "Do you want to save changes ? (y , n)" << endl;
            cin >> answer_to_end_program;
            if (answer_to_end_program == 'y')
            {
                cout << "saved successfully";
                end_programe = true;
            }
        }
        if (is_first_time)
        {
            cout << "Enter the Book ID you want to check:\n ";
            int wanted_book_ID;
            cin >> wanted_book_ID;
            if (patorn_data.isBorrowedBook(wanted_book_ID))
            {
                cout << "The book is borrowed now ." << endl;
            }
            else
            {
                cout << "The book is available." << endl;
            }
            cout << "Do you want to save changes ? (y , n)" << endl;
            cin >> answer_to_end_program;
            if (answer_to_end_program == 'y')
            {
                cout << "saved successfully";
                end_programe = true;
            }
        }
        else
        {
            cout << "Enter the Book ID you want to check:\n ";
            int wanted_book_ID;
            cin >> wanted_book_ID;
            if (patorn_data.isBorrowedBook(wanted_book_ID))
            {
                cout << "The book is borrowed." << endl;
            }
            else
            {
                cout << "The book is available." << endl;
            }
        }
    }
}
