#include <stdint.h>

/*@
    predicate is_even(integer b) = b % 2 == 0;
    predicate in_range(integer a) = 1 <= a && a <= 100;

    logic integer half(integer b) = b / 2;
    logic integer result_val(integer a, integer b) = a + half(b);

    lemma half_positive: \forall integer b; b >= 1 && b <= 100 && is_even(b) ==> half(b) >= 0;
    lemma result_in_range: \forall integer a, integer b; in_range(a) && in_range(b) && is_even(b) ==> 1 <= result_val(a, b) && result_val(a, b) <= 150;
*/

/*@
    requires in_range(a) && in_range(b) && is_even(b);
    ensures \result == result_val(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t half_b;
    int64_t count;
    int64_t temp_b;

    if (b >= 0) {
        count = 0;
        temp_b = b;
        /*@
            loop invariant 0 <= temp_b && temp_b <= b;
            loop invariant count <= b / 2;
            loop invariant temp_b == b - 2 * count;
            loop invariant in_range(a) && in_range(b) && is_even(b);
            loop assigns temp_b, count;
            loop variant temp_b;
        */
        while (temp_b >= 2) {
            temp_b -= 2;
            count += 1;
        }
        half_b = count;
    } else {
        count = 0;
        temp_b = b;
        /*@
            loop invariant temp_b <= b && temp_b >= -b;
            loop invariant count >= -b / 2;
            loop invariant temp_b == b - 2 * count;
            loop invariant in_range(a) && in_range(b) && is_even(b);
            loop assigns temp_b, count;
            loop variant -temp_b;
        */
        while (temp_b <= -2) {
            temp_b += 2;
            count -= 1;
        }
        half_b = count;
    }

    //@ assert half_b == b / 2;
    int64_t result = a + half_b;
    //@ assert result == a + (b / 2);
    return result;
}

int main() {
    return 0;
}
