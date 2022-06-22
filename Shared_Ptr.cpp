#include <iostream>
using namespace std;

template <typename T>
class my_shared_ptr
{
public:
    my_shared_ptr()
        : count(new int(0)), p(nullptr) {}

    my_shared_ptr(T *pt)
        : count(new int(1)), p(pt) {}

    my_shared_ptr<T> &operator=(T *pt)
    {
        shared_delete();
        count = new int(1);
        p = pt;
        return *this;
    }

    my_shared_ptr(const my_shared_ptr<T> &rhs)
    {
        count = rhs.count;
        p = rhs.p;
        ++(*count);
    }

    my_shared_ptr<T> &operator=(const my_shared_ptr<T> &rhs)
    {
        shared_delete();
        count = rhs.count;
        p = rhs.p;
        ++(*count);
        return *this;
    }

    ~my_shared_ptr()
    {
        shared_delete();
    }

    int use_count()
    {
        return *count;
    }

    T *get()
    {
        return p;
    }

    T *operator->()
    {
        return p;
    }

    T &operator*()
    {
        return *p;
    }

    operator bool()
    {
        return p;
    }

private:
    void shared_delete()
    {
        if (!p)
        {
            delete count;
        }
        else
        {
            --(*count);
            if (*count == 0)
            {
                delete count;
                delete p;
                cout << "deleted " << p << endl;
            }
        }
    }

    int *count;
    T *p;
};

int main()
{
    my_shared_ptr<int> ptr;
    if (!ptr)
    {
        cout << boolalpha << false << endl;
    }

    int *p = new int(42);
    ptr = p;

    my_shared_ptr<int> ptr0(ptr);
    my_shared_ptr<int> ptr1(new int(2));
    ptr0 = ptr1;
}