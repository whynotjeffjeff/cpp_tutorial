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

void foo_()
{
    ;
}

void baz()
{
    int a;
    a = 4;
    int &b{a};
    b = 5;
    const int& c{a};
    // c = 6;
    void (*p)() = &foo_;
    // foo_ = baz;
}

void value_category_1()
{
    baz();
}

struct S
{
    S() : m{42} {}
    S(int a) : m{a} {}
    int m;
};

void value_category_2()
{
    S s;
    s = S{};
    std::cout << s.m << '\n';
    std::cout << (S{} = S{7}).m << '\n';
}

#include <type_traits>
#include <utility>
template <class T> struct is_prvalue : std::true_type {};
template <class T> struct is_prvalue<T&> : std::false_type {};
template <class T> struct is_prvalue<T&&> : std::false_type {};

template <class T> struct is_lvalue : std::false_type {};
template <class T> struct is_lvalue<T&> : std::true_type {};
template <class T> struct is_lvalue<T&&> : std::false_type {};

template <class T> struct is_xvalue : std::false_type {};
template <class T> struct is_xvalue<T&> : std::false_type {};
template <class T> struct is_xvalue<T&&> : std::true_type {};

void value_category_3()
{
    int a{42};
    int& b{a};
    int&& r{std::move(a)};

    // 表达式 `42` 是纯右值
    static_assert(is_prvalue<decltype((42))>::value);

    // 表达式 `a` 是左值
    static_assert(is_lvalue<decltype((a))>::value);

    // 表达式 `b` 是左值
    static_assert(is_lvalue<decltype((b))>::value);

    // 表达式 `std::move(a)` 是亡值
    static_assert(is_xvalue<decltype((std::move(a)))>::value);

    // 变量 `r` 的类型是右值引用
    static_assert(std::is_rvalue_reference<decltype(r)>::value);

    // 变量 `b` 的类型是左值引用
    static_assert(std::is_lvalue_reference<decltype(b)>::value);

    // 表达式 `r` 是左值
    static_assert(is_lvalue<decltype((r))>::value);
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
    value_category_1();
    value_category_2();
    value_category_3();
    return 0;
}
