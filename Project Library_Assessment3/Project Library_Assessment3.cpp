#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // ใช้งาน all_of
#include "book.cpp"
#include "member.cpp"
using namespace std;

class Transaction {
private:
	string transactionID;
	string ISBN;
	string MemberID;

public:
	Transaction(string transID, string isbn, string memID)
		: transactionID(transID), ISBN(isbn), MemberID(memID) {}

	string getISBN() { return ISBN; }
	string getMemberID() { return MemberID; }

	// Update book status
	static void processTransaction(vector<Book>& books, string isbn) {
		for (auto& book : books) {
			if (book.getISBN() == isbn) {
				if (book.getisAvailable()) {
					book.setAvailable(false);
				}
				else {
					book.setAvailable(true);
				}
				break;
			}
		}
	}
};

bool askReturnToMenu() {
	string choice;
	cout << "\nBack to the main menu? (y/n): ";
	cin >> choice;
	return (choice == "y" || choice == "Y");
}

int main() {

	// ประกาศ เวคเตอร์
		vector<Book> bookList;
		vector<Member> members;
		vector<Transaction> transactions;

	// Book list
	{
		bookList.push_back(Book("9780786856299", "Percy Jackson: The Lightning Thief", "Rick Riordan", true, "https://ebook.com/0001"));
		bookList.push_back(Book("9780062796028", "A Series of Unfortunate Events: The Bad Beginning", "Lemony Snicket", true, "https://ebook.com/0002"));
		bookList.push_back(Book("9780545069670", "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", false, ""));
	}

	// Member list
	{
		members.push_back(Member("001", "Julie", "J.Julie@gmail.com", "Thailand"));
		members.push_back(Member("002", "Jaii02", "02@gmail.com", "Thailand"));
		members.push_back(Member("003", "Jaii03", "03@gmail.com", "Thailand"));
	}

	// Transaction list
	{
		transactions.push_back(Transaction("T001", "9780786856299", "001"));
		Transaction::processTransaction(bookList, "0001");  

		transactions.push_back(Transaction("T002", "9780062796028", "002"));
		Transaction::processTransaction(bookList, "0002");  

		transactions.push_back(Transaction("T003", "9780545069670", "003"));
		Transaction::processTransaction(bookList, "0005");  

		transactions.push_back(Transaction("T004", "9780062796028", "002"));
		Transaction::processTransaction(bookList, "0001");  
	}

	// ประกาศตัวแปรที่ใช้ในการ run main menu (choice & running)
	int choice;
	bool running = true; // ตัวแปร running สำหรับให้เลือกว่าจะให้โปแกรมกลับมา main menu ไหม

	// Display main menu
	while (running) {
		cout << "\n======= Main menu =======\n"
			<< "1. Show all books\n"
			<< "2. Add new book\n"
			<< "3. Borrowing\n"
			<< "4. Returning\n"
			<< "5. Check your member detail\n"
			<< "6. Exiting program\n" << "\n";
		cout << "Enter your number: ";
		cin >> choice;

		switch (choice) {

		case 1: // แสดง Book list ทั้งหมด
			cout << "\n======= Book List =======" << endl;
			for (size_t i = 0; i < bookList.size(); ++i) {
				cout << (i + 1) << ". ";
				bookList[i].displayBook();
			}
			running = askReturnToMenu();
			break;

		case 2: {
			string isbn, name, author, url; // ประกาศตัวแปรต่างๆที่ใช้ในการรับรายละเอียดหนังสือเพิ่ม
			bool ebook_;

			cout << "\n=== Add New Book ===\n";

			while (true) {
				cout << "Enter ISBN (13 digits): ";
				cin >> isbn;
				if (isbn.length() == 13 && all_of(isbn.begin(), isbn.end(), ::isdigit)) break;
				// เงื่อนไข isbnจะต้องมีความยาว13ตัวพอดี และทุกตัวตั้งแต่ตัวแรกจนจบต้องเป็น digit/ตัวเลขเท่านั้น ถ้าตรงเงื่อนไขให้ break! จาก loop
				cout << "Invalid ISBN. Please enter exactly 13 digits.\n";
			}

			cin.ignore();
			// ***ใส่เพื่อเคลียร์ \n ที่ได้รับจากการ cin >> isbn ใช้แค่ในกรณีที่ใช้ cin แล้วใช้ getline ต่อ
			// cin ใช้รับค่าเป็นตัวๆ รับช่องว่างไม่ได้ | getline ใช้รับค่าที่เป็นช่องว่างได้ ใช้รับชื่อหนังสือ, ชื่อคนเขียน ดี

			cout << "Enter book title: ";
			getline(cin, name);

			cout << "Enter author name: ";
			getline(cin, author);

			cout << "Enter eBook Link (optional): ";
			getline(cin, url);

			if (url.empty()) {ebook_ = false;}
			else {ebook_ = true;}

			// เพิ่มเข้า vector
			bookList.push_back(Book(isbn, name, author, ebook_, url));

			cout << "\n Book added successfully!\n";
			running = askReturnToMenu();
			break;
		}

		case 3:
			running = askReturnToMenu();
			break;

		case 4:
			running = askReturnToMenu();
			break;

		case 5:
			running = askReturnToMenu();
			break;

		case 6:
			cout << "\nExiting program...\n";
			running = false;
			break;

		default:
			cout << "\nInvalid choice. Please select a valid option.\n";
		}
	}

return 0;

}
