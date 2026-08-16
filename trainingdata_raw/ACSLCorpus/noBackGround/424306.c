#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at the top
    bool result;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    //@ assert 1 <= a + b && a + b <= 200;
    //@ assert 1 <= b + c && b + c <= 200;
    //@ assert 1 <= c + a && c + a <= 200;

    if (a + b == c || b + c == a || c + a == b) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
