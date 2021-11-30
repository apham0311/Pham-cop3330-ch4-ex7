/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Anh Pham
 */

#include "std_lib_facilities.h"

vector<string> numbers;

int getNumber() {
    const int not_a_symbol = numbers.size();

    int val = not_a_symbol;
    if (cin>>val) return val;

    cin.clear();
    string s;
    cin>>s;
    for (int i=0; i<numbers.size(); ++i)
        if (numbers[i]==s) val = i;
    if (val==not_a_symbol) error("unexpected number string: ",s);
    return val;
}

//Translate numbers to words
void numbersToWords()
{
    numbers.push_back("zero");
    numbers.push_back("one");
    numbers.push_back("two");
    numbers.push_back("three");
    numbers.push_back("four");
    numbers.push_back("five");
    numbers.push_back("six");
    numbers.push_back("seven");
    numbers.push_back("eight");
    numbers.push_back("nine");
    numbers.push_back("ten");
}

int main()
try
{
    numbersToWords();

    cout<< "Please enter two numbers with operator in between\n The operator can be + - * / % : ";

    while (true) {
        int val1 = getNumber();

        char op = 0;
        cin>>op;

        int val2 = getNumber();

        string oper;
        double result;
        //For calculator function
        switch (op) {
            case '+':
                oper = "sum of ";
                result = val1+val2;
                break;
            case '-':
                oper = "difference between ";
                result = val1-val2;
                break;
            case '*':
                oper = "product of ";
                result = val1*val2;
                break;
            case '/':
                oper = "ratio of ";
                if (val2==0) error("Cannot divide by zero");
                result = val1/val2;
                break;
            case '%':
                oper = "remainder of ";
                if (val2==0) error("Cannot divide by zero");
                result = val1%val2;
                break;
            default:
                error("bad operator");
        }
        cout << oper << val1 << " and " << val2 << " is " << result << '\n';
        cout << "Try again: ";
    }
}
catch (runtime_error e) {
    cout << e.what() << '\n';
    keep_window_open("Stop");
}
catch (...) {
    cout << "exiting\n";
    keep_window_open("Stop");
}