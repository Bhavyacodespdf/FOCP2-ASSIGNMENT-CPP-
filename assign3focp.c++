#include<iostream>
#include <vector>
using namespace std;

const int MAX_STU = 100;

class Person{
    protected:
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
    void displayDetails() override ;

    virtual double calculatePayment() const = 0; 

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

class AssistantProfessor : public Professor{
    protected:
    bool isTenureTrack;
    string researchArea;

public:
    AssistantProfessor(string name, int age, string id, long long contact,string department,string specialization, string hdate, bool isTenureTrack,string researchArea): Professor(name, age, id, contact, department,specialization, hdate),isTenureTrack(isTenureTrack),researchArea(researchArea){}
    void displayDetails() override {
        Professor::displayDetails();
        cout << "Tenure Track: " << (isTenureTrack ? "Yes" : "No") << endl;
    }

    double calculatePayment() const {
    double baseSalary = 50000;
    return baseSalary;
}

};

class AssociateProfessor : public Professor{
    int publications;
    string domain; 

public:
    AssociateProfessor(string name, int age, string id, long long contact,string department, string specialization,string hdate,int publications, string domain): Professor(name, age, id, contact, department,specialization,hdate),publications(publications), domain(domain) {}
    void displayDetails() override {
        Professor::displayDetails();
        cout << "Publications: " << publications << ", Domain: " << domain << endl;
    }

    double calculatePayment() const {
    double baseSalary = 50000;
    return baseSalary;
}

};

class FullProfessor : public Professor{
    protected:
    bool isTenured;
    int numBooks;

public:
    FullProfessor(string name, int age, string id, long long contact,string department, string specialization, string hdate,bool isTenured, int numBooks): Professor(name, age, id, contact, department, specialization,hdate),isTenured(isTenured), numBooks(numBooks) {}
    void displayDetails() override {
        Professor::displayDetails();
        cout << "Tenured: " << (isTenured ? "Yes" : "No")<< ", Books Published: " << numBooks << endl;
    }

    double calculatePayment() const {
    double baseSalary = 50000;
   return baseSalary;
}
};

class Course {
private:
    string code;
    string title;
    int credits;
    string description;
    Professor* instructor; 

public:
    void assignInstructor(Professor* prof) {
        instructor = prof;
    }

    void dispCourse() {
        cout << "Code: " << code << "\nTitle: " << title << "\nCredits: " << credits << "\nDescription: " << description << endl;
        if (instructor) {
            cout << "--- Instructor Info ---\n";
            instructor->displayDetails();
        }
    }

    Course();
    Course(string code,string title,int credits,string description);
    ~Course();
    void setCourse(string c,string t,int cred,string des);
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

    Course::~Course(){
        cout<<"Course Destructor is called .....\n";
    }


class Classroom {
private:
    string roomNumber;
    int capacity;
    string building;
    Classroom* classroom; // Pointer to another classroom (though this is semantically unclear)

public:
    Classroom() : roomNumber(""), capacity(0), building(""), classroom(nullptr) {}

    Classroom(string roomNumber, int capacity, string building)
        : roomNumber(roomNumber), capacity(capacity), building(building), classroom(nullptr) {}

    void assignClassroom(Classroom* room) {
        classroom = room;
    }

    void displayClassroom() {
        cout << "Room Number: " << roomNumber << "\nCapacity: " << capacity << "\nBuilding: " << building << endl;
        if (classroom) {
            cout << "--- Assigned Classroom Info ---\n";
            classroom->displayClassroom();
        }
    }
};

class Student : public Person {
private:
    string edate;
    string program;
    float gpa;
    vector<Course*> enrolledCourses; 
public:
    void enrollInCourse(Course* course) {
        enrolledCourses.push_back(course);
    }

    void listCourses() {
        for (auto* c : enrolledCourses) {
            c->dispCourse();
        }
    }

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

class UndergraduateStudent : public Student{
    protected:
    string major;
    string minor;
    string expectedGraduation;

    public:
    UndergraduateStudent(string name, int age, string id, long long contact,string edate, string program,float gpa,string major, string minor, string expectedGrad): Student(name, age, id, contact, edate, program,gpa),major(major), minor(minor), expectedGraduation(expectedGrad) {}
    
    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor << ", Expected Graduation: " << expectedGraduation << endl;
    }

    float calculatePayment() override {
        return 50000.0f;
    }
};

#include <string>

class GraduateStudent : public Student {
private:
    bool isTeachingAssistant;     
    bool isResearchAssistant;      
    double teachingStipend;        
    double researchStipend;        
    std::string assignedCourse;    
    std::string researchProject;   

public:
    GraduateStudent(std::string name, int age, double teachingStipend = 0, double researchStipend = 0)
        : Student(name, age), isTeachingAssistant(false), isResearchAssistant(false),
          teachingStipend(teachingStipend), researchStipend(researchStipend) {}

    void assignTeachingAssistantship(std::string course, double stipend) {
        isTeachingAssistant = true;
        assignedCourse = course;
        teachingStipend = stipend;
    }

    void assignResearchAssistantship(std::string project, double stipend) {
        isResearchAssistant = true;
        researchProject = project;
        researchStipend = stipend;
    }

    bool isTA() const { return isTeachingAssistant; }
    bool isRA() const { return isResearchAssistant; }
    double getTeachingStipend() const { return teachingStipend; }
    double getResearchStipend() const { return researchStipend; }
    std::string getAssignedCourse() const { return assignedCourse; }
    std::string getResearchProject() const { return researchProject; }
    
    void displayDetails() const override {
        Student::displayDetails();
        if (isTA()) {
            std::cout << "Teaching Assistant for: " << assignedCourse << "\n";
            std::cout << "Teaching Stipend: $" << teachingStipend << "\n";
        }
        if (isRA()) {
            std::cout << "Research Assistant for: " << researchProject << "\n";
            std::cout << "Research Stipend: $" << researchStipend << "\n";
        }
    }
};




class Department {
private:
    string name;
    string location;
    long long int budget;
    vector<Professor> professors; 

public:
    void addProfessor(const Professor& prof) {
        professors.push_back(prof);
    }

    void listProfessors() {
        for (const auto& prof : professors) {
            prof.displayDetails();
        }
    }
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

class University {
private:
    string name;
    vector<Department> departments;

public:
    University(string name) : name(name) {}

    void addDepartment(const Department& dept) {
        departments.push_back(dept);
    }

    void removeDepartment(const string& deptName) {
        departments.erase(remove_if(departments.begin(), departments.end(),
            [&deptName](const Department& d) { return d.getName() == deptName; }), departments.end());
    }

    void listAllProfessors() {
        for (auto& dept : departments) {
            dept.listProfessors();
        }
    }

    void displayUniversityInfo() {
        cout << "University Name: " << name << "\nDepartments:\n";
        for (auto& dept : departments) {
            dept.dispDepartment();
        }
    }
};

class Schedule {
private:
    struct Slot {
        string day;
        string time;
        Course* course;
        Classroom* room;
    };

    vector<Slot> slots;

public:
    void addSlot(const string& day, const string& time, Course* course, Classroom* room) {
        slots.push_back({day, time, course, room});
    }

    void displaySchedule() {
        for (auto& slot : slots) {
            cout << slot.day << " at " << slot.time << ":\n";
            slot.course->dispCourse();
            slot.room->displayClassroom();
            cout << endl;
        }
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
