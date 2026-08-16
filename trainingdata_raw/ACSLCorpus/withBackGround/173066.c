#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 
        product(a, b) <= 10000 * 10000;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C) && valid_range(D);
    ensures \result == product(A, B) || \result == product(C, D);
    ensures \result >= product(A, B);
    ensures \result >= product(C, D);
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int train_cost;
    int taxi_cost;
    int ans;

    //@ assert valid_range(A) && valid_range(B);
    //@ assert product(A, B) <= 10000 * 10000;
    train_cost = A * B;

    //@ assert valid_range(C) && valid_range(D);
    //@ assert product(C, D) <= 10000 * 10000;
    taxi_cost = C * D;

    if (train_cost > taxi_cost)
    {
        ans = train_cost;
    }
    else
    {
        ans = taxi_cost;
    }

    return ans;
}
