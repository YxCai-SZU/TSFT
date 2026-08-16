#include <stdbool.h>

/*@
    predicate valid_vector(int *v) =
        \valid(v + (0..5)) &&
        0 <= v[0] <= 123 &&
        0 <= v[1] <= 123 &&
        0 <= v[2] <= 123 &&
        0 <= v[3] <= 123 &&
        0 <= v[4] <= 123 &&
        0 <= v[5] <= 123 &&
        v[0] < v[1] < v[2] < v[3] < v[4];

    lemma subtraction_bounds:
        \forall int *v; valid_vector(v) ==> v[4] - v[0] <= 123;
*/

/*@
    requires valid_vector(v);
    ensures \result == (v[4] - v[0] <= v[5]);
    assigns \nothing;
*/
bool func(int *v)
{
    //@ assert \valid(v + (0..5));
    //@ assert 0 <= v[0] <= 123;
    //@ assert 0 <= v[1] <= 123;
    //@ assert 0 <= v[2] <= 123;
    //@ assert 0 <= v[3] <= 123;
    //@ assert 0 <= v[4] <= 123;
    //@ assert 0 <= v[5] <= 123;
    //@ assert v[0] < v[1] < v[2] < v[3] < v[4];
    //@ assert v[4] - v[0] <= 123;
    
    return v[4] - v[0] <= v[5];
}
