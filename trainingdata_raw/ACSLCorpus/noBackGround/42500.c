#include <stdbool.h>

/*@
    requires a > 0 && b > 0 && c > 0;
    requires a + b + c == 180;
    ensures \result == (a == 60 && b == 60 && c == 60);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int diff1;
    unsigned int diff2;
    unsigned int diff3;
    bool ans;

    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a + b + c == 180;

    if (a >= b) {
        diff1 = a - b;
    } else {
        diff1 = b - a;
    }

    if (b >= c) {
        diff2 = b - c;
    } else {
        diff2 = c - b;
    }

    if (c >= a) {
        diff3 = c - a;
    } else {
        diff3 = a - c;
    }

    ans = true;

    if (diff1 != 0) {
        ans = false;
    }
    //@ assert ans == (diff1 == 0);

    if (diff2 != 0) {
        ans = false;
    }
    //@ assert ans == (diff1 == 0 && diff2 == 0);

    if (diff3 != 0) {
        ans = false;
    }
    //@ assert ans == (diff1 == 0 && diff2 == 0 && diff3 == 0);

    //@ assert ans == (a == b && b == c);
    //@ assert ans == (a == 60 && b == 60 && c == 60);

    return ans;
}
