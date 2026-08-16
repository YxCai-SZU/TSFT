#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            1 <= product(a, b) <= 100000000;
*/


int func(int a, int b, int c, int d)
{
    int s1;
    int s2;
    int res;
    
    //@ assert 1 <= a * b <= 100000000;
    s1 = a * b;
    
    //@ assert 1 <= c * d <= 100000000;
    s2 = c * d;
    
    if (s1 > s2) {
        res = s1;
    } else {
        res = s2;
    }
    
    //@ assert res == s1 || res == s2;
    //@ assert 1 <= res <= 100000000;
    
    return res;
}
