#include <stdbool.h>

/*@
    predicate valid_range(int *v, integer idx) =
        0 <= v[idx] <= 123;

    predicate strictly_increasing(int *v) =
        v[0] < v[1] < v[2] < v[3] < v[4];

    logic integer vector_length{L}(int *v) = 6;

    lemma bounds_preserved:
        \forall int *v, integer i;
            0 <= i < vector_length(v) && valid_range(v, i) ==>
                v[i] >= 0 && v[i] <= 123;
*/

/*@
    requires \valid(v+(0..5));
    requires vector_length(v) == 6;
    requires valid_range(v, 0);
    requires valid_range(v, 1);
    requires valid_range(v, 2);
    requires valid_range(v, 3);
    requires valid_range(v, 4);
    requires valid_range(v, 5);
    requires strictly_increasing(v);
    assigns \nothing;
    ensures \result == (v[4] - v[0] <= v[5]);
*/
bool func(int *v) {
    int len;
    int i;
    len = 6;
    i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant len == 6;
        loop invariant \forall integer k; 0 <= k < i ==> 0 <= v[k] <= 123;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (v[i] > 123 || v[i] < 0) {
            return false;
        }
        i = i + 1;
    }
    //@ assert i == len;
    //@ assert \forall integer k; 0 <= k < len ==> 0 <= v[k] <= 123;
    return v[4] - v[0] <= v[5];
}
