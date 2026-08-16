#include <stdint.h>
#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
    logic integer max_of_four(integer v0, integer v1, integer v2, integer v3) =
        (v0 >= v1 && v0 >= v2 && v0 >= v3) ? v0 :
        (v1 >= v0 && v1 >= v2 && v1 >= v3) ? v1 :
        (v2 >= v0 && v2 >= v1 && v2 >= v3) ? v2 : v3;
    lemma max_is_one_of_four:
        \forall integer v0, v1, v2, v3, m;
        m == max_of_four(v0, v1, v2, v3) ==>
        (m == v0 || m == v1 || m == v2 || m == v3);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d) {
    int64_t tmp[4];
    int64_t max_value;
    int i;

    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert product_in_range(a, c);
    tmp[0] = a * c;

    //@ assert in_range(a);
    //@ assert in_range(d);
    //@ assert product_in_range(a, d);
    tmp[1] = a * d;

    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert product_in_range(b, c);
    tmp[2] = b * c;

    //@ assert in_range(b);
    //@ assert in_range(d);
    //@ assert product_in_range(b, d);
    tmp[3] = b * d;

    max_value = tmp[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> tmp[j] <= max_value;
        loop invariant in_range(a) && in_range(b) && in_range(c) && in_range(d);
        loop invariant a <= b && c <= d;
        loop assigns i, max_value;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (tmp[i] > max_value) {
            max_value = tmp[i];
        }
        i = i + 1;
    }

    //@ assert tmp[0] == a * c;
    //@ assert tmp[1] == a * d;
    //@ assert tmp[2] == b * c;
    //@ assert tmp[3] == b * d;
    //@ assert \exists integer k; 0 <= k < 4 && max_value == tmp[k];
    //@ assert max_value == max_of_four(tmp[0], tmp[1], tmp[2], tmp[3]);

    return max_value;
}
