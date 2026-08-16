#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == ((((n) % 10 == 9 || ((n) / 10) % 10 == 9) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long last_digit;
    unsigned long first_digit;
    bool result;
    
    last_digit = n % 10;
    first_digit = n / 10;
    
    //@ assert first_digit == n / 10;
    
    result = (last_digit == 9) || (first_digit % 10 == 9);
    return result;
}
