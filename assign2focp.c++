#include<iostream>
#include <vector>
using namespace std;

const int MAX_STU = 100;

class Person{
    private:
    string name;
    int age;
    string id;
    long long int contact;

    public:
    Person();
    Person(string name,int age,string id,long long int contact);
    ~Person();
    void setPerson(string n,int a,string d,long long int c);
    virtual void displayDetails();
    virtual float calculatePayment(){
        return 0.0;
    }
};


    Person::Person(){
        name="ajay";
        age=19;
        id="24csu890";
        contact=83800838892;
    }
    
    
    Person::Person(string name,int age,string id,long long int contact){
        if(!name.empty()){
        this->name=name;
        }

        if(age>0 && age<=100){
        this->age=age;
        }

        this->id=id;
        this->contact=contact;
    }
    
    void Person::setPerson(string n,int a,string d,long long int c){
        if(!name.empty()){
        name=n;
        }

        if(age>0 && age<=100){
             age=a;
        }

        id=d;
        contact=c;
    }

    void Person::displayDetails(){
        cout<<"Name of the person : "<<name<<endl;
        cout<<"Age of the person : "<<age<<endl;
        cout<<"ID of the person : "<<id<<endl;
        cout<<"Contact of the person : "<<contact<<endl;
    }

    Person::~Person(){
        cout<<"Person Destructor is called .....\n";
    }
    
   



class Student : public Person{
    private:
    string edate;
    string program;
    float gpa;

    public:
    Student();
    Student(string name,int age,string id,long long int contact,string edate,string program,float gpa);
    ~Student();
    void setStudent(string ed,string p,float gp);
    void displayDetails() override;

    float calculatePayment() override {
        return 1000000000.0f; //add in undergraduate
    }
};

   Student::Student() : Person(), edate(""), program(""), gpa(0.0f) {}

   Student::Student(string name,int age,string id,long long int contact,string edate,string program,float gpa): Person(name, age, id, contact), edate(edate), program(program), gpa(gpa) {}


   void Student::setStudent(string ed,string p,float gp){
    edate=ed;
    program=p;

    if(gpa>0.0 && gpa<=4.0){
    gpa=gp;
   }
   }

   void Student::displayDetails(){
    Person::displayDetails();
    cout<<"Enrollment Date of the student : "<<edate<<endl;
    cout<<"Program of the student : "<<program<<endl;
    cout<<"GPA of the student : "<<gpa<<endl;
   }

   Student::~Student(){
    cout<<"Student Destructor is called .....\n";
    }

   
class Professor : public Person{
    private:
    string department;
    string specialization;
    string hdate;

    public:
    Professor();
    Professor(string name,int age,string id,long long int contact,string department,string specialization,string hdate);
    ~Professor();
    void setProfessor(string dep,string spc,string hire);
    void displayDetails() override;

    float calculatePayment() override {
        return 5000000.0f;
    }
};

    Professor::Professor() : Person(), department(""), specialization(""), hdate("") {}

    Professor::Professor(string name, int age, string id, long long int contact, string department, string specialization, string hdate) : Person(name, age, id, contact), department(department), specialization(specialization), hdate(hdate) {}
    

    void Professor::setProfessor(string dep,string spc,string hire){
        department=dep;
        specialization=spc;
        hdate=hire;
    }

    void Professor::displayDetails(){
        Person::displayDetails();
        cout<<"Department of the Professor : "<<department<<endl;
        cout<<"Specialization of the Professor : "<<specialization<<endl;
        cout<<"Hire date of the Professor : "<<hdate<<endl;
    }

    Professor::~Professor(){
        cout<<"Professor Destructor is called .....\n";
    }


class Course{
    private:
    string code;
    string title;
    int credits;
    string description;

    public:
    Course();
    Course(string code,string title,int credits,string description);
    ~Course();
    void setCourse(string c,string t,int cred,string des);
    void dispCourse();
};

 Course::Course(){
        code="AN89";
        title="Data Structures";
        credits=4;
        description="linked list,tree,hash map";
    }

    Course::Course(string code,string title,int credits,string description){
    this->code=code;
    this->title=title;

    if (credits > 0){
    this->credits=credits;
    }

    this->description=description;
    }

    void Course::setCourse(string c,string t,int cred,string des){
    code=c;
    title=t;

    if (credits > 0){
    credits=cred;
    }

    description=des;
    }

    void Course::dispCourse(){
        cout<<"Code of the course : "<<code<<endl;
        cout<<"Title of the course : "<<title<<endl;
        cout<<"Credits of the course : "<<credits<<endl;
        cout<<"Description of the course : "<<description<<endl;
    }

    Course::~Course(){
        cout<<"Course Destructor is called .....\n";
    }


class Department{
    private:
    string name;
    string location;
    long long int budget;

    public:
    Department();
    Department(string name,string location,long long int budget);
    ~Department();
    void setDepartment(string nm,string loc,long long int bud);
    void dispDepartment();
};

    Department::Department(){
        name="CSE";
        location="2nd floor of main building";
        budget=927902482047;
    }



    Department::Department(string name,string location,long long int budget){
    this->name=name;
    this->location=location;
    this->budget=budget;
    }


    void Department::setDepartment(string nm,string loc,long long int bud){
        name=nm;
        location=loc;
        budget=bud;
    }



    void Department::dispDepartment(){
        cout<<"Name of the department : "<<name<<endl;
        cout<<"Location of the department : "<<location<<endl;
        cout<<"Budget of the department : "<<budget<<endl;
    }


    Department::~Department(){
         cout<<"Department Destructor is called .....\n";
    }


class GradeBook {
private:
    vector<string> courseIDs;
    vector<string> studentIDs;
    vector<double> grades;

public:
    void addGrade(const string& courseID, const string& studentID, double grade) {
        courseIDs.push_back(courseID);
        studentIDs.push_back(studentID);
        grades.push_back(grade);
    }

    double calculateAverageGrade(const string& courseID) {
        double sum = 0.0;
        int count = 0;
        for (size_t i = 0; i < courseIDs.size(); ++i) {
            if (courseIDs[i] == courseID) {
                sum += grades[i];
                ++count;
            }
        }
        return (count > 0) ? (sum / count) : 0.0;
    }

    double getHighestGrade(const string& courseID) {
        double highest = -1.0;
        for (size_t i = 0; i < courseIDs.size(); ++i) {
            if (courseIDs[i] == courseID && grades[i] > highest) {
                highest = grades[i];
            }
        }
        return (highest >= 0.0) ? highest : 0.0;
    }

    vector<string> getFailingStudents(const string& courseID) {
        vector<string> failing;
        for (size_t i = 0; i < courseIDs.size(); ++i) {
            if (courseIDs[i] == courseID && grades[i] < 50.0) {
                failing.push_back(studentIDs[i]);
            }
        }
        return failing;
    }
};

class EnrollmentManager {
private:
    vector<string> courseIDs;
    vector<string> studentIDs;

public:
    void enrollStudent(const string& courseID, const string& studentID) {
        for (size_t i = 0; i < courseIDs.size(); ++i) {
            if (courseIDs[i] == courseID && studentIDs[i] == studentID) {
                return;
            }
        }
        courseIDs.push_back(courseID);
        studentIDs.push_back(studentID);
    }

    void dropStudent(const string& courseID, const string& studentID) {
        for (size_t i = 0; i < courseIDs.size(); ++i) {
            if (courseIDs[i] == courseID && studentIDs[i] == studentID) {
                courseIDs.erase(courseIDs.begin() + i);
                studentIDs.erase(studentIDs.begin() + i);
                return;
            }
        }
    }

    int getEnrollmentCount(const std::string& courseID) const {
        int count = 0;
        for (size_t i = 0; i < courseIDs.size(); ++i) {
            if (courseIDs[i] == courseID) {
                ++count;
            }
        }
        return count;
    }
};



int main() {
    Person* ptr;

    Student s("Ajay",19,"CSU89",789994567,"01-01-2023", "B.Tech", 8.9);
    Professor p("Hukum Singh",40,"APS88",9087777734,"ECE", "Embedded Systems", "12-12-2010");


    ptr = &s;
    cout << "\n--- Displaying Student Details via Person Pointer ---\n";
    ptr->displayDetails(); 
   
    ptr = &p;
    cout << "\n--- Displaying Professor Details via Person Pointer ---\n";
    ptr->displayDetails(); 

    return 0;
}
