struct Dis
{
    string discipline;
    int semester;
    int grade;
};

class Stud 
{
    public:
        string getSurname() const;
        unsigned int getCode() const;
    private:
        string surname;
        unsigned int code;
        vector <Dis> disciplines;
};