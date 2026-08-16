#include <limits.h>

/*@
  requires a >= INT_MIN && a <= INT_MAX;
  requires b >= INT_MIN && b <= INT_MAX;
  requires c >= INT_MIN && c <= INT_MAX;
  ensures \result >= a && \result >= b && \result >= c;
*/
int max_numbers(int a, int b, int c)
{
    int max = a;
    //@ assert max == a;
    
    if (b > max)
    {
        max = b;
        //@ assert max == b;
    }
    //@ assert max >= a && max >= b;
    
    if (c > max)
    {
        max = c;
        //@ assert max == c;
    }
    //@ assert ((max) >= (a) && (max) >= (b) && (max) >= (c));
    
    return max;
}
