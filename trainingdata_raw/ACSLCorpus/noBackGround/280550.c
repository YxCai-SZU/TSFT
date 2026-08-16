#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        1 <= (c) && (c) <= 10000 &&
        1 <= (d) && (d) <= 10000);
    ensures \result == ((a) > (b / c) ? (b / c) : (a));
    ensures \result == (b / c >= a ? a : b / c) || \result == (b / c >= a ? b / c : a);
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int res;
    unsigned int b_div_c;

    //@ assert (1 <= (a) && (a) <= 10000 &&         1 <= (b) && (b) <= 10000 &&         1 <= (c) && (c) <= 10000 &&         1 <= (d) && (d) <= 10000);
    b_div_c = b / c;
    //@ assert b_div_c == b / c;

    if (a > b_div_c)
    {
        res = b_div_c;
        //@ assert res == b_div_c;
    }
    else
    {
        res = a;
        //@ assert res == a;
    }

    //@ assert res == ((a) > (b_div_c) ? (b_div_c) : (a));
    return res;
}
