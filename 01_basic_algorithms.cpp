#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //початок завдання 1

    cout << "TASK 1." << endl << endl;

    int base;
    long long num, i, res = 0;
    cout << "Enter number and press Enter: ";
    cin >> num;
    if (num < 1) {
        cout << "Please, enter the number which is greater than 1 and press Enter: ";
        cin >> num;
    }
    cout << "Enter base from 2 to 9 and press Enter: ";
    cin >> base;
    while ((base < 2) || (base > 9)) {
        cout << "Sorry, we can't solve this problem. Please, enter base from 2 to 9 and press Enter: ";
        cin >> base;
    }
    for(i = 0; num != 0; i++) {
        res += (num % base) * pow(10, i);
        num /= base;
    }
    cout << "Your number in the new number system: " << res << endl;

    cout << "-------------------------------------------------------------------------------" << endl << endl;




    //кінець завдання 1, початок завдання 2





    cout << "TASK 2." << endl << endl;

    int sum1 = 0, sum2 = 0;
    bool not_prime;
    cout << "Enter the number and press Enter: ";
    cin >> num;
    while (num != 0) {
        // перевірка, чи є число простим
        not_prime = true;
        if (num == 1) {
            not_prime = false;
        }
        for (int i = 2; i <= sqrt(num); i++) {
            if ((num % i) == 0) {
                not_prime = false;
            }
        }
        //сума простих чисел
        if (not_prime) {
            sum1 += num;
        }
        // сума чисел, кратних двом
        if (num % 2 == 0) {
            sum2 += num;
        }
        cout << "Enter another number and press Enter (if you want to see the sums enter zero): ";
        cin >> num;
    }
    cout << "The sum of prime numbers is: " << sum1 << endl;
    cout << "The sum of numbers multiple by 2 is: " << sum2 << endl;

    cout << "-------------------------------------------------------------------------------"  << endl << endl;




    //кінець завдання 2, початок завдання 3




    cout << "TASK 3." << endl << endl;

    sum1 = 0;
    sum2 = 0;
    for (int i = 0; i <= 100; i++) {
        //сума чисел, що діляться на 10
        if (i % 10 == 0) {
            sum1 += i;
        }
        //сума чисел, що не діляться на 7
        if (i % 7 != 0) {
            sum2 += i;
        }
    }
    cout << "Sum of all numbers which are multiple by 10: " << sum1 << endl;
    cout << "Sum of all numbers which are NOT multiple by 7: " << sum2 << endl;

    cout << "-------------------------------------------------------------------------------"  << endl << endl;




    //кінець завдання 3, початок завдання 4




    cout << "TASK 4." << endl << endl;

    int num1, num2;
    bool growing;
    growing = false;
    cout << "Enter the number and press Enter: ";
    cin >> num1;
    while (num1 == 0) {
        cout << "Zero identify the end of the sequence. Please, enter another number and press Enter: ";
        cin >> num1;
    }
    cout << "Enter another number and press Enter: ";
    cin >> num2;
    while (num2 == 0) {
        cout << "It's not the sequence. Please, enter another number and press Enter: ";
        cin >> num2;
    }
    while (num2 != 0) {
        if (num2 < num1) {
            num1 = num2;
        }
        else {
            growing = true;
        }
        cout << "Enter another number and press Enter (if you want to see if your sequence is falling, enter zero): ";
        cin >> num2;
    }
    if (!growing) {
        cout << "The sequence IS falling" << endl;
    }
    else {
        cout << "The sequence IS NOT falling" << endl;
    }

    cout << "-------------------------------------------------------------------------------" << endl << endl;




    //кінець завдання 4, початок завдання 5




    cout << "TASK 5." << endl << endl;

    string str1, str2;
    int max_l = 0;
    cout << "Enter the string and press Enter: ";
    cin >> str1;
    while (str1 == "finish") {
        cout << "'finish' identify the end of the sequence. Please, enter another string and press Enter: ";
        cin >> str1;
    }
    cout << "Enter another string and press Enter: ";
    cin >> str2;
    max_l = str1.length();
    if (str1.length() > str2.length()) {
            max_l = str1.length();
        }
    else {
            max_l = str2.length();
        }
    if (str2 == "finish") {
        max_l = str1.length();
    }
    while (str2 != "finish") {
        if (str2.length() > max_l) {
            max_l = str2.length();
        }
        cout << "Enter another string and press Enter (if you want to see the length of the longest string, enter 'finish'): ";
        cin >> str2;
    }
    cout << "The length of the longest string is: " << max_l << endl;

    cout << "-------------------------------------------------------------------------------" << endl << endl;




    //кінець завдання 5, початок завдання 6




    cout << "TASK 6." << endl << endl;

    growing = true;
    cout << "Enter the string and press Enter: ";
    cin >> str1;
    while (str1 == "finish") {
        cout << "'finish' identify the end of the sequence. Please, enter another string and press Enter: ";
        cin >> str1;
    }
    cout << "Enter another string and press Enter: ";
    cin >> str2;
    while (str2 == "finish") {
        cout << "It's not the sequence. Please, enter another number and press Enter: ";
        cin >> str2;
    }
    while (str2 != "finish") {
        if (str2.length() > str1.length()) {
            str1 = str2;
        }
        else {
            growing = false;
        }
        cout << "Enter another string and press Enter (if you want to see if your sequence is growing, enter 'finish'): ";
        cin >> str2;
    }
    if (growing) {
        cout << "The sequence of strings IS growing" << endl;
    }
    else {
        cout << "The sequence of string IS NOT growing" << endl;
    }

    cout << "-------------------------------------------------------------------------------" << endl << endl;




    //кінець завдання 6
}