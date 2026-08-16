#include <limits.h>

/*@
    predicate is_min(integer val, integer a, integer b, integer c) =
        val <= a && val <= b && val <= c &&
        (val == a || val == b || val == c);
*/

/*@
    lemma min_test1:
        \forall integer a, b, c;
        a == 5 && b == 10 && c == 15 ==> is_min(a, a, b, c);
    
    lemma min_test2:
        \forall integer a, b, c;
        a == 15 && b == 10 && c == 5 ==> is_min(c, a, b, c);
    
    lemma min_test3:
        \forall integer a, b, c;
        a == 10 && b == 15 && c == 5 ==> is_min(c, a, b, c);
*/

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    ensures \result <= a;
    ensures \result <= b;
    ensures \result <= c;
    ensures \result == a || \result == b || \result == c;
*/
int min_numbers(int a, int b, int c)
{
    int min_val = a;
    
    //@ assert min_val == a;
    
    if (b < min_val)
    {
        min_val = b;
        //@ assert min_val == b;
    }
    
    //@ assert min_val <= a && min_val <= b;
    
    if (c < min_val)
    {
        min_val = c;
        //@ assert min_val == c;
    }
    
    //@ assert is_min(min_val, a, b, c);
    return min_val;
}
