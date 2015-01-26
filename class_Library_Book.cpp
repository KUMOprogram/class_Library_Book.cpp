#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdbool.h>
using namespace std;

class Book
{
	private:
		string isbn;
		string title;
		string author;
		string subject;
		double price;
	public:
		Book(string& xisbn,string& xtitle,string& xauthor,string& xsubject,double xprice);
		void setisbn(string& xisbn);
		void settitle(string& xtitle);
		void setauthor(string& xauthor);
		void setsubject(string& xsubject);
		void setprice(double price);
		string& getisbn();
		string& gettitle();
		string& getauthor();
		string& getsubject();
		double getprice();
		_Bool find(string& searcher);
		_Bool more_than(double target);
		_Bool less_than(double target);
		_Bool more_equal(double target);
		_Bool less_equal(double target);
		_Bool fullfind(string& searcher, double target1, double target2);
};

Book::Book(string& xisbn,string& xtitle,string& xauthor,string& xsubject,double xprice)
{
	isbn=xisbn;
	title=xtitle;
	author=xauthor;
	subject=xsubject;
	price=xprice;
}

void Book::setisbn(string& xisbn)
{
	isbn=xisbn; 
}

void Book::settitle(string& xtitle)
{
	title=xtitle;
}

void Book::setauthor(string& xauthor)
{
	author=xauthor;
}

void Book::setsubject(string& xsubject)
{
	subject=xsubject;
}

void Book::setprice(double xprice)
{
	price=xprice;
}

string& Book::getisbn()
{
	return isbn;
}

string& Book::gettitle()
{
	return title;
}

string& Book::getauthor()
{
	return author;
}

string& Book::getsubject()
{
	return subject;
}

double Book::getprice()
{
	return price;
}

_Bool Book::find(string& searcher)
{
	if (isbn.find(searcher)!=string::npos)
	{
		return 1;
	}else if (title.find(searcher)!=string::npos)
	{
		return 1;
	}else if (author.find(searcher)!=string::npos)
	{
		return 1;
	}else if (subject.find(searcher)!=string::npos)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::more_than(double target)
{
    if (price>target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::less_than(double target)
{
    if (price<target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::more_equal(double target)
{
    if (price>=target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::less_equal(double target)
{
    if (price<=target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::fullfind(string& searcher, double target1, double target2)
{
	if(find(searcher))
	{
		if((more_equal(target1))&&(less_equal(target2)))
		{
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

class Library
{
	private:
		int libid;
		string libname;
		vector <Book> libbooks;
	public:
		Library(int xlibid, string& xlibname, vector <Book>& xlibbooks);
		int getlibid();
		string& getlibname();
		vector <Book>& getlibbooks();
		void setlibid(int xlibid);
		void setlibname(string& xlibname);
		void setlibbooks(vector <Book>& xlibbooks);
		_Bool find(int searcher);
		_Bool find(string searcher);
};

Library::Library(int xlibid, string& xlibname, vector <Book>& xlibbooks)
{
    libid=xlibid;
    libname=xlibname;
    libbooks=xlibbooks;
}

int Library::getlibid()
{
	return libid;
}

string& Library::getlibname()
{
	return libname;
}

vector <Book>& Library::getlibbooks()
{
	return libbooks;
}

void Library::setlibid(int xlibid)
{
    libid=xlibid;
}

void Library::setlibname(string& xlibname)
{
    libname=xlibname;
}

void Library::setlibbooks(vector <Book>& xlibbooks)
{
    libbooks=xlibbooks;
}

_Bool Library::find(int searcher)
{
	if (libid==searcher)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Library::find(string searcher)
{
	if (libname.find(searcher)!=string::npos)
	{
		return 1;
	}else{
		return 0;
	}
}

void menu();
void menu1();
void menu2();
vector <Book>& bubblebeam(vector <Book>& bubblebooks);
vector <Book>& bubblegun(vector <Book>& bubblebooks);
Book new_book(int sum_books);
Library new_library(int sum_libraries, vector <Book>& mybooks, vector <Library>& mylibraries);
void print_books(vector <Book>& mybooks);
void print_libraries(vector <Library>& mylibraries);
void search_books(int sum_books, vector <Book>& mybooks);
void search_bigger(int sum_books, vector <Book>& mybooks);
void search_smaller(int sum_books, vector <Book>& mybooks);
void search_full(int sum_books, vector <Book>& mybooks);
void search_libraries(int sum_libraries, vector <Library>& mylibraries);
vector <Book>& delete_book(vector <Book>& mybooks);
vector <Library>& delete_library(vector <Library>& mylibraries);
vector <Book>& edit_book(vector <Book>& mybooks);
vector <Library>& edit_library(vector <Book>& mybooks, vector <Library>& mylibraries);

int main()
{
system("color f1");
	int choose, sum_books=0, sum_libraries=0;
	vector <Book> mybooks;
	vector <Library> mylibraries;

	while(true)
	{
		menu();
		cin>>choose;
		cout<<endl;
		
		if (choose==1)
		{
			mybooks.push_back(new_book(sum_books));
			++sum_books;
			cout<<endl;
		}
		
		if (choose==2)
		{
			print_books(mybooks);
		}
		
		if (choose==3)
		{
            		search_books(sum_books, mybooks);
		}
		
		if (choose==4)
		{
			search_bigger(sum_books, mybooks);
		}
		
		if (choose==5)
		{
            		search_smaller(sum_books, mybooks);
		}
		
		if (choose==6)
		{
			search_full(sum_books, mybooks);
		}
		
		if (choose==7)
		{
			if (sum_books==0)
			{
				cout<<" REGISTER BOOKS FIRST TO CREATE A LIBRARY"<<endl<<endl;
			}else{
				mylibraries.push_back(new_library(sum_libraries, mybooks, mylibraries));
				++sum_libraries;
				cout<<endl;
			}
		}
		
		if (choose==8)
		{
            		print_libraries(mylibraries);
		}
		
		if (choose==9)
		{
            		search_libraries(sum_libraries, mylibraries);
		}
		
		if (choose==10)
		{
			mybooks=edit_book(mybooks);
		}
		
		if (choose==11)
		{
            		mylibraries=edit_library(mybooks, mylibraries);
		}
		
		if (choose==12)
		{
            		mybooks=delete_book(mybooks);
		}
		
		if (choose==13)
		{
            		mylibraries=delete_library(mylibraries);
		}
		
		if (choose==0)
		{
			break;
		}
		
		if ((choose!=0)&&(choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)&&(choose!=5)&&(choose!=6)&&(choose!=7)&&(choose!=8)&&(choose!=9)&&(choose!=10)&&(choose!=11)&&(choose!=12)&&(choose!=13))
		{
			cout<<" ERROR: WRONG CHOICE"<<endl;
		}
		
	system("pause");
	}
system("pause");
}

void menu()
{
    	system("cls");
    	cout<<endl;
    	cout<<" Add book ----------------------------------------- 1"<<endl;
    	cout<<" Show books --------------------------------------- 2"<<endl;
	cout<<" Find books by keyword ---------------------------- 3"<<endl;
	cout<<" Find books by price (bigger) --------------------- 4"<<endl;
	cout<<" Find books by price (smaller) -------------------- 5"<<endl;
	cout<<" Find books by keyword && range of price ---------- 6"<<endl;
	cout<<" Add new library ---------------------------------- 7"<<endl;
	cout<<" Show libraries ----------------------------------- 8"<<endl;
	cout<<" Find library by name (keyword) ------------------- 9"<<endl;
	cout<<" Edit books -------------------------------------- 10"<<endl;
	cout<<" Edit libraries ---------------------------------- 11"<<endl;
	cout<<" Delete a book ----------------------------------- 12"<<endl;
	cout<<" Delete a library -------------------------------- 13"<<endl;
	cout<<" Close -------------------------------------------- 0"<<endl<<endl;
	cout<<" CHOICE: ";
}

void menu1()
{
	cout<<endl;
    	cout<<" Add book to library ------------------------------ 1"<<endl;
    	cout<<" Show all books ----------------------------------- 2"<<endl;
	cout<<" Library ready ------------------------------------ 0"<<endl<<endl;
	cout<<" CHOICE: ";
}

void menu2()
{
	cout<<endl;
    	cout<<" Add book to library ------------------------------ 1"<<endl;
    	cout<<" Delete book from library ------------------------- 2"<<endl;
    	cout<<" Show all books ----------------------------------- 3"<<endl;
	cout<<" Library ready ------------------------------------ 0"<<endl<<endl;
	cout<<" CHOICE: ";
}

Book new_book(int sum_books)
{
	string isbn, title, author, subject, CPPbug;
	double price;
	Book newbook(isbn, title, author, subject, price);
    
    getline(cin,CPPbug);
	cout<<" --- BOOK "<<(sum_books+1)<<" ---"<<endl;

	cout<<" GIVE ISBN: ";
	getline(cin,isbn);
	newbook.setisbn(isbn);

	cout<<" GIVE TITLE: ";
	getline(cin,title);
	newbook.settitle(title);

	cout<<" GIVE AUTHOR: ";
	getline(cin,author);
	newbook.setauthor(author);

	cout<<" GIVE SUBJECT: ";
	getline(cin,subject);
	newbook.setsubject(subject);

	while(true)
	{
		cout<<" GIVE PRICE: ";
		cin>>price;
		if (price>=0)
		{
			break;
		}else{
			cout<<" @@@ ERROR: WRONG PRICE @@@"<<endl;
		}
	}
	newbook.setprice(price);
	
	return newbook;
}

Library new_library(int sum_libraries, vector <Book>& mybooks, vector <Library>& mylibraries)
{
	int libid, choice, xchoice;
	string libname, CPPbug;
	vector <Book> libbooks;
	Library newlibrary(libid, libname, libbooks);

	cout<<" --- LIBRARY "<<(sum_libraries+1)<<" ---"<<endl;

	_Bool flagzeus=1;
	while(flagzeus)
	{
		cout<<" GIVE LIBRARY ID: ";
		cin>>libid;
		if (mylibraries.size()>0)
		{
			for(int i=0; i<mylibraries.size(); ++i)
			{
				if (mylibraries[i].find(libid))
				{
					cout<<" @@@ ERROR: ID ALREADY EXISTS @@@"<<endl<<endl;
					flagzeus=1;
					break;
				}else{
					flagzeus=0;
				}
			}
		}else{
            flagzeus=0;
		}
	}
	newlibrary.setlibid(libid);

	getline(cin,CPPbug);
	cout<<" GIVE LIBRARY NAME: ";
	getline(cin, libname);
	newlibrary.setlibname(libname);

	cout<<endl<<" *** ALL REGISTERED BOOKS ***"<<endl;
	print_books(mybooks);

	_Bool flagizard=1;
	while(flagizard)
	{
		menu1();
		cin>>choice;
		cout<<endl;
		
		if (choice==1)
		{
            		cout<<" SELECT A BOOK FROM 1 TO "<<mybooks.size()<<" : ";
			cin>>xchoice;
			cout<<endl;
			if ((xchoice>=1)&&(xchoice<=mybooks.size()))
			{
				libbooks.push_back(mybooks[(xchoice-1)]);
				cout<<" BOOK SELECTED SUCCESSFULLY"<<endl<<endl;
			}else{
				cout<<" @@@ ERROR: INVALID CHOICE @@@"<<endl;
			}
		}
		
		if (choice==2)
		{
			print_books(mybooks);
			system("pause");
		}
		
		if (choice==0)
		{
			if (libbooks.size()==0)
			{
				cout<<" @@@ ERROR: SELECT AT LEAST 1 BOOK @@@"<<endl<<endl;
				system("pause");
				flagizard=1;
			}else{
                		newlibrary.setlibbooks(libbooks);
				flagizard=0;
				
				cout<<"** LIBRARY "<<(sum_libraries+1)<<" READY **"<<endl<<endl;
			}
		}
		
		if ((choice!=0)&&(choice!=1)&&(choice!=2))
		{
            		cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
		}
	}
	
	return newlibrary;
}

void print_books(vector <Book>& mybooks)
{
    	if (mybooks.size()==0)
	{
		cout<<" NO BOOKS YET"<<endl<<endl;
	}else{
		for(int i=0; i<mybooks.size(); ++i)
		{
			cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
			cout<<" ISBN: "<<mybooks[i].getisbn()<<endl;
			cout<<" TITLE: "<<mybooks[i].gettitle()<<endl;
			cout<<" AUTHOR: "<<mybooks[i].getauthor()<<endl;
			cout<<" SUBJECT: "<<mybooks[i].getsubject()<<endl;
			cout<<" PRICE: "<<mybooks[i].getprice()<<endl<<endl;
		}
	}
}

void print_libraries(vector <Library>& mylibraries)
{
	if (mylibraries.size()==0)
	{
		cout<<" NO LIBRARIES YET"<<endl<<endl;
	}else{
		for(int i=0; i<mylibraries.size(); ++i)
		{
			cout<<" **** LIBRARY "<<(i+1)<<" ****"<<endl;
			cout<<" LIBRARY ID: "<<mylibraries[i].getlibid()<<endl;
			cout<<" LIBRARY NAME: "<<mylibraries[i].getlibname()<<endl<<endl;
			print_books(mylibraries[i].getlibbooks());
		}
	}
}

vector <Book>& bubblebeam(vector <Book>& bubblebooks)
{
    	for(int i=0; i<bubblebooks.size(); ++i)
	{
		for(int j=bubblebooks.size()-1; j>i; --j)
		{
			if(bubblebooks[i].getprice()<bubblebooks[j].getprice())
			{
		                double c=bubblebooks[i].getprice();
		                bubblebooks[i].setprice(bubblebooks[j].getprice());
		                bubblebooks[j].setprice(c);
		
		                string c1=bubblebooks[i].getisbn();
		                bubblebooks[i].setisbn(bubblebooks[j].getisbn());
		                bubblebooks[j].setisbn(c1);
		
		                c1=bubblebooks[i].gettitle();
		                bubblebooks[i].settitle(bubblebooks[j].gettitle());
		                bubblebooks[j].settitle(c1);
		
		                c1=bubblebooks[i].getauthor();
		                bubblebooks[i].setauthor(bubblebooks[j].getauthor());
		                bubblebooks[j].setauthor(c1);
		
		                c1=bubblebooks[i].getsubject();
		                bubblebooks[i].setsubject(bubblebooks[j].getsubject());
		                bubblebooks[j].setsubject(c1);
			}
		}
	}
	return bubblebooks;
}

vector <Book>& bubblegun(vector <Book>& bubblebooks)
{
    	for(int i=0; i<bubblebooks.size(); ++i)
	{
		for(int j=bubblebooks.size()-1; j>i; --j)
		{
			if(bubblebooks[i].getprice()>bubblebooks[j].getprice())
			{
		                double c=bubblebooks[i].getprice();
		                bubblebooks[i].setprice(bubblebooks[j].getprice());
		                bubblebooks[j].setprice(c);
		
		                string c1=bubblebooks[i].getisbn();
		                bubblebooks[i].setisbn(bubblebooks[j].getisbn());
		                bubblebooks[j].setisbn(c1);
		
		                c1=bubblebooks[i].gettitle();
		                bubblebooks[i].settitle(bubblebooks[j].gettitle());
		                bubblebooks[j].settitle(c1);
		
		                c1=bubblebooks[i].getauthor();
		                bubblebooks[i].setauthor(bubblebooks[j].getauthor());
		                bubblebooks[j].setauthor(c1);
		
		                c1=bubblebooks[i].getsubject();
		                bubblebooks[i].setsubject(bubblebooks[j].getsubject());
		                bubblebooks[j].setsubject(c1);
			}
		}
	}
	return bubblebooks;
}

void search_books(int sum_books, vector <Book>& mybooks)
{
	string searcher, CPPbug;
	
    	getline(cin,CPPbug);
	cout<<" KEYWORD TO SEARCH: ";
	getline(cin,searcher);

	if (sum_books==0)
	{
		cout<<endl<<" NO BOOKS YET"<<endl;
	}else{
		int count=0;
		for(int i=0; i<sum_books; ++i)
		{
			if (mybooks[i].find(searcher))
			{
				cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
				cout<<" ISBN: "<<mybooks[i].getisbn()<<endl;
				cout<<" TITLE: "<<mybooks[i].gettitle()<<endl;
				cout<<" AUTHOR: "<<mybooks[i].getauthor()<<endl;
				cout<<" SUBJECT: "<<mybooks[i].getsubject()<<endl;
				cout<<" PRICE: "<<mybooks[i].getprice()<<endl<<endl;
				++count;
			}
		}
		if (count>0)
		{
			cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
		}else{
			cout<<endl<<" NO RESULTS"<<endl;
		}
	}
	cout<<endl;
}

void search_bigger(int sum_books, vector <Book>& mybooks)
{
	double target;

	cout<<" PRICES BIGGER THAN: ";
	cin>>target;

	if (sum_books==0)
	{
		cout<<" NO BOOKS YET"<<endl<<endl;
	}else{

		vector <Book> bubblebooks=bubblebeam(mybooks);

		int count=0;
		for(int i=0; i<sum_books; ++i)
		{
			if (bubblebooks[i].more_than(target))
			{
				cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
				cout<<" ISBN: "<<bubblebooks[i].getisbn()<<endl;
				cout<<" TITLE: "<<bubblebooks[i].gettitle()<<endl;
				cout<<" AUTHOR: "<<bubblebooks[i].getauthor()<<endl;
				cout<<" SUBJECT: "<<bubblebooks[i].getsubject()<<endl;
				cout<<" PRICE: "<<bubblebooks[i].getprice()<<endl<<endl;
				++count;
			}
		}
		if (count>0)
		{
			cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
		}else{
					cout<<endl<<" NO RESULTS"<<endl;
		}
	}
	cout<<endl;
}

void search_smaller(int sum_books, vector <Book>& mybooks)
{
	double target;

	cout<<" PRICES LESS THAN: ";
	cin>>target;

	if (sum_books==0)
	{
		cout<<" NO BOOKS YET"<<endl<<endl;
	}else{

		vector <Book> bubblebooks=bubblegun(mybooks);

		int count=0;
		for(int i=0; i<sum_books; ++i)
		{
			if (bubblebooks[i].less_than(target))
			{
				cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
				cout<<" ISBN: "<<bubblebooks[i].getisbn()<<endl;
				cout<<" TITLE: "<<bubblebooks[i].gettitle()<<endl;
				cout<<" AUTHOR: "<<bubblebooks[i].getauthor()<<endl;
				cout<<" SUBJECT: "<<bubblebooks[i].getsubject()<<endl;
				cout<<" PRICE: "<<bubblebooks[i].getprice()<<endl<<endl;
				++count;
			}
		}
		if (count>0)
		{
			cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
		}else{
			cout<<endl<<" NO RESULTS"<<endl;
		}
	}
	cout<<endl;
}

void search_full(int sum_books, vector <Book>& mybooks)
{
	string searcher, CPPbug;
	double target, target1=0, target2=sum_books;

	if (sum_books==0)
	{
		cout<<" NO BOOKS YET"<<endl<<endl;
	}else{
        	getline(cin,CPPbug);
		cout<<" KEYWORD TO SEARCH: ";
		getline(cin,searcher);

		while(true)
		{
			cout<<" PRICES BIGGER THAN: ";
			cin>>target1;
			if (target1>=0)
			{
				break;
			}else{
				cout<<" @@@ ERROR: WRONG PRICE @@@"<<endl;
			}
		}

		while(true)
		{
			cout<<" PRICES LESS THAN: ";
			cin>>target2;
			if (target2>=0)
			{
				break;
			}else{
				cout<<" @@@ ERROR: WRONG PRICE @@@"<<endl;
			}
		}
		cout<<endl;

		vector <Book> bubblebooks=bubblegun(mybooks);

		int count=0;
		for(int i=0; i<sum_books; ++i)
		{
			if (bubblebooks[i].fullfind(searcher,target1,target2))
			{
				cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
				cout<<" ISBN: "<<bubblebooks[i].getisbn()<<endl;
				cout<<" TITLE: "<<bubblebooks[i].gettitle()<<endl;
				cout<<" AUTHOR: "<<bubblebooks[i].getauthor()<<endl;
				cout<<" SUBJECT: "<<bubblebooks[i].getsubject()<<endl;
				cout<<" PRICE: "<<bubblebooks[i].getprice()<<endl<<endl;
				++count;
			}
		}
		if (count>0)
		{
			cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
		}else{
			cout<<endl<<" NO RESULTS"<<endl;
		}
	}
	cout<<endl;
}

void search_libraries(int sum_libraries, vector <Library>& mylibraries)
{
	string searcher, CPPbug;

    	getline(cin,CPPbug);
	cout<<" KEYWORD TO SEARCH: ";
	getline(cin,searcher);

	if (sum_libraries==0)
	{
		cout<<endl<<" NO LIBRARIES YET"<<endl;
	}else{
		int count=0;
		for(int i=0; i<sum_libraries; ++i)
		{
			if (mylibraries[i].find(searcher))
			{
				cout<<" **** LIBRARY "<<(i+1)<<" ****"<<endl;
				cout<<" LIBRARY ID: "<<mylibraries[i].getlibid()<<endl;
				cout<<" LIBRARY NAME: "<<mylibraries[i].getlibname()<<endl<<endl;
				print_books(mylibraries[i].getlibbooks());
				++count;
			}
		}
		if (count>0)
		{
			cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
		}else{
			cout<<endl<<" NO RESULTS"<<endl;
		}
	}
	cout<<endl;
}

vector <Book>& delete_book(vector <Book>& mybooks)
{
	int choice;
	print_books(mybooks);
	
	if (mybooks.size()!=0)
	{
		while(true)
		{
	        	cout<<" DELETE A BOOK FROM 1 - "<<mybooks.size()<<" (press 0 for cancel) : ";
			cin>>choice;
			cout<<endl;
			if ((choice>=1)&&(choice<=mybooks.size()))
			{
				mybooks.erase(mybooks.begin()+(choice-1),mybooks.begin()+choice);
				cout<<" DELETE SUCCESSFUL"<<endl<<endl;
				break;
			}else if (choice==0){
				cout<<" DELETE CANCELED"<<endl<<endl;
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
			}
		}
	}
	return mybooks;
}

vector <Library>& delete_library(vector <Library>& mylibraries)
{
	int choice;
	print_libraries(mylibraries);

	if (mylibraries.size()!=0)
	{
		while(true)
		{
	        	cout<<" DELETE A LIBRARY FROM 1 - "<<mylibraries.size()<<" (press 0 for cancel) : ";
			cin>>choice;
			cout<<endl;
			if ((choice>=1)&&(choice<=mylibraries.size()))
			{
				mylibraries.erase(mylibraries.begin()+(choice-1),mylibraries.begin()+choice);
				cout<<" DELETE SUCCESSFUL"<<endl<<endl;
				break;
			}else if (choice==0){
				cout<<" DELETE CANCELED"<<endl<<endl;
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
			}
		}
	}
	return mylibraries;
}

vector <Book>& edit_book(vector <Book>& mybooks)
{
    	int choice;
	string isbn, title, author, subject, xchoice, CPPbug;
	double price;
	Book newbook(isbn, title, author, subject, price);
	
    	if (mybooks.size()!=0)
	{
		print_books(mybooks);
		while(true)
		{
			cout<<" CHOSE BOOK TO EDIT FROM 1 - "<<mybooks.size()<<" (press 0 to cansel) : ";
			cin>>choice;
			cout<<endl;
			if ((choice>=1)&&(choice<=mybooks.size()))
			{
                		newbook=mybooks[(choice-1)];
                
				newbook.getisbn();
				while(true)
				{
					cout<<" TO EDIT ISBN PRESS + ELSE - : ";
					cin>>xchoice;
					if (xchoice=="+")
					{
						getline(cin, CPPbug);
						cout<<" GIVE NEW ISBN: ";
						getline(cin, isbn);
						newbook.setisbn(isbn);
						cout<<endl;
						break;
					}else if (xchoice=="-"){
						cout<<endl;
						break;
					}else{
						cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
					}
				}
				
				newbook.gettitle();
				while(true)
				{
					cout<<" TO EDIT TITLE PRESS + ELSE - : ";
					cin>>xchoice;
					if (xchoice=="+")
					{
						getline(cin, CPPbug);
						cout<<" GIVE NEW TITLE: ";
						getline(cin, title);
						newbook.settitle(title);
						cout<<endl;
						break;
					}else if (xchoice=="-"){
						cout<<endl;
						break;
					}else{
						cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
					}
				}
				
				newbook.getauthor();
				while(true)
				{
					cout<<" TO EDIT AUTHOR PRESS + ELSE - : ";
					cin>>xchoice;
					if (xchoice=="+")
					{
						getline(cin, CPPbug);
						cout<<" GIVE NEW AUTHOR: ";
						getline(cin, author);
						newbook.setauthor(author);
						cout<<endl;
						break;
					}else if (xchoice=="-"){
						cout<<endl;
						break;
					}else{
						cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
					}
				}
				
				newbook.getsubject();
				while(true)
				{
					cout<<" TO EDIT SUBJECT PRESS + ELSE - : ";
					cin>>xchoice;
					if (xchoice=="+")
					{
						getline(cin, CPPbug);
						cout<<" GIVE NEW SUBJECT: ";
						getline(cin, subject);
						newbook.setsubject(subject);
						cout<<endl;
						break;
					}else if (xchoice=="-"){
						cout<<endl;
						break;
					}else{
						cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
					}
				}
				
				newbook.getprice();
				while(true)
				{
					cout<<" TO EDIT PRICE PRESS + ELSE - : ";
					cin>>xchoice;
					if (xchoice=="+")
					{
						cout<<" GIVE NEW PRICE: ";
						cin>>price;
						newbook.setprice(price);
						cout<<endl;
						break;
					}else if (xchoice=="-"){
						cout<<endl;
						break;
					}else{
						cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
					}
				}
				
				mybooks[(choice-1)]=newbook;
				break;
			}else if(choice==0){
				cout<<" EDIT CANCELED"<<endl<<endl;
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
			}
		}
	}else{
		cout<<" NO BOOKS YET"<<endl<<endl;
	}
	return mybooks;
}

vector <Library>& edit_library(vector <Book>& mybooks, vector <Library>& mylibraries)
{
	int libid, choice, zchoice, schoice;
	string libname, xchoice, CPPbug;
	vector <Book> libbooks;
	Library newlibrary(libid, libname, libbooks);

	if (mybooks.size()!=0)
	{
	    if (mylibraries.size()!=0)
		{
			print_libraries(mylibraries);
			while(true)
			{
				cout<<" CHOSE BOOK TO EDIT FROM 1 - "<<mylibraries.size()<<" (press 0 to cansel) : ";
				cin>>choice;
				cout<<endl;
				if ((choice>=1)&&(choice<=mylibraries.size()))
				{
	                		newlibrary=mylibraries[(choice-1)];
	                		libbooks=newlibrary.getlibbooks();

					newlibrary.getlibname();
					while(true)
					{
						cout<<" TO EDIT LIBRARY NAME PRESS + ELSE - : ";
						cin>>xchoice;
						if (xchoice=="+")
						{
							getline(cin, CPPbug);
							cout<<" GIVE NEW LIBRARY NAME: ";
							getline(cin, libname);
							newlibrary.setlibname(libname);
							cout<<endl;
							break;
						}else if (xchoice=="-"){
							cout<<endl;
							break;
						}else{
							cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
						}
					}
					
					while(true)
					{
						cout<<" TO EDIT LIBRARY BOOKS PRESS + ELSE - : ";
						cin>>xchoice;
						if (xchoice=="+")
						{
							_Bool flagizard=1;
							while(flagizard)
							{
								menu2();
								cin>>zchoice;
								cout<<endl;

								if (zchoice==1)
								{
		                        				cout<<" *** ALL REGISTERED BOOKS ***"<<endl;
									print_books(mybooks);

						            		cout<<" SELECT A BOOK FROM 1 TO "<<mybooks.size()<<" : ";
									cin>>schoice;
									cout<<endl;
									if ((schoice>=1)&&(schoice<=mybooks.size()))
									{
										libbooks.push_back(mybooks[(schoice-1)]);
										cout<<" BOOK SELECTED SUCCESSFULLY"<<endl<<endl;
									}else{
										cout<<" @@@ ERROR: INVALID CHOICE @@@"<<endl;
									}
								}

								if (zchoice==2)
								{
									if (libbooks.size()>0)
									{
                                        					cout<<" *** LIBRARY'S BOOKS ***"<<endl;
										for(int i=0; i<libbooks.size(); ++i)
										{
											cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
											cout<<" ISBN: "<<libbooks[i].getisbn()<<endl;
											cout<<" TITLE: "<<libbooks[i].gettitle()<<endl;
											cout<<" AUTHOR: "<<libbooks[i].getauthor()<<endl;
											cout<<" SUBJECT: "<<libbooks[i].getsubject()<<endl;
											cout<<" PRICE: "<<libbooks[i].getprice()<<endl<<endl;
										}
									
							            		cout<<" SELECT A BOOK FROM 1 TO "<<libbooks.size()<<" : ";
										cin>>schoice;
										cout<<endl;
										if ((schoice>=1)&&(schoice<=libbooks.size()))
										{
											libbooks.erase(libbooks.begin()+schoice-1,libbooks.begin()+schoice);
											cout<<" BOOK SELECTED SUCCESSFULLY"<<endl<<endl;
										}else{
											cout<<" @@@ ERROR: INVALID CHOICE @@@"<<endl;
										}
									}else{
										cout<<" NO BOOKS REGISTERED"<<endl<<endl;
									}
								}

								if (zchoice==3)
								{
									print_books(mybooks);
									system("pause");
								}

								if (zchoice==0)
								{
                                    					if (libbooks.size()==0)
									{
										cout<<" @@@ ERROR: SELECT AT LEAST 1 BOOK @@@"<<endl<<endl;
										system("pause");
										flagizard=1;
									}else{
										newlibrary.setlibbooks(libbooks);
										flagizard=0;
										cout<<"** LIBRARY EDITED SUCCESSFULLY **"<<endl<<endl;
									}
								}

								if ((zchoice!=0)&&(zchoice!=1)&&(zchoice!=2)&&(zchoice!=3))
								{
						            		cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
								}
							}
							break;
						}else if (xchoice=="-"){
							cout<<endl;
							break;
						}else{
							cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
						}
					}
					
					mylibraries[(choice-1)]=newlibrary;
					break;
				}else if(choice==0){
					cout<<" EDIT CANCELED"<<endl<<endl;
					break;
				}else{
					cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl<<endl;
				}
			}
		}else{
			cout<<" NO LIBRARIES YET"<<endl<<endl;
		}
	}else{
	    cout<<" NO BOOKS YET"<<endl<<endl;
	}
	return mylibraries;
}
