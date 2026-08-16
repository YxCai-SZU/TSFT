#include <stdbool.h>

/*@
    predicate valid_vec(int *v) =
        \valid(v) &&
        \valid(v+1) &&
        \valid(v+2) &&
        1 <= v[0] <= 100 &&
        1 <= v[1] <= 20 &&
        1 <= v[2] <= 2000;

    logic integer vec_len{L}(int *v) = 3;

    lemma mul_bounds:
        \forall int *v; valid_vec(v) ==> v[0] * v[1] <= 2000;
*/

/*@
    requires valid_vec(v);
    ensures \result >= 0;
    ensures \result <= v[2];
    ensures \result == v[1] * v[0] || \result == v[2];
    assigns \nothing;
*/
int func(int *v)
{
    int min_val;
    int temp;

    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 20;
    //@ assert v[0] * v[1] <= 2000;

    temp = v[1] * v[0];
    if (temp < v[2]) {
        min_val = temp;
    } else {
        min_val = v[2];
    }

    return min_val;
}
