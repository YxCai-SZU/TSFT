#include <stdbool.h>

/*@
    requires \valid(x + (0..2));
    requires ((3) >= 3 &&
        1 <= (x)[0] <= 100 &&
        1 <= (x)[1] <= 20 &&
        1 <= (x)[2] <= 2000);
    ensures \result <= x[2];
    ensures \result >= 0;
    ensures \result == ((x[0]) * (x[1])) || \result == x[2];
    assigns \nothing;
*/
long func(const long *x)
{
    long max_val;
    //@ assert 1 <= x[0] && x[0] <= 100;
    //@ assert 1 <= x[1] && x[1] <= 20;
    //@ assert 1 <= x[2] && x[2] <= 2000;
    //@ assert ((x[0]) * (x[1])) <= 2000;
    
    max_val = x[0] * x[1];
    
    if (max_val < x[2])
    {
        //@ assert max_val == ((x[0]) * (x[1]));
        return max_val;
    }
    else
    {
        //@ assert x[2] == x[2];
        return x[2];
    }
}
