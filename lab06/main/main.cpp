#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <iomanip>

#include "../../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

void p0101()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << "found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << "found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

bool isEven(int n)
{
    return n % 2 == 0;
}

// functor, function object
struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};

void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << "found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << "found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

// void p0201()
// {
//     vector<int> a = {3, 1, 20, 4, 7, 0, 5};

//     // IsEven pred;
//     // cout << boolalpha;
//     // cout << pred(5) << endl;
//     // cout << string(40, '-') << endl;

//     auto it = find_if(begin(a), end(a), IsEven());
//     if (it != end(a))
//     {
//         cout << *it << " found. Its index is " << it - begin(a) << "\n";
//     }
//     else
//     {
//         cout <<  "No even numbers are found\n";
//     }
// }

void p0202()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    auto it = find_if(begin(a), end(a),
                      [](int n) // lambda expression
                      { return n % 2 == 0; });
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even numbers are found\n";
    }
}

void p06()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    cout << "- - -" << endl;
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });

    cout << "- - -" << endl;
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

struct GreaterThan
{
    int mX;
    GreaterThan(int x) : mX(x){};
    bool operator()(int n) const
    {
        return n > mX;
    }
};

void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    cout << "Enter x: ";
    int x;
    cin >> x;

    auto it = find_if(begin(a), end(a),
                      [x](int n)
                      { return n > x; });
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even numbers are found\n";
    }

    // GreaterThan pred(x);
    auto it2 = find_if(begin(a), end(a), GreaterThan(x));
    if (it2 != end(a))
    {
        cout << *it2 << " found. Its index is " << it2 - begin(a) << "\n";
    }
    else
    {
        cout << "No even numbers are found\n";
    }
}

void p07()
{
    vector<Student> students = {
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0},
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0},
        {"StudentR", 4.0},
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0}};

    cout << "--- regular sort by name ---" << endl;

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "--- regular sort by gpa ---" << endl;

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mGpa < s2.mGpa; });

    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "--- stable sort by name ---" << endl;

    stable_sort(begin(students), end(students),
                [](const Student &s1, const Student &s2)
                { return s1.mName < s2.mName; });

    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "--- stable sort by gpa ---" << endl;

    stable_sort(begin(students), end(students),
                [](const Student &s1, const Student &s2)
                { return s1.mGpa < s2.mGpa; });

    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

void p08()
{
    vector<pair<string, double>> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students));

    cout << "- - -" << endl;
    cout << fixed << showpoint << setprecision(2);
    for (const auto &[studName, studGpa] : students)
    {
        cout << studName << ", " << studGpa << endl;
    }
}
int main()
{
    // p0101();
    // p0102();

    // p0201();
    // p0202();

    // p03();
    // p06();
    // p07();
    p08();
}