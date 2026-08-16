#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == ((a < c ? a : c) < (b > d ? d : b));
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    long min_left;
    long max_right;
    bool result;

    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    
    min_left = a < c ? a : c;
    //@ assert min_left == (a < c ? a : c);
    
    max_right = b > d ? d : b;
    //@ assert max_right == (b > d ? d : b);
    
    result = min_left < max_right;
    //@ assert result == (min_left < max_right);
    
    return result;
}
