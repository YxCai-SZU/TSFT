#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (a - c <= b - d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int min_val;
    int max_val;
    int min_val2;
    int max_val2;
    bool result;

    if (a < c) {
        min_val = a;
    } else {
        min_val = c;
    }
    if (a > c) {
        max_val = a;
    } else {
        max_val = c;
    }
    if (b < d) {
        min_val2 = b;
    } else {
        min_val2 = d;
    }
    if (b > d) {
        max_val2 = b;
    } else {
        max_val2 = d;
    }

    //@ assert min_val <= max_val;
    //@ assert min_val2 <= max_val2;
    //@ assert 0 <= max_val - min_val <= 99;
    //@ assert 0 <= max_val2 - min_val2 <= 99;
    //@ assert a - c >= -99 && a - c <= 99;
    //@ assert b - d >= -99 && b - d <= 99;

    result = (a - c) <= (b - d);
    return result;
}
