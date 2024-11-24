#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Address {
public:
    string city;
    string street;
    int num_home;
    int num_apart;

    virtual void save_to_file(ofstream& file) {
        size_t city_len = city.size();
        size_t street_len = street.size();
        file.write(reinterpret_cast<char*>(&city_len), sizeof(city_len));
        file.write(city.data(), city_len);
        file.write(reinterpret_cast<char*>(&street_len), sizeof(street_len));
        file.write(street.data(), street_len);
        file.write(reinterpret_cast<char*>(&num_home), sizeof(num_home));
        file.write(reinterpret_cast<char*>(&num_apart), sizeof(num_apart));
    }

    virtual void read_file(ifstream& file) {
        size_t city_len;
        file.read(reinterpret_cast<char*>(&city_len), sizeof(city_len));
        city.resize(city_len);
        file.read(&city[0], city_len);

        size_t street_len;
        file.read(reinterpret_cast<char*>(&street_len), sizeof(street_len));
        street.resize(street_len);
        file.read(&street[0], street_len);

        file.read(reinterpret_cast<char*>(&num_home), sizeof(num_home));
        file.read(reinterpret_cast<char*>(&num_apart), sizeof(num_apart));
    }
};

class E_Address : public Address {
public:
    string email;
    string address_site;
    int phone_number;

    void save_to_file(ofstream& file) {
        Address::save_to_file(file);
        size_t email_len = email.size();
        size_t site_len = address_site.size();
        file.write(reinterpret_cast<char*>(&email_len), sizeof(email_len));
        file.write(email.data(), email_len);
        file.write(reinterpret_cast<char*>(&site_len), sizeof(site_len));
        file.write(address_site.data(), site_len);
        file.write(reinterpret_cast<char*>(&phone_number), sizeof(phone_number));
    }

    void read_file(ifstream& file) {
        Address::read_file(file);
        size_t email_len;
        file.read(reinterpret_cast<char*>(&email_len), sizeof(email_len));
        email.resize(email_len);
        file.read(&email[0], email_len);

        size_t site_len;
        file.read(reinterpret_cast<char*>(&site_len), sizeof(site_len));
        address_site.resize(site_len);
        file.read(&address_site[0], site_len);

        file.read(reinterpret_cast<char*>(&phone_number), sizeof(phone_number));
    }

    string get_email_domain() const {
        size_t domain = email.find('@');
        if (domain != string::npos) {
            return email.substr(domain + 1);
        }
        return "";
    }
};

class Person : public E_Address {
public:
    string name;

    void save_to_file(ofstream& file) {
        size_t name_len = name.size();
        file.write(reinterpret_cast<char*>(&name_len), sizeof(name_len));
        file.write(name.data(), name_len);
        E_Address::save_to_file(file);
    }

    void read_file(ifstream& file) {
        size_t name_len;
        file.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
        name.resize(name_len);
        file.read(&name[0], name_len);
        E_Address::read_file(file);
    }

    void show_all_people(const string &filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        // зберігання колекції об'єктів Person
        vector<Person> people;
        // поки не досягнемо кінця файлу
        while (file.peek() != EOF) {
            Person person;
            person.read_file(file);
            people.push_back(person);
        }
        for (int i = 0; i < people.size(); ++i) {
            const Person& person = people[i];
            cout << "Name: " << person.name << endl;
            cout << "City: " << person.city << ", Street: " << person.street << ", Home: " << person.num_home << ", Apartment: " << person.num_apart << endl;
            cout << "Email: " << person.email << ", Address Site: " << person.address_site << ", Phone: " << person.phone_number << endl;
            cout << "-----------------------------------" << endl;
        }
        file.close();
    }

    void search_people(const string &filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        vector<Person> people;
        // поки не досягнемо кінця файлу
        while (file.peek() != EOF) {
            Person person;
            person.read_file(file);
            people.push_back(person);
        }
        bool found = false;
        for (size_t i = 0; i < people.size(); ++i) {
            for (size_t j = i + 1; j < people.size(); ++j) {
                if (people[i].city == people[j].city && people[i].get_email_domain() == people[j].get_email_domain()) {
                    cout << "People in city '" << people[i].city << "' with domain '" << people[i].get_email_domain() << "':\n";
                    cout << "Name: " << people[i].name << ", Email: " << people[i].email << endl;
                    cout << "Name: " << people[j].name << ", Email: " << people[j].email << endl;
                    cout << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "No people with the same city and email domain found." << endl;
        }
        file.close();
    }
};

int main() {
    vector<Person*> data_file;
    Person person;
    ofstream file("address_book.dat", ios::binary);

    Person* person1 = new Person();
    person1->name = "John Doe";
    person1->city = "New York";
    person1->street = "5th Avenue";
    person1->num_home = 123;
    person1->num_apart = 45;
    person1->email = "johndoe@knu.ua";
    person1->address_site = "www.johndoe.com";
    person1->phone_number = 123456789;
    data_file.push_back(person1);

    Person* person2 = new Person();
    person2->name = "Jane Smith";
    person2->city = "Los Angeles";
    person2->street = "Sunset Boulevard";
    person2->num_home = 67;
    person2->num_apart = 89;
    person2->email = "janesmith@gmail.com";
    person2->address_site = "www.janesmith.com";
    person2->phone_number = 987654321;
    data_file.push_back(person2);

    Person* person3 = new Person();
    person3->name = "Michael Johnson";
    person3->city = "Los Angeles";
    person3->street = "Lake Shore Drive";
    person3->num_home = 456;
    person3->num_apart = 23;
    person3->email = "michael.johnson@gmail.com";
    person3->address_site = "www.michaeljohnson.com";
    person3->phone_number = 246813579;
    data_file.push_back(person3);

    Person* person4 = new Person();
    person4->name = "Emily Davis";
    person4->city = "New York";
    person4->street = "Wall Street";
    person4->num_home = 300;
    person4->num_apart = 100;
    person4->email = "emilydavis@knu.ua";
    person4->address_site = "www.emilydavis.com";
    person4->phone_number = 135792468;
    data_file.push_back(person4);

    for (int i = 0; i < data_file.size(); ++i) {
        data_file[i]->save_to_file(file);
    }
    file.close();

    cout << "Address Book:\n";
    person.show_all_people("address_book.dat");

    cout << "Searching for people with the same city and email domain: \n";
    person.search_people("address_book.dat");

    for (int i = 0; i < data_file.size(); ++i) {
        delete data_file[i];
    }
}
