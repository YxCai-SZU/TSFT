#include <stdint.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    predicate ret_is_1(integer a, integer b, integer c) =
        a == b && b == c;

    predicate ret_is_2(integer a, integer b, integer c) =
        (a == b && b != c) ||
        (b == c && c != a) ||
        (c == a && a != b);

    predicate ret_is_3(integer a, integer b, integer c) =
        a != b && b != c && c != a;

    lemma ret_cases_cover:
        \forall integer a, b, c;
            ret_is_1(a, b, c) ||
            ret_is_2(a, b, c) ||
            ret_is_3(a, b, c);
*/

/*@
    requires is_valid_input(a, b, c);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> ret_is_1(a, b, c);
    ensures \result == 2 ==> ret_is_2(a, b, c);
    ensures \result == 3 ==> ret_is_3(a, b, c);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t ret = -1;

    //@ assert ret_is_1(a, b, c) || ret_is_2(a, b, c) || ret_is_3(a, b, c);

    if (a == b && b == c) {
        ret = 1;
        //@ assert ret == 1 ==> ret_is_1(a, b, c);
    } else if (a != b && b != c && c != a) {
        ret = 3;
        //@ assert ret == 3 ==> ret_is_3(a, b, c);
    } else {
        ret = 2;
        //@ assert ret == 2 ==> ret_is_2(a, b, c);
    }

    //@ assert ret >= 1 && ret <= 3;
    return ret;
}
