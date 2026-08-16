#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (a) != (c)) || ((a) == (c) && (a) != (b)) || ((b) == (c) && (a) != (b)));
 */
bool func(int a, int b, int c)
{
    int a_new;
    int b_new;
    int c_new;
    a_new = 0;
    b_new = 0;
    c_new = 0;

    //@ assert a_new == 0 && b_new == 0 && c_new == 0;

    if (a == b) {
        a_new = 1;
        b_new = 1;
    }
    if (a == c) {
        a_new = 1;
        c_new = 1;
    }
    if (b == c) {
        b_new = 1;
        c_new = 1;
    }

    //@ assert a_new == 0 || a_new == 1;
    //@ assert b_new == 0 || b_new == 1;
    //@ assert c_new == 0 || c_new == 1;

    return (a_new + b_new + c_new) == 2;
}
