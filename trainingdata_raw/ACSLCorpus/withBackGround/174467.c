#include <stdbool.h>
/*@
    predicate valid_input(int *s, integer len) =
        len >= 3 &&
        1 <= s[0] && s[0] <= 100 &&
        1 <= s[1] && s[1] <= 20 &&
        1 <= s[2] && s[2] <= 2000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 20 ==> safe_product(a, b) <= 2000;
*/

/*@
    requires \valid(s + (0..2));
    requires valid_input(s, 3);
    ensures \result <= s[2];
    ensures \result >= 0;
    ensures \result == s[2] || \result == safe_product(s[0], s[1]);
    assigns \nothing;
*/
int func(int *s) {
    int res;
    //@ assert 1 <= s[0] && s[0] <= 100;
    //@ assert 1 <= s[1] && s[1] <= 20;
    //@ assert safe_product(s[0], s[1]) <= 2000;
    
    res = s[0] * s[1];
    if (res < s[2]) {
        return res;
    } else {
        return s[2];
    }
}
