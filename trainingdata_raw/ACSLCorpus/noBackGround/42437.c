#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (((a) * (b)) < ((c) * (d)));
*/
bool func(int a, int b, int c, int d)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) <= 100000000;
    
    return a * b < c * d;
}
