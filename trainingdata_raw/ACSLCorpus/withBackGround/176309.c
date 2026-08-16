#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(size_t n, unsigned long *aa) =
        n >= 2 && n <= 200000 &&
        \valid(aa + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> aa[i] >= 1 && aa[i] <= 1000000000;
*/

/*@
    requires valid_array(n, aa);
    ensures \result == ((n % 2 == 0) || (n % 5 == 0));
    assigns \nothing;
*/
bool func(size_t n, const unsigned long *aa) {
    unsigned long a = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant a >= 0;
        loop assigns a, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        a ^= aa[index];
        index += 1;
    }
    
    return (n % 2 == 0) || (n % 5 == 0);
}
