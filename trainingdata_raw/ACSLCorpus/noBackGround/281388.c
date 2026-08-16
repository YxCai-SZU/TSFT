#include <stdbool.h>

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    unsigned int max;
    unsigned int x;
    unsigned int y;
    bool result;

    //@ assert a + b <= 4294967295;
    //@ assert a + c <= 4294967295;
    //@ assert b + c <= 4294967295;

    if (a + b == c || a + c == b || b + c == a) {
        return true;
    }

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    if (max == a) {
        x = b;
        y = c;
    } else if (max == b) {
        x = a;
        y = c;
    } else {
        x = a;
        y = b;
    }

    //@ assert !(x + y == max);
    return false;
}
