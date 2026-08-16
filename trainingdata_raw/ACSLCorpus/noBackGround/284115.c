#include <stdbool.h>

/*@ requires (10 <= (n) && (n) <= 99);
    ensures \result == (((n) / 10) == 9 || ((n) % 10) == 9);
    assigns \nothing;
 */
bool func(unsigned long n)
{
    unsigned long tens_digit;
    unsigned long ones_digit;
    bool result;

    tens_digit = n / 10;
    ones_digit = n % 10;
    
    //@ assert tens_digit == n / 10;
    //@ assert ones_digit == n % 10;
    //@ assert 1 <= tens_digit && tens_digit <= 9;
    //@ assert 0 <= ones_digit && ones_digit <= 9;
    
    result = (tens_digit == 9) || (ones_digit == 9);
    
    //@ assert result == (tens_digit == 9 || ones_digit == 9);
    return result;
}

/*@ requires (10 <= (n) && (n) <= 99);
    ensures \result == (((n) / 10) == 9 || ((n) % 10) == 9);
    assigns \nothing;
 */
bool func_with_calc(unsigned long n)
{
    unsigned long tens_digit;
    unsigned long ones_digit;
    bool result;

    tens_digit = n / 10;
    ones_digit = n % 10;
    
    //@ assert 10 <= n && n <= 99;
    //@ assert tens_digit == n / 10;
    //@ assert ones_digit == n % 10;
    //@ assert 1 <= tens_digit && tens_digit <= 9;
    //@ assert 0 <= ones_digit && ones_digit <= 9;
    
    result = (tens_digit == 9) || (ones_digit == 9);
    
    //@ assert result == (tens_digit == 9 || ones_digit == 9);
    return result;
}
