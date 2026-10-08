class Group
{
    public:
        Group();
        Group (Group && other);
        ~Group();
        Group operator = (Group && other) noexcept;
        vector <pair <string, int>> getLowestAverageGrades() const;
        int getHighestGrade (pair <string, unsigned int> studentInfo) const;
        void addDisciplineData (pair <string, unsigned int> studentInfo, Dis discipline);
        bool operator + (pair <string, unsigned int> studentInfo);
        void removeStudent (pair <string, unsigned int> studentInfo);
        istream & operator << (istream & in, Group & group);
    private:
        string group;
        struct Node 
        {
            Stud student;
            Node * next;
        };
        Node * first;
        Node * last;
        int numStudents;
};