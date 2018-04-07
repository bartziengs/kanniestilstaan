#include <iostream>
#include <memory>

class Container
{
  public:
    // constructors

    //1.  Create a default constructor,
    Container()
    {
        length = 0;
        data = nullptr;
        print("default constructor");
    }

    //2.  Create a constructor that takes one `int` argument that holds the length of
    Container(int length)
        : length(length), data(new double[length])
    {
        print("constructor that takes one int");
    }
    //3.  Create a constructor that takes an `std::initializer_list<double>`.
    Container(std::initializer_list<double> l)
        : Container((int)l.size())
    {
        std::uninitialized_copy(l.begin(), l.end(), data);
        print("constructor that takes a list");
    }

    //4.  Create a copy constructor that takes a `Container` argument.
    Container(const Container &c)
        : Container(c.length)
    {
        for (auto i = 0; i < c.length; i++){
            data[i] = c.data[i];
        }
        print("copy constructor");
    }

    //5.  Create a move constructor that takes a `Container` argument.
    Container(Container &&c)
        : length(c.length), data(c.data)
    {
        c.length = 0;
        c.data = nullptr;
        print("move constructor");
    }

    //7.  Create a copy assignment operator.
    Container &operator=(const Container &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new double[other.length];
            length = other.length;
            for (auto i = 0; i < length; i++)
                data[i] = other.data[i];
        }
        print("copy assignment operator");
        return *this;
    }
    //8.  Create a move assignment operator.
    Container &operator=(Container &&other)
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
            length = other.length;
            other.length = 0;
        }
        print("move assignment operator");
        return *this;
    }
    
    // destructor
    //6.  Create a destructor that `delete[]`s the `data` attribute.
    ~Container()
    {
        delete[] data;
        length = 0;
        print("destructor");
    }
    // operators
    //9.  Create an `operator+` that takes one `Container` argument.
    Container operator+(Container other){
        Container c;
        c = std::move(other);
        for(int i; i < length; i++){
            c.data[i]+=data[i];
        }
        print("+operator");
        return c;
    }
    void print(const std::string &info) const
    {
        // print the address of this instance, the attributes `length` and
        // `data` and the `info` string
        std::cout << "  " << this << " " << length << " " << data << "  "
                  << info << std::endl;
    }

  private:
    int length;
    double *data;
};

int main()
{
    std::cout << "Container a({ 1, 2, 3 });" << std::endl;
    Container a({1, 2, 3}); //calls constructor that takes a list and subsequently the one taking a int (implemented constructor)
    std::cout << "  a has address " << &a << std::endl;
    std::cout << "Container b = { 4, 5, 6 };" << std::endl;
    Container b = {4, 5, 6};//calls constructor that takes a list and also the int one
    std::cout << "  b has address " << &b << std::endl;
    std::cout << "Container c(a);" << std::endl;
    Container c(a); //calls copy constructor and the int constructor
    std::cout << "  c has address " << &c << std::endl;
    std::cout << "Container d = a + b;" << std::endl;
    Container d = a + b; //calls operator, move assignment, then default for and copies it to d.
    std::cout << "  d has address " << &d << std::endl;
    std::cout << "Container e;" << std::endl;
    Container e;  // this is just plain default constructor.
    std::cout << "  e has address " << &e << std::endl;
    std::cout << "e = a + b;" << std::endl;
    e = a + b; //calls move (from =) then + operator, then move agian, copy constructor and one taking a int
    std::cout << "Container f(std::move(a + b));" << std::endl;
    Container f(std::move(a + b)); //calls move constructor, then operator for a + b) then move assignment (for f) n, which calls copy then the int one.
    std::cout << "  f has address " << &f << std::endl;
    std::cout << "Container g = a + b + c;" << std::endl;
    Container g = a + b + c; // +,move,+,move, default, copy , 1 int, copy , 1 int.
    std::cout << "  g has address " << &g << std::endl;
    std::cout << "Container h;" << std::endl;
    Container h; //default
    std::cout << "  h has address " << &h << std::endl;
    std::cout << "h = a + b + c;" << std::endl;
    h = a + b + c;  //move,+,move,+ copy, int , copoy , int
    std::cout << "Container i = { a + b + c };" << std::endl;
    Container i = {a + b + c};//+,move,+,move,copy, one int
    std::cout << "  i has address " << &i << std::endl;
    std::cout << "end" << std::endl;

    return 0;
}