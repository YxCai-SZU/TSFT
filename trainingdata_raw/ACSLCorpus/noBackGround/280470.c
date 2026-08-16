#include <stdbool.h>

/*@ requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (c) && (c) <= 100);
    requires (1 <= (d) && (d) <= 100);
    requires ((a) <= (b));
    requires ((c) <= (d));
    ensures \result == true <==> (((a) <= (c) && (b) >= (c)) || ((c) <= (a) && (d) >= (a)) || ((a) >= (c) && (b) <= (d)) ? 1 : 0) == 1;
*/
bool func(long a, long b, long c, long d)
{
    bool intersection;
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert (1 <= (d) && (d) <= 100);
    //@ assert ((a) <= (b));
    //@ assert ((c) <= (d));
    
    intersection = (a <= c && b >= c) || (c <= a && d >= a) || (a >= c && b <= d);
    
    //@ assert intersection == true <==> ((a <= c && b >= c) || (c <= a && d >= a) || (a >= c && b <= d));
    
    return intersection;
}
