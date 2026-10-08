string Stud::getSurname() const
{
    return surname;
}

int Stud::getCode() const
{
    return code;
}

Group::Group (Group && other) noexcept
{
    group = move (other.group);
    first = other.first;
    last = other.last;
    numStudents = other.numStudents;

    other.first = nullptr;
    other.last = nullptr;
    other.numStudents = 0;
}

Group::~Group()
{
    Node * current = first;
    while (current != nullptr)
    {
        Node * next = current -> next;
        delete current;
        current = next;
    }
}

void Group::addDisciplineData (pair <string, unsigned int> studentInfo, Dis discipline)
{
    string surname = studentInfo.first;
    unsigned int code = studentInfo.second;

    Node * current = first;
    while (current != nullptr)
    {
        if ((current -> student.getSurname() == surname) && (current -> student.getCode() == code))
        {
            current -> student.addDisciplineData (surname, code, discipline);
            return;
        }
        current = current -> next;
    }

    // Якщо студента не знайдено, виводимо повідомлення
    cout << "Student not found" << endl;
}