#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {
private:
    string ISBN;
    string BookName;
    string Author;
    bool isAvailable = true;
    bool isEbook;
    string EbookURL;

public:
    Book(string isbn, string name, string author, bool ebook_, string url) {
        ISBN = isbn;
        BookName = name;
        Author = author;
        isAvailable = true;
        isEbook = ebook_;
        EbookURL = url;
    }

    string getISBN() { return ISBN; }
    string getBookName() { return BookName; }
    bool getisEbook() { return isEbook; }
    string getEbookURL() { return isEbook ? EbookURL : "Do not have an Ebook"; }

    void setAvailable(bool available) { isAvailable = available; }
    bool getisAvailable() { return isAvailable; }

    // Display Book Information
    void displayBook() {
        cout << "ISBN:" << ISBN;
        cout << "\tTitle:" << BookName;
        cout << "\tAvailable:" << (isAvailable ? "Yes" : "No");
        cout << "\nEbook:" << (isEbook ? "Yes" : "No");
        cout << "\tURL:" << getEbookURL() << endl;
        cout << endl;
    }
};
