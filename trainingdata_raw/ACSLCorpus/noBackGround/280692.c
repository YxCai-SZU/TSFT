#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n / 10 % 10 == 9);
*/
bool func(int n) {
    unsigned int n_unsigned;
    unsigned int last_digit;
    unsigned int first_digit;
    bool result;

    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;

    last_digit = n_unsigned % 10;
    first_digit = n_unsigned / 10;

    if (last_digit == 9 || first_digit == 9) {
        result = true;
    } else {
        //@ assert last_digit != 9 && first_digit != 9;
        result = false;
    }

    return result;
}
