/*Design the data structures for an online book reader system.*/

#include <iostream>

class user {
private:
	string name;
	int age;
	string account;
	string password;
public:
	string get_name() { return name; }
	int get_age() { return age; }
	string get_account { return account; }
	string get_password { return password; }
	void set_password(string pass) { password = pass; }	
};

class user_manager {
private:
	vector<user> manager;
public:
	add_user(user u) { manager.push_back(u); }
	remove_user(user u) {
		for (int i = 0; i < manager.size(); u++)
			if (u == manager[i]) {
				manager.erase(manager.begin() + i);
				return; 
			}
	}
};

class book {
private:
	string name;
	string author;
	int id;
public:
	string get_name() { return name; }
	string author() { return author; }
	int get_id() { return id; }
	void set_id(int id) { this->id = id; }
};

class library {
private:
	int number_of_books;
	vector<book> books;
public:
	int get_number_of_books() { return number_of_books; }	
	void add_book(book b) { books.push_back(b); }
	void remove_a_book(book b) {
		for (int i = 0; i<books.size(); i++)
			if (b == books[i]) {
				books.erase(books.begin() + i);
				return;
			}
	}
};

class book_reader {
private:
	library lib;
	user_manager um;
public:
	book_reader(library lib, user_manager um) {
		this->lib = lib;
		this->um = um;
	}	

	library get_library() { return lib; }
	user_manager get_manager() { return um; }
	void set_library(library lib) { this->lib = lib; }
	void set_um(user_manager um) { this->um = um; }
};
