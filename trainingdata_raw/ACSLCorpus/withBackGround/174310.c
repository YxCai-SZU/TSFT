#include <stdint.h>

/*@
    predicate divides(uint32_t a, uint32_t b) =
        b > 0 && a % b == 0;
*/

/*@
    lemma test_div:
        \forall uint32_t a, b;
            divides(a, b) ==> a / b == a / b;
*/

/*@
    requires b > 0;
    requires a % b == 0;
    ensures \result == a / b;
*/
uint32_t safe_div(uint32_t a, uint32_t b) {
    //@ assert divides(a, b);
    uint32_t result = a / b;
    //@ assert result == a / b;
    return result;
}
