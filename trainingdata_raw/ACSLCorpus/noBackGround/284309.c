#include <stdbool.h>

/*@
    requires (100 <= (a) && (a) <= 999);
    ensures \result == (((a) / 100) == 7 || (((a) / 10) % 10) == 7 || ((a) % 10) == 7);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    // Variable declarations at scope top
    unsigned int b;
    unsigned int c;
    unsigned int d;
    bool result;

    //@ assert (100 <= (a) && (a) <= 999);
    //@ assert 0 <= ((a) / 100) <= 9;
    //@ assert 0 <= (((a) / 10) % 10) <= 9;
    //@ assert 0 <= ((a) % 10) <= 9;

    b = a / 100;
    c = (a / 10) % 10;
    d = a % 10;

    result = (b == 7) || (c == 7) || (d == 7);
    return result;
}
