/*Write a program that defines a vector of double. The program asks user to enter numbers
and stores the numbers in the vector. The program stops asking numbers when user enter
a negative number. The negative number is not stored the vector.
When program has finished asking numbers it sorts the numbers. After sorting the
program prints the numbers on separate lines with 3 decimal precision.
Iomanipulators can be used to change formatting of output (and input) streams. See
http://www.cplusplus.com/reference/iomanip/setprecision/ for an example.*/


#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#pragma warning (disable:4996)

using namespace std;

vector <double> number_input;

int main()
{
    cout<<"To stop the program type in a negative number!\n\n";
    cout<<"Please type a number: ";

    double user_input = 0;

    do
    {
        cin >> user_input;

        if (user_input < 0)
        {
            break;
        }
        else
        {
            printf("Please type another number: ");
            number_input.push_back(user_input);
        }
    }

    while (user_input >= 0);

    printf("\nNumbers sorted:\n\n");

    for (int i = 0; i < number_input.size(); ++i)
    {
        sort(number_input.begin(), number_input.end());
        cout << fixed;
        cout << setprecision(3) << number_input[i] << endl;
    }

    return 0;
}