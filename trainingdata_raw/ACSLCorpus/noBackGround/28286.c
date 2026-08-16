#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \valid((v) + (0 .. 2)) &&
        1 <= (v)[0] && (v)[0] <= 13 &&
        1 <= (v)[1] && (v)[1] <= 13 &&
        1 <= (v)[2] && (v)[2] <= 13);
    ensures \result == true <==> ((v[0]) + (v[1]) == (v[2]) || (v[0]) + (v[2]) == (v[1]) || (v[1]) + (v[2]) == (v[0]));
    assigns \nothing;
*/
bool func(int *v)
{
    int a;
    int b;
    int c;
    bool result;

    //@ assert ((3) == 3 &&         \valid((v) + (0 .. 2)) &&         1 <= (v)[0] && (v)[0] <= 13 &&         1 <= (v)[1] && (v)[1] <= 13 &&         1 <= (v)[2] && (v)[2] <= 13);
    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a >= 1 && a <= 13;
    //@ assert b >= 1 && b <= 13;
    //@ assert c >= 1 && c <= 13;

    if (a + b == c || a + c == b || b + c == a)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
    return result;
}
