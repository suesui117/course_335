#include <iostream>



class Sue
{

    public:

        Sue() : name_(""), age_(0), contacts_() 
        {
            std::cout << "Default constructor called, vector size: " << contacts_.size() << "\n";
        }; // default

        Sue(std::string input_name, int input_age, std::vector<std::string> in_vec) : name_(input_name), age_(input_age), contacts_(in_vec)
        {
            std::cout << "Parameterized constructor called, vector size: " << contacts_.size() << "\n";
        } // parameterized


        Sue(const Sue& another)
        {
            name_ = another.name_;
            age_ = another.age_;
            contacts_ = another.contacts_;
            std::cout << "Copy constructor called, vector size: " << contacts_.size() << "\n";
        } // copy constructor, original passed by referece

        ~Sue()
        {
            contacts_.clear();
            std::cout << "destructor called " << contacts_.size() << "\n";

        }; // destructor

        

        int getAge() { return age_; } // getter

        void setAge(const int in_age) { age_ = in_age; } // setter

        std::vector<std::string>& getVector() { return contacts_;}

    private:
        std::string name_;
        int age_;
        std::vector<std::string> contacts_;
};

int main()
{

    std::vector<std::string> vec {"andy", "joe", "tony"};

    Sue defaultC;
    Sue parameterC("BLAH", 100, vec);
    Sue copyC(parameterC);
    std::cout << copyC.getAge() << "\n";
    std::cout << parameterC.getAge() << "\n";

    return 0;

    // (3,4), (2,1)
    // (1,2)

    // (4,6), (2,1) result

    // friend function: have access to private members of the current class
}

