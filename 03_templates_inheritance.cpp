#include <iostream>
#include <string>

using namespace std;

template <class T>
class MyVector
{
    public:
        MyVector (int size)
        {
            this -> buffer_size = size;
            p = new T [this -> buffer_size];
        }
        void push_back (T a)
        {
            if (this -> size == this -> buffer_size)
            {
                this -> buffer_size *= 2;
                T * temp = new T [this -> buffer_size];
                for (int i = 0; i < size; i++) 
                {
                    temp[i] = p[i];
                }
                temp[this -> size] = a;
                this -> size++;
                delete [] p;
                this -> p = temp;
            }
            else
            {
                p[this -> size] = a;
                this -> size++;
            }

        }
        friend ostream & operator << (ostream & out, const MyVector <T> & v) 
        {
            for (int i = 0; i < v.size; i++) 
            {
                out << v.p[i];
            }
            return out;
        }
    private:
        T * p;
        int size = 0;
        int buffer_size = 0;
};

class Human
{
    public:
        Human (string name, string surname, int age) : name_(name), surname_(surname), age_(age) {}
        string getName() const
        {
            return name_;
        }
        string getSurname() const
        {
            return surname_;
        }
        int getAge() const
        {
            return age_;
        }
    protected:
        string name_;
        string surname_;
        int age_;
};

class Student : public Human
{
    public:
        Student (string name, string surname, int age, int group, int course) : Human (name, surname, age), group_(group), course_(course) {}
        int getGroup() const
        {
            return group_;
        }
        int getCourse() const
        {
            return course_;
        }
    private:
        int group_;
        int course_;
};

class Bachelor : public Student
{
    public:
        Bachelor (string name, string surname, int age, int group, int course, string bachelorDiploma) : Student (name, surname, age, group, course), bachelorDiploma_(bachelorDiploma) {}
        string getBachDiploma() const
        {
            return bachelorDiploma_;
        }
    private:
        string bachelorDiploma_;
};

class Master : public Bachelor
{
    public:
        Master (string name, string surname, int age, int group, int course, string bachelorDiploma, string masterDiploma) : Bachelor (name, surname, age, group, course, bachelorDiploma), masterDiploma_(masterDiploma) {}
        Master (int size) : Bachelor("", "", 0, 0, 0, ""), masterDiploma_("") {}
        Master() : Bachelor("", "", 0, 0, 0, ""), masterDiploma_("") {}
        string getMastDiploma() const
        {
            return masterDiploma_;
        }
        friend ostream & operator << (ostream & out, const Master & master)
        {
            out << "Name is: " << master.getName() << endl;
            out << "Surname is: " << master.getSurname() << endl;
            out << "Age is: " << master.getAge() << endl;
            out << "Group is: " << master.getGroup() << endl;
            out << "Course is: " << master.getCourse() << endl;
            out << "Dimploma1 is: " << master.getBachDiploma() << endl;
            out << "Dimploma2 is: " << master.getMastDiploma() << endl;
            out << "-----------------------------------------------------" << endl;
            return out;
        }
    private:
        string masterDiploma_;
};

int main()
{
    Master master1 ("Anna", "Yurevych", 17, 16, 1, "Creating desktop applications in python", "Online clothing store on PHP");
    Master master2 ("Max", "Lukovskiy", 18, 16, 1, "Dota2", "CS:GO");
    Master master3 ("Roman", "Pohribniak", 18, 16, 1, "The Impact of Artificial Intelligence on Modern Software Development", "Secure Software Development: Best Practices and Tools");
    MyVector <Master> masters(3);
    masters.push_back(master1);
    masters.push_back(master2);
    masters.push_back(master3);
    cout << masters;
    return 0;
}