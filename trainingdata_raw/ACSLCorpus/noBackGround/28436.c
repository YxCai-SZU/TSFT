#include <stdbool.h>

/*@
    requires n >= 100 && n <= 999;
    ensures \result == ((n / 100) % 10 == n % 10);
    assigns \nothing;
*/
bool is_palindrome_func(unsigned int n)
{
    // Variable declarations at top of scope
    unsigned int hundreds_digit;
    unsigned int units_digit;
    bool ret;

    //@ assert n >= 100;
    //@ assert n <= 999;

    hundreds_digit = (n / 100) % 10;
    units_digit = n % 10;
    ret = (hundreds_digit == units_digit);

    return ret;
}
