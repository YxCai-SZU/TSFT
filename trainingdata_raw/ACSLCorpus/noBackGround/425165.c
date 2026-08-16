#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == 1 <==> ((((n)) / 100) == 7 ||
        ((((n)) / 10) % 10) == 7 ||
        (((n)) % 10) == 7);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    bool result = false;
    unsigned long num = n;
    unsigned long last_digit;
    unsigned long middle_digit;
    unsigned long first_digit;

    // Extract the last digit
    last_digit = num % 10;
    //@ assert last_digit == ((n) % 10);
    if (last_digit == 7) {
        result = true;
    }

    // Remove the last digit
    num = num / 10;

    // Extract the middle digit
    middle_digit = num % 10;
    //@ assert middle_digit == (((n) / 10) % 10);
    if (middle_digit == 7) {
        result = true;
    }

    // Remove the middle digit
    num = num / 10;

    // Extract the first digit
    first_digit = num;
    //@ assert first_digit == ((n) / 100);
    if (first_digit == 7) {
        result = true;
    }

    //@ assert result == 1 <==> (first_digit == 7 || middle_digit == 7 || last_digit == 7);
    return result;
}
