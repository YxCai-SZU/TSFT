#include <stdbool.h>

/*@
    predicate bounds(integer A, integer B) =
        1 <= A <= 100 && 1 <= B <= 100;

    logic integer product(integer A, integer B) = A * B;

    lemma product_bound: \forall integer A, B; bounds(A, B) ==> product(A, B) <= 10000;
*/

/*@
    requires bounds(A, B);
    ensures \result == product(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    //@ assert bounds(A, B);
    //@ assert product(A, B) <= 10000;
    result = A * B;
    return result;
}
