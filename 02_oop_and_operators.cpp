//Restaurant menu - A class that represents a restaurant menu, with attributes such as name, description, price, and ingredients for each item.

class RestaurantMenu
{
    private:
        string name;
        string description;
        double price;
        vector <string> ingredients;
    public:
        
        //constructor
        RestaurantMenu(string name, string description, double price, vector <string> ingredients)
        {
            this -> name = name;
            this -> description = description;
            this -> price = price;
            this -> ingredients = ingredients;
        }
        
        //getters and setters
        string getName()
        { 
            return name; 
        }
        void setName(string name) 
        {
        this -> name = name;
        }
        string getDescription()
        { 
            return description; 
        }
        void setDescription(string description) 
        {
        this -> description = description;
        }
        double getPrice()
        { 
            return price; 
        }
        void setPrice(double price) 
        {
        this -> price = price;
        }
        vector <string> getIngredients()
        { 
            return ingredients; 
        }
        void setIngredients(vector <string> ingredients) 
        {
        this -> ingredients = ingredients;
        }
        
        //method1: Creates a combination of 2 dishes
        RestaurantMenu createCombination(RestaurantMenu other)
        {
            string newName = name + " " + other.name;
            string newDescription = description + " " + other.description;
            double newPrice = (price + other.price) / 2;
            vector <string> newIngredients = ingredients;
            for (int i = 0; i < other.ingredients.size(); i++)
            {
                newIngredients.push_back(other.ingredients[i]);
            }
            RestaurantMenu combination(newName, newDescription, newPrice, newIngredients);
            return combination;
        }
        
        //method2: If one of the ingredients in the menu is an orange, print: "This dish has an orange in it. Since you are allergic, this dish is not suitable for you".If not print: "This dish is suitable for you"
        int isAllergenic()
        {
            for (string ingredient : ingredients)
            {
                if (ingredient == "orange")
                {
                    cout << "This dish has an orange in it. Since you are allergic, this dish is not suitable for you";
                    return 0;
                }
            }
            cout << "This dish is suitable for you";
        }
};

//Overloading of comparison operators (>, <, >=, <=)
class Student 
{
    private: 
        string name;
        int size;
        int *marks = new int(size);
    
    public: 
        string getName()
        {
            return name;
        }
    
        void setName(string name)
        {
            this -> name = name;
        }
        
        void setMarks(int *arrmarks, int size)
        {
            for (int i = 0; i < size; i++) 
            {
                this -> marks[i] = arrmarks[i];
            }
        }
        
        Student (string name, int size)
        {
            this -> name = name;
            this -> size = size;
            this -> marks = new int[size];
        }
    
        double averageMarks() const
        {
            double sum = 0, avMarks;
            for (int i = 0; i < size; i++) 
            {
                sum += marks[i];
            }
            avMarks = sum / size;
            return avMarks;
        }
    
        Student(const Student &s1, int size)
        {
            this -> name = s1.name;
            this -> size = s1.size;
            this -> marks = new int[size];
            for (int i = 0; i < size; i++) 
            {
                this -> marks[i] = s1.marks[i];
            }
        }
        
        bool operator> (const Student& other) const
        {
            return averageMarks() > other.averageMarks();
        }
        
        bool operator< (const Student& other) const
        {
            return averageMarks() < other.averageMarks();
        }
        
        bool operator>= (const Student& other) const
        {
            return averageMarks() >= other.averageMarks();
        }
        
        bool operator<= (const Student& other) const
        {
            return averageMarks() <= other.averageMarks();
        }
};