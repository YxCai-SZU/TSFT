#include <stdbool.h>

/*@
    requires \valid(x + (0..2)) && \valid(y + (0..2));
    requires (1 <= (x[0]) <= 100) && (1 <= (x[1]) <= 100) && (1 <= (x[2]) <= 100);
    requires (1 <= (y[0]) <= 100) && (1 <= (y[1]) <= 100) && (1 <= (y[2]) <= 100);
    ensures (1 <= (\result) <= 10000);
    ensures \result == ((x)[(0)] * (y)[(0)]) ||
            \result == ((x)[(1)] * (y)[(1)]) ||
            \result == ((x)[(2)] * (y)[(2)]);
    assigns \nothing;
*/
int func(int* x, int* y)
{
    //@ assert (1 <= (x[0]) <= 100);
    //@ assert (1 <= (y[0]) <= 100);
    //@ assert (1 <= (x[1]) <= 100);
    //@ assert (1 <= (y[1]) <= 100);
    //@ assert (1 <= (x[2]) <= 100);
    //@ assert (1 <= (y[2]) <= 100);
    
    //@ assert (1 <= (((x)[(0)] * (y)[(0)])) <= 10000);
    //@ assert (1 <= (((x)[(1)] * (y)[(1)])) <= 10000);
    //@ assert (1 <= (((x)[(2)] * (y)[(2)])) <= 10000);
    
    int m;
    m = x[0] * y[0];
    
    if (x[1] * y[1] > m)
    {
        m = x[1] * y[1];
    }
    
    if (x[2] * y[2] > m)
    {
        m = x[2] * y[2];
    }
    
    return m;
}
