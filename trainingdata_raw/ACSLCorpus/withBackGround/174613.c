#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer train_cost(integer b) = b * 2;
    logic integer taxi_cost(integer a, integer b) = a + b;

    lemma train_cost_def: \forall integer b; train_cost(b) == b * 2;
    lemma taxi_cost_def: \forall integer a, integer b; taxi_cost(a, b) == a + b;
*/

/*@
    requires valid_range(n);
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == (n >= taxi_cost(a, b) || n >= train_cost(b));
*/
bool func(int n, int a, int b)
{
    int train;
    int taxi;
    bool result;

    train = b * 2;
    taxi = a + b;

    //@ assert train == train_cost(b);
    //@ assert taxi == taxi_cost(a, b);

    result = (n >= train) || (n >= taxi);
    return result;
}
