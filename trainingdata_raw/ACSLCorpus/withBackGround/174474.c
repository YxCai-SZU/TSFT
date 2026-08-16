#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_array(uint64_t *a, integer n) =
        n > 0 && n <= 100000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000;

    logic integer element_value(uint64_t *a, integer i) = a[i];

    lemma array_bounds: \forall uint64_t *a, integer n; valid_array(a, n) ==> 
        \forall integer i; 0 <= i < n ==> 1 <= element_value(a, i) <= 1000000;
*/

/*@
    requires n > 0 && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000;
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
uint64_t func(uint64_t n, uint64_t *a) {
    uint64_t sum = 0;
    uint64_t count = 0;
    uint64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= sum <= i;
        loop invariant 0 <= count <= i;
        loop invariant sum + count <= i;
        loop invariant valid_array(a, n);
        loop assigns i, sum, count;
        loop variant n - i;
    */
    while (i < n) {
        uint64_t x = a[i];
        
        /*@
            loop invariant 0 <= x <= 1000000;
            loop invariant valid_array(a, n);
            loop assigns x;
            loop variant x;
        */
        while (x > 0 && x % 2 == 0) {
            x /= 2;
        }
        
        if (x == 0) {
            sum += 1;
        } else {
            count += 1;
        }
        i += 1;
    }
    
    uint64_t result = 0;
    uint64_t j = 0;
    
    /*@
        loop invariant 0 <= j <= sum;
        loop invariant 0 <= result <= j;
        loop invariant result <= n;
        loop assigns j, result;
        loop variant sum - j;
    */
    while (j < sum) {
        if (sum == 0) {
            break;
        }
        if (j < count) {
            result += 1;
        }
        j += 1;
    }
    
    return result;
}
