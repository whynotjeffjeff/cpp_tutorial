#include <iostream>
#include <mutex>
#include <string>
#include <thread>

thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string &thread_name)
{
    ++rage;
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << thread_name << "counter: " << rage << '\n';
}

void storage_duration_1()
{
    std::thread a(increase_rage, "a"), b(increase_rage, "b");
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "main counter: " << rage << '\n';
    }
    a.join();
    b.join();
}

void static_and_dynamic_1()
{
    const int k_num = 10;
    struct X
    {
        int n;
    };
    constexpr std::array<int, 3> k_array = {1, 2, 3};
}

void foo()
{
    static const char *const k_messages[] = {"hello", "world"};
}

std::string strcat(std::string s1, std::string s2, std::string s3)
{
    return s1 + s2 + s3;
}

void static_and_dynamic_2()
{
    const std::string k_foo = "foo";
    const std::string  &k_bar = strcat("a", "b", "c\n");
}

#include <map>
void bar()
{
    static  std::map<int, int> k_data = {{1, 0}, {2, 0}, {3, 0}};
}

int f()
{
    return rand();
}

struct Foo
{
    int val;
    char data;
};

struct Bar
{
    int val;
};

Bar g()
{
    Bar bar;
    bar.val = 0;
    return bar;
}

void initializer_1()
{
    int n = 5;
    int m = f();
    Foo x;
    Bar bar = g();
}

struct Foo_ {constexpr Foo_(int) {} };

void initializer_2()
{
    int n = 5;
    Foo_ x(2);
    Foo_ a[] = {Foo_(1), Foo_(2), Foo_(3)};
}

void initializer_3()
{
    time_t time(time_t *);
    int f();
};

struct Bar_ { Bar_() {} };

void initializer_4()
{
    time_t m = time(nullptr);
    Foo_ y(f());
    Bar_ b;
}



int main()
{
    storage_duration_1();
    static_and_dynamic_1();
    static_and_dynamic_2();
    initializer_1();
    initializer_2();
    initializer_3();
    initializer_4();
    return 0;
}
