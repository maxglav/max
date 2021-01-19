#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;


struct Pacient{
    Pacient(string firstName, string lastName, string middleName, int cart_num, int police_num) : firstName(firstName),
        lastName(lastName), middleName(middleName), cart_num(cart_num), police_num(police_num)
    {}


    string firstName;
    string lastName;
    string middleName;
    int cart_num;
    int police_num;
};

bool operator==(const Pacient& left, const Pacient& right) {
    return left.cart_num == right.cart_num;
}


struct PacientManager{
    PacientManager(string filename) : filename(filename) {}

    void delete_by_cart_num(int num) {
        ifstream in(filename);
        string data = "";
        string buf;

        while(getline(in, buf)) {
            istringstream iss(buf);
            string fName, lName, mName;
            int cartNum;
            iss >> fName >> lName >> mName >> cartNum;

            if (cartNum!= num)
                data += buf + "\n";
        }
        in.close();


        ofstream out(filename);
        out << data;

        out.close();
    }

    void append_record(Pacient const &p) {
        ifstream in(filename);
        string data = "";
        string buf;


        while(getline(in, buf)) {
            data += buf + "\n";
        }

        in.close();


        ofstream out(filename);

        out << p.firstName << " " << p.lastName << " " << p.middleName << " " << p.cart_num << " " << p.police_num << endl;
        out << data << endl;

        out.close();
    }

    string filename;
};



int main(){
    PacientManager pm = PacientManager("pacients");
    pm.append_record(Pacient("Alex", "Borrow", "Canibal", 11, 100));
    pm.append_record(Pacient("Dimas", "Eremenko", "Footbolchic", 10, 1000));

    pm.delete_by_cart_num(11);


    return 0;
}

