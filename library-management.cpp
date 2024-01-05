#include<bits/stdc++.h>
using namespace std;

class Book {
private:
    string title;
    string author;
    int id;
    bool borrowed;

public:
    Book(string title, string author, int id) : title(title), author(author), id(id), borrowed(false) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getId() const {
        return id;
    }

    bool isBorrowed() const {
        return borrowed;
    }

    void borrowBook() {
        borrowed = true;
    }

    void returnBook(){
        borrowed = false;
    }
        
    
};

class Library {
private:
    vector<Book> books; 
    
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        cout << "Available Books:" << endl;
        for (const auto& book : books) {
            if (!book.isBorrowed()) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ID: " << book.getId() << endl;
            }
        }
        cout << endl;
    }

    bool borrowBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id && !book.isBorrowed()) {
                book.borrowBook();
                return true;
            }
        }
        return false;
    }

    bool returnBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id && book.isBorrowed()) {
                book.returnBook();
                return true;
            }
        }
        return false;
    }

    bool removeBook(int id) {
        int i=0;
         for (const auto& book : books) {
            if(book.getId()==id){
                break;
            }
            i++;
        }
        books.erase(books.begin()+i);
    }
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook(Book("Ramayana","Valmiki",0));
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 2));
    library.addBook(Book("1984", "George Orwell", 3));
    library.addBook(Book("Computer Network","Andrew S. Tanenbaum",4));

    while(true){
        int ch;
        cout<<"Enter your choice: "<<endl;
        cout<<"1. For Admin"<<endl;
        cout<<"2. For Student"<<endl;
        cout<<"3. For Close Library :) "<<endl;
        cin>>ch;
        if(ch==1){
            //            admin_login();
            while(true){
                cout<<"Enter your choice: "<<endl;
                cout<<"1. For Add Book: "<<endl;
                cout<<"2. For See All Book: "<<endl;
                cout<<"3. For Remove Book: "<<endl;
                cout<<"4. For Exit. "<<endl;
                int ach;
                cin>>ach;
                if(ach==4) break;
                else if(ach==1){
                    // add book
                    string bookname,author;
                    int id;
                    cout<<"Enter Book Name: "<<endl;
                    cin>>bookname;
                    cout<<" Author Name: "<<endl;
                    cin>>author;
                    cout<<" Enter Book id: ";
                    cin>>id;
                    library.addBook(Book(bookname,author,id));
                    cout<<"------------------------------"<<endl;
                    cout<<"Book Added Successfully.."<<endl;
                    cout<<"------------------------------"<<endl;
                }else if(ach==2) library.displayBooks();
                else if(ach==3){
                    int bookid;
                    cout<<"Enter book id: "<<endl;
                    cin>>bookid;
                    library.removeBook(bookid);
                }
            }
        }else if(ch==2){
            //                student_login();
            while(true){
                cout<<"Enter Choice: "<<endl;
                cout<<"1. For See All Book: "<<endl;
                cout<<"2. For Borrow Book: "<<endl;
                cout<<"3. For Return Book: "<<endl;
                cout<<"4. For Exit. "<<endl;
                int stch;
                cin>>stch;
                if(stch == 4)break;
                else if(stch == 1 ) library.displayBooks();
                else if(stch==2){
                    int bookid;
                    cout<<"Enter Book id: "<<endl;
                    cin>>bookid;

                    if(library.borrowBook(bookid)) cout << "Book with ID: " << bookid << " successfully borrowed." << endl;
                    else cout << "Book with ID: " << bookid << " is not available for borrowing." << endl;
                    
                }else if(stch==3){
                    int bookid;
                    cout<<"Enter Book Id: "<<endl;
                    cin>>bookid;

                    if (library.returnBook(bookid)) cout << "Book with ID: " << bookid << " successfully returned." << endl;
                    else cout << "Book with ID: " << bookid << " is not available for return." << endl;
                }
            }
        }else if(ch==3)  break;
        else cout<<"Invalid Input..  Please Enter valid input :)"<<endl;
    }
    cout<<"Thank you..."<<endl;
    return 0;
}
