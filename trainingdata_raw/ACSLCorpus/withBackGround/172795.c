#include <stdint.h>

/*@ predicate suber_pre(uint32_t n, uint32_t sub) = n >= sub; */
/*@ predicate suber_post(uint32_t n, uint32_t sub, uint32_t result) = result == n - sub; */

/*@ logic integer suber_spec(integer n, integer sub) = n - sub; */

/*@
    lemma suber_lemma:
        \forall integer n, sub;
            n >= sub ==> suber_spec(n, sub) == n - sub;
*/

/*@
    requires suber_pre(n, sub);
    ensures suber_post(n, sub, \result);
    assigns \nothing;
*/
uint32_t suber(uint32_t n, uint32_t sub) {
    uint32_t result;
    result = n - sub;
    //@ assert suber_post(n, sub, result);
    return result;
}

/*@
    predicate sub_twice_pre(uint32_t n) =
        n >= 0;
*/

/*@
    requires sub_twice_pre(n);
    ensures \result == n - n;
    assigns \nothing;
*/
uint32_t sub_twice(uint32_t n) {
    uint32_t result;
    result = suber(n, n);
    //@ assert result == n - n;
    return result;
}

int main() {
    uint32_t r1;
    r1 = sub_twice(20);
    //@ assert r1 == 0;
    return 0;
}
