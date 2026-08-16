#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;

    logic integer multiply(integer a, integer b) = a * b;

    lemma multiplication_bounds:
        \forall integer a, b;
            valid_range(a, b) ==> 1 <= multiply(a, b) <= 400;

    lemma multiple_of_three_lemma:
        \forall integer n;
            n % 3 == 0 ==> (n + 3) % 3 == 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert valid_range(a, b);
    //@ assert 1 <= multiply(a, b) <= 400;
    
    return a * b;
}
