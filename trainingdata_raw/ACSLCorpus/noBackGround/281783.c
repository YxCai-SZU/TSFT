#include <stdbool.h>

/*@
    requires ((a) > 0 && (b) > 0 && (c) > 0 && (d) > 0 &&
        (a) <= 8 && (b) <= 8 && (c) <= 8 && (d) <= 8);
    ensures \result == true <==> (a * b) * c == a * b * c;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a > 0 && a <= 8;
    //@ assert b > 0 && b <= 8;
    //@ assert c > 0 && c <= 8;
    //@ assert d > 0 && d <= 8;

    //@ assert (a * b) * c == a * b * c;
    //@ assert 0 <= (a * b) * c <= 8 * 8 * 8 * 8 * 8 * 8;

    result = true;
    return result;
}
