#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n && n <= 0xFFFF;
*/

/*@
    logic integer square(integer n) = n * n;
*/

/*@
    lemma square_bound: 
        \forall integer n; is_valid_n(n) ==> square(n) <= 0xFFFF * 0xFFFF;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    assigns \nothing;
*/
uint32_t find_square_num(uint32_t n) {
    //@ assert square(n) <= 0xFFFF * 0xFFFF;
    return n * n;
}
