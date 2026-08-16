#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures \result == (((a) * 100 + (b) * 10 + (c)) % 4 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int a100;
    unsigned int b10;
    unsigned int sum;
    bool result;

    a100 = a * 100;
    b10 = b * 10;

    //@ assert 100 <= a100 && a100 <= 900;
    //@ assert 10 <= b10 && b10 <= 90;
    //@ assert 1 <= c && c <= 9;

    sum = a100 + b10 + c;
    //@ assert sum <= 1000;

    result = (sum % 4 == 0);
    return result;
}
