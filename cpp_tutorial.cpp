#include <iostream>
#include <climits>

void limits_3_1_()
{
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << sizeof(n_int) << " " << sizeof(n_short) << " ";
    cout << sizeof(n_long) << " " << sizeof(n_llong) << endl;
    cout << n_int << " " << n_short << " ";
    cout << n_long << " " << n_llong << " ";
    cout << INT_MIN << " " << CHAR_BIT << endl;
}

void initializer_3_2_1()
{
    int n_int = INT_MAX;
    int uncles = 5;
    int aunts = uncles;
    int chairs = uncles + aunts + 4;
    int owls = 101;
    int wrens(432);
    short years;
    years = 1492;

    int hamburgers = {24};
    int emus{7};
    int rheas = {12};
    int rocs = {};
    int psychics{};

}

#define ZERO 0
#include <climits>

void exceed_3_2_()
{
    using namespace std;
    short sam = SHRT_MAX;
    unsigned short sue = sam;
    cout << sam << " " << sue << endl;
    sam += 1;
    sue += 1;
    cout << sam << " " << sue << endl;
    sam = ZERO;
    sue = ZERO;
    cout << sam << " " << sue << endl;
    sam -= 1;
    sue -= 1;
    cout << sam << " " << sue << endl;
}

void hexoct_3_3_()
{
    using namespace std;
    int chest = 42;
    int waist = 0x42;
    int inseam = 042;
    cout << chest << " " << waist << " " << inseam << endl;
}

void hexoct2_3_4_()
{
    using namespace std;
    int cheat, waist, inseam;
    cheat = waist = inseam = 42;
    cout << cheat << " ";
    cout << hex;
    cout << waist << " ";
    cout << oct;
    cout << inseam << endl;
}

void chartype_3_5_()
{
    using namespace std;
    char ch;
    cin >> ch;
    cout << ch << endl;
}

void morechar_3_6_()
{
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout << ch << " : " << i << endl;
    ch += 1;
    i = ch;
    cout << ch << " : " << i << endl;
    cout.put(ch);
    cout.put('!');
}

void bondini_3_7_()
{
    using namespace std;
    cout << "\aOperation \HyperHype \" is now activated!\n";
    cout << "Enter your agent code :_______\b\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";
}

void float_alert_3_3()
{
    float f1, f2;
    f1 = 12.34;
    f2 = 2.52e+8;
}

void floatnum_3_8_()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double  mint = 10.0 / 3.0;
    const float million = 1.0e6;
    cout <<  tub << " " << mint * tub << " ";
    cout << 10 * million * tub << " " << mint << " " << million * mint << endl;
}

void float_constant_3_3_3()
{
    long double ld1, ld2, ld3, ld4;
    ld1 = 1.234f;
    ld2 = 2.45E20F;
    ld3 = 2.345324E28;
    ld4 = 2.2L;
}

void fltadd_3_9_()
{
    using namespace std;
    float a = 2.3E+22f;
    float b = a + 1.0f;
    cout << a << endl;
    cout << b - a << endl;
}

void arith_3_10_()
{
    using namespace std;
    float hats, heads;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cin >> hats;
    cin >> heads;
    cout << hats + heads << " " << hats - heads << " ";
    cout << hats * heads << " " << hats / heads << endl;
}

void divide_3_11_()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << 9 / 5 << endl;
    cout << 9.0 / 5.0 << endl;
    cout << 9L / 5L << endl;
    cout << 9.0 / 5 << endl;
    cout << 1.e7 / 9.0 << endl;
    cout << 1.e7f / 9.0f << endl;
}

void modulus_3_12_()
{
    using namespace std;
    const int Lbs_per_stn = 14;
    int lbs;
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;
    int pounds = lbs % Lbs_per_stn;
    cout << lbs << " " << stone << " " << pounds << endl;
}

void assign_3_13_()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess(3.9832);
    int debt = 7.2E12;
    cout << tree << endl;
    cout << guess << endl;
    cout << debt << endl;
}

void list_initialization_3_4()
{
    const int code = 66;
    int x = 66;
    // char c1{31325};
    char c2 = {66};
    char c3 = {code};
    // char c4 = {x};
    x = 31325;
    char c5 = x;
}

void convert_in_expression_3_4_3()
{
    using namespace std;
    short chicks = 20;
    short ducks = 35;
    short fowl = chicks + ducks;
    int thorn = 100;
    (long) thorn;
    (int) thorn;
    thorn = 99;
    // long (thorn);
    cout << int('Q');
    static_cast<long> (thorn);
    cout << thorn;
}

void typecast_3_14_()
{
    using namespace std;
    int auks, bats, coots;
    auks = 19.99 + 11.99;
    bats = (int) 19.99 + (int) 11.99;
    coots = int (19.99) + int (11.99);
    cout << auks << " " << bats << " ";
    cout << coots << endl;
    char ch = 'Z';
    cout << ch << " " << int(ch) << endl;
    cout << static_cast<int>(ch) << endl;
}

#include <vector>
void auto_3_4_5()
{
    using namespace std;
    auto n = 100;
    auto x = 1.5;
    auto y = 1.3e12L;
    auto x_ = 0.0;
    double y_ = 0;
    auto z = 0;
    vector<double> scores;
    auto pv = scores.begin();
    cout << sizeof(pv);
}

void arrayone_4_1_()
{
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;
    int yamcosts[3] = {20, 30, 5};
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << sizeof yams << " " << sizeof(yams[0]) << endl;
}

void cpp11_array_initializer_4_1_3()
{
    double earn[4] {1.2e4, 1.6e4, 1.1e4, 1.7e4};
    unsigned int counts[10] = {};
    float balances[100] {};
    // long plifs[] = {25, 92, 3.0};
    // char slifs[4] {'h', 'i', 1122011, '\0'};
    char tlifs[4] {'h', 'i', 112, '\0'};
}

int main()
{
    limits_3_1_();
    initializer_3_2_1();
    exceed_3_2_();
    hexoct_3_3_();
    hexoct2_3_4_();
    chartype_3_5_();
    morechar_3_6_();
    bondini_3_7_();
    float_alert_3_3();
    floatnum_3_8_();
    float_constant_3_3_3();
    fltadd_3_9_();
    arith_3_10_();
    divide_3_11_();
    modulus_3_12_();
    assign_3_13_();
    list_initialization_3_4();
    convert_in_expression_3_4_3();
    typecast_3_14_();
    arrayone_4_1_();
    cpp11_array_initializer_4_1_3();
    return 0;
}
