#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (c - b == b - a);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int diff1;
    int diff2;
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    diff1 = c - b;
    diff2 = b - a;

    //@ assert diff1 >= -99 && diff1 <= 99;
    //@ assert diff2 >= -99 && diff2 <= 99;

    result = (diff1 == diff2);
    return result;
}
