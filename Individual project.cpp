#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Class Course declared.
class Course {
public:
    //constructor and destructor defined.
    Course(){};
    ~Course(){};

    //class Course's member variables declared.
    string Dept_code;
    int Course_num;
    string Course_name;
    long long int isbn;
    int Section_num;
    bool Is_Required_or_Optional;
    vector <Course> v;

    //class Course's member functions declared.
    void store_Course (string _Dept_code, int _Course_num, string _Course_name);
    void print_CourseList ( vector <Course> v);
    void assign_Book_to_Course(long long int _isbn,string _Dept_code, int _Course_num, int _Section_num, bool _Is_Required_or_Optional);
    void print_by_CourseNum(string _Dept_code, int _Course_num, vector <Course> v);
    void print_by_SectionNum(string _Dept_code, int _Course_num, int _Section_num, vector  <Course> v);
    void print_by_Dept_code(string _Dept_code, vector <Course> v);
    void print_all (vector <Course> v);

};

//temporary store the department code, course number, course name values before push backed in the course vector.
void Course::store_Course (string _Dept_code, int _Course_num, string _Course_name) {

    Dept_code = _Dept_code;
    Course_num = _Course_num;
    Course_name = _Course_name;

}

//print entire course list from the course vector.
void Course::print_CourseList (vector <Course> v) {

    for (int i=0; i<v.size();i++) {
        cout << "Course department code: "<< v[i].Dept_code << endl;
        cout << "Course number: " << v[i].Course_num << endl;
        cout << "Course name: " << v[i].Course_name << endl;
        cout << endl;
    }

}

//assign a book (ISBN) to given information department code, course number, section number, and if required or optional.
void Course::assign_Book_to_Course(long long int _isbn,string _Dept_code, int _Course_num, int _Section_num, bool _Is_Required_or_Optional)  {

    isbn = _isbn;
    Dept_code = _Dept_code;
    Course_num = _Course_num;
    Section_num = _Section_num;
    Is_Required_or_Optional = _Is_Required_or_Optional;

}

//print courses searched by department code and course number from course vector.
void Course::print_by_CourseNum(string _Dept_code, int _Course_num, vector <Course> v) {

    Dept_code = _Dept_code;
    Course_num = _Course_num;

      for (int i=0;i<v.size();i++) {
            if (v[i].Dept_code==_Dept_code&&v[i].Course_num==_Course_num){
        cout << "ISBN: " << v[i].isbn << endl;
        cout << "Department code: " << v[i].Dept_code << endl;
        cout << "Course name: " << v[i].Course_name<<endl;
        cout << "Course number: " << v[i].Course_num << endl;
        cout << "Section number: " << v[i].Section_num << endl;
        cout << "Require or Optiona (1: required, 0: optional): " << v[i].Is_Required_or_Optional  <<endl;
        cout << endl;
            }
       }

}
//print courses searched by department code, course number, and section number from course vector.
void Course::print_by_SectionNum(string _Dept_code, int _Course_num, int _Section_num, vector <Course> v) {

    Dept_code = _Dept_code;
    Course_num = _Course_num;
    Section_num = _Section_num;

         for (int i=0;i<v.size();i++) {
            if (v[i].Dept_code==_Dept_code&&v[i].Course_num==_Course_num&&v[i].Section_num==_Section_num){
        cout << "ISBN: " << v[i].isbn << endl;
        cout << "Department code: " << v[i].Dept_code << endl;
        cout << "Course name: " << v[i].Course_name << endl;
        cout << "Course number: " << v[i].Course_num << endl;
        cout << "Section number: " << v[i].Section_num << endl;
        cout << "Require or Optional (1:required, 0:optional): " << v[i].Is_Required_or_Optional  <<endl;
        cout << endl;
            }
        }

}

//print courses searched by department code from course vector.
void Course::print_by_Dept_code(string _Dept_code, vector <Course> v) {

      Dept_code = _Dept_code;

      for (int i=0;i<v.size();i++) {
            if (v[i].Dept_code==_Dept_code){
                    if (v[i].Is_Required_or_Optional==1||v[i].Is_Required_or_Optional==0){
        cout << "ISBN: " << v[i].isbn << endl;
        cout << "Course name: " << v[i].Course_name<<endl;
        cout << "Department code: " << v[i].Dept_code << endl;
        cout << "Course number: " << v[i].Course_num << endl;
        cout << "Section number: " << v[i].Section_num << endl;
        cout << "Require or Optional (1:required, 0:optional): " << v[i].Is_Required_or_Optional  <<endl;
        cout << endl;
                    }
            }
    }
}

//class Book declared.
class Book {
    public:
        //constructor and destructor defined.
        Book() {};
        ~Book() {};
        //member variables of class Book declared.
        string Book_title;
        string author;
        string edition_num;
        string Book_pubDate;
        string value;
        string Dept_code;

        bool Is_Required_or_Optional;
        char isNewUsedRentEBook;
        char c;
        long long int isbn;
        int Section_num;
        int Course_num;
        double Book_cost;
        vector <Book> v;

        //member functions declared.
        void BookInfo();
        void store_Book(long long int _isbn, string _Book_title);
        void store_Book_character(string _value);
        void print_all_Booksinfo( vector <Book> v);
        void print_a_Bookinfo(long long int _isbn, vector <Book> v);
        int find_index_by_ISBN(long long int _isbn, vector <Book> v);
        void store_Book_cost(double _Book_cost, char _isNewUsedRentEBook);
        void print_by_vec (vector <Book> v1, vector <int> cour_vec1);
        void print_Book_by_pubDate(string _Book_pubDate, vector <Book> v);
        void print_by_index(int i, vector <Book> v);
        void find_index_by_ISBN_vec_by_Dept_code(string _Dept_code, vector <Book> v);
        void assign_Book_to_Course(long long int _isbn,string _Dept_code, int _Course_num, int _Section_num, bool _Is_Required_or_Optional);
        void print_avgCost(string _Dept_code ,vector <Book> v);

};

//assign a book(ISBN) with given information: department code, course number, section number, and if required or optional.
void Book::assign_Book_to_Course(long long int _isbn,string _Dept_code, int _Course_num, int _Section_num, bool _Is_Required_or_Optional) {

    isbn = _isbn;
    Dept_code = _Dept_code;
    Course_num = _Course_num;
    Section_num = _Section_num;
    Is_Required_or_Optional = _Is_Required_or_Optional;

}

//temporary store the value before the data pushed back into book vector.
void Book::store_Book(long long int _isbn, string _Book_title) {

    isbn = _isbn;
    Book_title = _Book_title;

}

//temporary store the value before the data pushed back into book vector.
void Book::store_Book_character(string _value) {

    value = _value;

}

//temporary store the value before the data pushed back into book vector.
void Book::store_Book_cost(double _Book_cost, char _isNewUsedRentEBook) {

    Book_cost = _Book_cost;
    isNewUsedRentEBook = _isNewUsedRentEBook;

}

//Print all books information in the book vector.
void Book::print_all_Booksinfo(vector <Book> v) {

    cout << "-------------------------------printing all Books.----------------------------------- " <<endl;
    //for loop to printing out all contents of the vector.
    for (int i=0;i<v.size();i++) {
        cout << "ISBN: " << v[i].isbn << endl;
        cout << "Title: " << v[i].Book_title << endl;
        cout << "Author: " << v[i].author << endl;
        cout << "Edition number: " << v[i].edition_num << endl;
        cout << "Date of Publication: " << v[i].Book_pubDate << endl;
        cout << "Cost: " << v[i].Book_cost << endl;
        cout << "isNewUsedRentEBook: " << v[i].isNewUsedRentEBook << endl;
        cout << endl;
    }

}


//print average book cost, (minimum cost+maximum cost)/2, in the department.
void Book::print_avgCost(string _Dept_code ,vector <Book> v) {

    double max_Book_cost;
    double min_Book_cost;
    max_Book_cost = v[0].Book_cost;
    min_Book_cost = v[0].Book_cost;
            //finding maximum in the vector via comparison.
            for (int i=0; i<v.size(); i++) {
                    if (v[i].Dept_code==_Dept_code&&max_Book_cost<v[i].Book_cost) {
                     max_Book_cost = v[i].Book_cost;
                    }
                }
            //finding minimum in the vector via comparison.
            for (int i=0; i<v.size(); i++) {
                    if (v[i].Dept_code==_Dept_code&&min_Book_cost>v[i].Book_cost) {
                     min_Book_cost = v[i].Book_cost;
                    }
                }

    cout << "The average Book Book_cost is: "<< (max_Book_cost+min_Book_cost)/2 << endl;

}

//Print a book information pointed through ISBN in the book vector.
void Book::print_a_Bookinfo(long long int _isbn, vector <Book> v) {
    //find_index_by_ISBN function called to find matching index by given isbn in the vector.
    int i = find_index_by_ISBN(_isbn, v);

        cout << "ISBN: " << v[i].isbn << endl;
        cout << "Title: " << v[i].Book_title << endl;
        cout << "Author: " << v[i].author << endl;
        cout << "Edition number: " << v[i].edition_num << endl;
        cout << "Date of Publication: " << v[i].Book_pubDate << endl;

}

//find specific location(index) in the book vector by input isbn.
int Book::find_index_by_ISBN(long long int _isbn, vector <Book> v) {

    for (int i=0;i<v.size();i++) {
            if(v[i].isbn==_isbn) {
                return i;
            }
        }

}

//print book info from book vector at given index.
void Book::print_by_index (int i, vector <Book> v) {

        cout << "ISBN: " << v[i].isbn << endl;
        cout << "Title: " << v[i].Book_title << endl;
        cout << "Author: " << v[i].author << endl;
        cout << "Edition number: " << v[i].edition_num << endl;
        cout << "Date of Publication: " << v[i].Book_pubDate << endl;
        cout << "Cost: " << v[i].Book_cost << endl;
        cout << "isNewUsedRentEBook: " << v[i].isNewUsedRentEBook << endl;
        cout << "Department code: " << v[i].Dept_code << endl;
        cout << "Course number: " << v[i].Course_num << endl;
        cout << "Section number: " << v[i].Section_num << endl;
        cout << "Require or Optional (1:required, 0:optional): " << v[i].Is_Required_or_Optional  <<endl;
        cout << endl;

}

//search and print book info by publication date of book.
void Book::print_Book_by_pubDate(string _Book_pubDate, vector <Book> v) {

   Book_pubDate = _Book_pubDate;
   //for finding by date and printing matched book data loop.
   for (int i=0;i<v.size();i++) {
            //unknown " " handler in data string.
            if (v[i].Book_pubDate == " "+_Book_pubDate) {
                    cout << "matched Book list by Book_pubDate: " <<endl;
                print_by_index(i, v);
            }
            //error handler; no matched result.
            else {
                  cout << "no result."<<endl;
            }
    }

}


int main(void)
{
    char c;
    int Course_num;
	int Section_num;
	long long int isbn_num;
	double Book_cost;

	string command;
    string Course_name_str;
    string Book_pubDate;
	string Dept_code;
	string Book_title;
	string value;

	//class variables and vectors declared.
/*------------------*/
    Book b;
    Course cour;
    vector <Book> v;
    vector <Course> cour_vec1;
    vector <Course> cour_vec2;

/*------------------*/
	do{
        //get the command to execute.
        cin >> command;
        if (command=="B") {

          cin>>isbn_num;
          getline(cin, Book_title);
            b.store_Book(isbn_num, Book_title);
            v.push_back(b);
            isbn_num = 0;
            Book_title = "";
        }

        //command D <ISBN> <A|E|D> <value>: define characteristics of Books
        else if (command=="D") {
            cout << "'D' command executed" <<endl;
            cin >> isbn_num >> c;
            getline(cin, value);

            b.store_Book_character(value);
            if (c =='A')
            v[b.find_index_by_ISBN(isbn_num, v)].author = value;
            else if (c == 'E') {
            v[b.find_index_by_ISBN(isbn_num, v)].edition_num = value;
            }
            else if (c == 'D') {
            v[b.find_index_by_ISBN(isbn_num, v)].Book_pubDate = value;
            }
            else {
                    return 1;
            }
        }

        //command M <ISBN> <Book_cost> <'N'ew|'U'sed|'R'ental|'E'Book>: define Book_cost of a Book
        else if (command=="M"){
        char isNewUsedRentEBook;
            cin >> isbn_num >> Book_cost >> c;

            b.store_Book_cost(Book_cost, isNewUsedRentEBook);

            v[b.find_index_by_ISBN(isbn_num, v)].Book_cost = Book_cost;
            v[b.find_index_by_ISBN(isbn_num, v)].isNewUsedRentEBook = c;
        }
        //command C <Dept_code. code> <Course #> <name>: define a Course.
        else if (command=="C"){
        int a=0;
            cin >> Dept_code >> Course_num;
            getline(cin, Course_name_str);
            cour.store_Course(Dept_code, Course_num, Course_name_str);
            for (int i=0;i<cour_vec2.size();i++) {
                if (cour_vec2[i].Dept_code==Dept_code&&cour_vec2[i].Course_num==Course_num&&cour_vec2[i].Course_name==Course_name_str) {
                        cout << "Duplicated Course." <<endl;
                        a=1;
                }
            }
            if (a==0) {
                    cour_vec2.push_back(cour);
            }
        }
        //command A <ISBN> <Department Code> <Course Number> <Section Number> <R | O>: assign a Book to a class.
        else if (command=="A") {

            cin >> isbn_num >> Dept_code >> Course_num >> Section_num >> c;
            bool Is_Required_or_Optional;
             //required Book
            if (c=='R') {
                Is_Required_or_Optional = 1;
            }
            //optional Book
            else if (c=='O') {
                Is_Required_or_Optional = 0;
            }

            v[b.find_index_by_ISBN(isbn_num, v)].Dept_code = Dept_code;
            v[b.find_index_by_ISBN(isbn_num, v)].Course_num = Course_num;
            v[b.find_index_by_ISBN(isbn_num, v)].Section_num = Section_num;
            v[b.find_index_by_ISBN(isbn_num, v)].Is_Required_or_Optional = Is_Required_or_Optional;

            cour.assign_Book_to_Course(isbn_num, Dept_code, Course_num, Section_num, Is_Required_or_Optional);
            b.assign_Book_to_Course(isbn_num,Dept_code, Course_num, Section_num, Is_Required_or_Optional);
            cour_vec1.push_back(cour);
            for (int i=0;i<cour_vec1.size();i++) {
                   for (int j=0;j<cour_vec2.size();j++)
                if (cour_vec1[i].Course_num == cour_vec2[j].Course_num){
                    cour_vec1[i].Course_name = cour_vec2[j].Course_name;
                }
            }
        }

        //-----------------------------Printing part-------------------------------

        //command GC <Department Code> <Course Number>: print all Books of the Course.
        else if (command=="GC") {
        cin >> Dept_code >> Course_num;
        cour.print_by_CourseNum(Dept_code, Course_num, cour_vec1);
        }

        //command GS <Department Code> <Course Number> <Section Number>: Print all Books by Section.
        else if (command=="GS") {
        cin >> Dept_code >> Course_num >> Section_num;
        cour.print_by_SectionNum(Dept_code, Course_num, Section_num, cour_vec1);
        }

        //command GB <ISBN> : Print all information known about a particular Book
        else if (command=="GB") {
        cin >> isbn_num;
        b.print_a_Bookinfo(isbn_num, v);
        }

        //command PB: Explanation Print a list of all Books that are defined
        else if (command=="PB") {
        b.print_all_Booksinfo(v);
        }

        //command PC: Print a list of all Courses that are defined
        else if (command=="PC") {
        cour.print_CourseList(cour_vec2);
        }

        //command PY <MM/YYYY> Explanation Print all Books with known publication Book_pubDates in the given month/year or later
        else if (command=="PY") {
        cin>>Book_pubDate;
        //cout << Book_pubDate <<endl;
        b.print_Book_by_pubDate(Book_pubDate, v);
        }

        //command PD <Department Code>: print all Books of department.
        else if (command=="PD") {
        cin>>Dept_code;
        cour.print_by_Dept_code(Dept_code, cour_vec1);
        }
        //command PM <Department code>: print average cost of minimum and maximum cost of books in the department.
        else if (command=="PM") {
        cin >> Dept_code;
        b.print_avgCost(Dept_code, v);
        }
        //wrong command handler.
        else {
            cout << "wrong command." <<endl;
        }
	} while (!cin.eof());
    return 0;
}
