#include <iostream>
using namespace std;
void print(int&) { cout << "rvalue\n";}
void print(int&&) { cout << "lvalue\n";}

class Numbers
{
    double* m_data{};
    size_t m_cnt;

public:
    Numbers(size_t cnt) : m_cnt{cnt}
    {
        m_data = new double[m_cnt] {};
        for (auto i = 0u; i < m_cnt; ++i)
        {
            m_data[i] = i + 0.5;
        }
    }
    //rules of three
    Numbers(const Numbers& that) //Must receive by a reference
    {
        m_data = nullptr;
        *this = that;
    }
    ~Numbers()
    {
        delete[]m_data;
    }
    Numbers& operator=(const Numbers& that)
    {
        //1. Check for self assignment
        if (this != &that)
        {
            //2. Deallocate the current instance
            delete[] m_data;

            //3. Shallow copy
            this->m_cnt = that.m_cnt;

            //4. Deep copy
            if (that.m_data != nullptr)
            {
                m_data = new double[m_cnt];
                for (auto i = 0u; i < m_cnt; ++i)
                {
                    m_data[i] = that.m_data[i];
                }
            }
            else
            {
                m_data = nullptr;
            }
            return *this;
        }
    }

     // move constructor
    Numbers(Numbers&& that)
    {
        *this = move(that);   // std::move() doesnt move anything
    }

    // move assignment
    Numbers& operator=(Numbers&& that)
    {
        //1. Check for self assignment
        if (this != &that)
        {
            //2. Deallocate the current instance
            delete[] m_data;

            //3. Shallow copy
            this->m_cnt = that.m_cnt;

            //4. Move resource
            this->m_data = that.m_data; // or string copy
            that.m_data = nullptr;
            that.m_cnt = 0;
        }
        return *this;
    }
};





struct Foo
{
    double m_data = 123.321;
    operator int() const
    {
        return static_cast<int>(m_data);
    }
    Foo(){cout << "[" << this << "] is built." << endl; }
    ~Foo(){cout << "[" << this << "] is removed." << endl; }

};

Foo getData()
{
    Foo aFoo;

    aFoo.m_data=5;

    return aFoo; // a Foo is at the end of its life
}

int main (int, char**)
{
    int data = 12;
    print(10);          // rvalue
    print(data);        // lvalue
    print(Foo());
    print(data + 10);   // rvalue: return that local variable since it isnt modified
    print(data += 10);  // lvalue: since it is modified
    print(++data);      // lvalue: return the current instance
    print(data++);      // rvalue
    return 0;
}
