#include <limits.h>

/*@
    predicate in_range(integer n) = -100 <= n <= 100;
    predicate product_in_range(integer n, integer m) = -10000 <= n * m <= 10000;
*/

/*@
    requires in_range(n) && in_range(m);
    ensures \result == n * m;
    assigns \nothing;
*/
int product(int n, int m) {
    // Variable declarations at top of scope
    int result;

    //@ assert product_in_range(n, m);
    
    result = n * m;
    //@ assert result == n * m;
    return result;
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
int main() {
    // Variable declarations at top of scope
    int p;
    
    p = product(10, 20);
    //@ assert p == 200;
    
    return 0;
}
