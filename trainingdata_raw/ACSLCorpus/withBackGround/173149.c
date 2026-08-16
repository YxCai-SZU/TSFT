#include <stdbool.h>

/*@ predicate all_equal(integer a, integer b, integer c) = 
      a == b && b == c;
    
    predicate not_all_equal(integer a, integer b, integer c) = 
      a != b || b != c || c != a;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && b == c ==> \result == 1);
    ensures (a != b || b != c || c != a ==> \result == 0);
*/
int func(int a, int b, int c)
{
    int res;
    
    if (a == b && b == c)
    {
        //@ assert a == b && b == c;
        res = 1;
    }
    else
    {
        //@ assert a != b || b != c || c != a;
        res = 0;
    }
    
    return res;
}
