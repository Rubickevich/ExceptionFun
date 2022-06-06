#include <iostream>
#include <string>
#include <vector>
class Country {
    int population;
    int wealth;
public:
    Country(int population, int wealth) :population(population), wealth(wealth) {}
    friend std::ostream& operator<< (std::ostream& out, const Country& p);
};
std::ostream& operator << (std::ostream& out, const Country& p)
{
    return out << "Country population is: " << p.population << " and wealth is: " << p.wealth << std::endl;
}
class MyExcept : public std::exception {
public:
    MyExcept(unsigned int errorPLace) : exception(std::string("Exception is found at line " + std::to_string(errorPLace)).c_str()) {}; 
};
int main()
{
    int a = 7;
	int b = 0;
	int c;
    try
    {
        if (b == 0)
            throw "can't divide by zero";
        c = a / b;
    }
    catch (const char* exception)
    {
	    std::cout << "Caught an exception: " << exception << std::endl;
    }
    try
    {
        if (b == 0)
            throw 0;
        c = a / b;
    }
    catch (const char* exception)
    {
	    std::cout << "Caught an exception: " << exception << std::endl;
    }
    catch (const int exception)
    {
	    std::cout << "Caught an exception: divider is " << exception << std::endl;
    }
    try
    {
        try
        {
            if (b == 0)
                throw 0;
            c = a / b;
        }
        catch (const char* exception)
        {
	        std::cout << "Caught an exception: " << exception << std::endl;
        }
    }
    catch (const int exception)
    {
	    std::cout << "Caught an exception: divider is " << exception << std::endl;
    }
    char* arr;
    try {
        arr = new char[INT_MAX];
        delete[] arr;
    }
    catch (std::bad_alloc& exception) {
	    std::cout << "Caught an exception: " << exception.what() << std::endl;
    }
    char* arr2;
    try {
        arr2 = new char[INT_MAX];
        delete[] arr2;
    }
    catch (std::exception& exception) {
	    std::cout << "Caught an exception: " << exception.what() << std::endl;
    }
    catch (...)
    {
	    std::cout << "Caught an unknown exception";
    }
    try
    {
        throw MyExcept(__LINE__);
    }
    catch (MyExcept& exception)
    {
	    std::cout << exception.what() << std::endl;
    }
    std::vector<int> vector = { 24,5,12,34,5 };
    try
    {
        vector.at(3) = 6;
    }
    catch (std::exception& exception)
    {
	    std::cout << "Caught an exception: " << exception.what() << std::endl;
    }
    Country country(11200, 7662);
    std::cout << country;
}