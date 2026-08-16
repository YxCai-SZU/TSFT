#include <stdbool.h>

/*@ predicate is_negative(integer number) = number < 0; */

/*@ requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1 || \result == 5 || \result == 6 || 
            \result == 3 || \result == 9 || \result == 8 || \result == 4 || 
            \result == 2 || \result == 7;
    assigns \nothing;
 */
int func(int n)
{
    int result = 0;
    bool multiple_of_3 = false;
    bool multiple_of_5 = false;
    int temp = 0;

    if (n == 1) {
        result = 1;
    } else if (n == 2) {
        result = 5;
    } else if (n == 3) {
        result = 6;
    } else if (n == 4) {
        result = 3;
    } else if (n == 5) {
        result = 9;
    } else if (n == 6) {
        result = 8;
    } else if (n == 7) {
        result = 4;
    } else if (n == 8) {
        result = 2;
    } else if (n == 9) {
        result = 7;
    } else if (n == 10) {
        result = 2;
    } else {
        // Check if n is a multiple of 3
        temp = n;
        /*@ loop invariant 1 <= n <= 100;
            loop invariant 0 <= temp <= n;
            loop invariant temp % 3 == n % 3;
            loop assigns temp;
            loop variant temp;
         */
        while (temp >= 3) {
            temp -= 3;
        }
        //@ assert temp == n % 3;
        if (temp == 0) {
            multiple_of_3 = true;
        }

        // Check if n is a multiple of 5
        temp = n;
        /*@ loop invariant 1 <= n <= 100;
            loop invariant 0 <= temp <= n;
            loop invariant temp % 5 == n % 5;
            loop assigns temp;
            loop variant temp;
         */
        while (temp >= 5) {
            temp -= 5;
        }
        //@ assert temp == n % 5;
        if (temp == 0) {
            multiple_of_5 = true;
        }

        if (multiple_of_3 && multiple_of_5) {
            result = 8;
        } else if (multiple_of_3) {
            result = 1;
        } else if (multiple_of_5) {
            result = 6;
        } else {
            result = 0;
        }
    }
    //@ assert result == 0 || result == 1 || result == 5 || result == 6 || result == 3 || result == 9 || result == 8 || result == 4 || result == 2 || result == 7;
    return result;
}

/*@ requires \true;
    ensures \result == (number < 0);
    assigns \nothing;
 */
bool is_negative(long long number)
{
    return number < 0;
}

int main()
{
    return 0;
}
