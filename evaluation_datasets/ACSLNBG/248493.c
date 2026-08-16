#include <limits.h>


int func(int A, int B)
{
    int plus;
    int minus;
    int multi;
    int max_val;

    plus = A + B;
    minus = A - B;

    //@ assert (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000);
    //@ assert -1000000 <= A * B <= 1000000;
    multi = A * B;

    max_val = plus;
    if (minus > max_val)
    {
        max_val = minus;
    }
    if (multi > max_val)
    {
        max_val = multi;
    }

    //@ assert max_val == plus || max_val == minus || max_val == multi;
    //@ assert max_val >= plus;
    //@ assert max_val >= minus;
    //@ assert max_val >= multi;
    return max_val;
}
