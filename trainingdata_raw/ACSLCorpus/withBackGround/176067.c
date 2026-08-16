#include <stdint.h>

/*@
    predicate valid_params(integer X, integer A, integer B) =
        1 <= A && A <= 1000 &&
        1 <= B && B <= 1000 &&
        A + B <= X && X <= 10000;

    logic integer compute_remainder(integer X, integer A, integer B) =
        X - A - ((X - A) / B) * B;
*/

/*@
    lemma remainder_bounds:
        \forall integer X, A, B;
        valid_params(X, A, B) ==>
        0 <= compute_remainder(X, A, B) <= X;
*/

/*@
    requires valid_params(X, A, B);
    ensures 0 <= \result <= X;
*/
int64_t func(int64_t X, int64_t A, int64_t B)
{
    int64_t remainder;
    
    //@ assert valid_params(X, A, B);
    remainder = X - A;
    
    //@ assert 0 <= remainder <= X;
    
    /*@
        loop invariant 0 <= remainder <= X;
        loop assigns remainder;
    */
    while (remainder >= B) {
        //@ assert remainder >= B;
        remainder -= B;
        //@ assert 0 <= remainder <= X;
    }
    
    //@ assert 0 <= remainder <= X;
    return remainder;
}
