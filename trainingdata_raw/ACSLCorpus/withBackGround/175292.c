#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer x, uint64_t *l) =
        1 <= n <= 100 &&
        1 <= x <= 10000 &&
        \valid(l + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= l[i] <= 100;
*/

/*@
    requires valid_params(n, x, l);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint64_t x, uint64_t *l) {
    uint32_t count = 0;
    uint64_t sum = 0;
    uint32_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant sum <= index * 100;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= l[i] <= 100;
        loop assigns index, sum, count;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        sum += l[index];
        if (sum <= x) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
