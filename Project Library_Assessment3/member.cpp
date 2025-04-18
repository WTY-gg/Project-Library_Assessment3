#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Member {
private:
    string MemberID;
    string Name;
    string Email;
    string Address;

public:
    Member(string memID, string name, string email, string address) {
        MemberID = memID;
        Name = name;
        Email = email;
        Address = address;
    }

    string getMemberID() { return MemberID; }
    string getName() { return Name; }
    string getEmail() { return Email; }
    string getAddress() { return Address; }

    // Display Member Information
    void displayMember() {
        cout << "Member ID: " << MemberID;
        cout << "\tName: " << Name;
        cout << "\nEmail: " << Email;
        cout << "\tAddress: " << Address << endl;
        cout << endl;
    }
};
