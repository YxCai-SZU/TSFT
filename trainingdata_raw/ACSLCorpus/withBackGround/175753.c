#include <stdbool.h>
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer div100(integer x) = x / 100;
    logic integer mod100(integer x) = x % 100;
    
    lemma division_property:
        \forall integer x, n, m;
            is_valid_range(x) ==>
            0 <= n <= 1000 ==>
            0 <= m <= 99 ==>
            x == 100 * n + m ==>
            n == div100(x) && m == mod100(x);
*/

/*@
    requires is_valid_range(x);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (x % 100) * 21 < x;
    ensures \result == 0 ==> (x % 100) * 21 >= x;
*/
unsigned int func(unsigned int x) {
    unsigned int n;
    unsigned int m;
    unsigned int r;
    unsigned int result;
    
    n = x / 100;
    m = x % 100;
    
    //@ assert 0 <= n <= 1000;
    //@ assert 0 <= m <= 99;
    //@ assert x == 100 * n + m;
    
    r = m * 21;
    
    if (r < x) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
