#include <stdint.h>

/*@
    predicate in_range(integer x) = 1 <= x && x <= 100;

    logic integer max_cost(integer X, integer Y) = X * 3 + Y;

    lemma cost_bound: \forall integer X, Y, cost;
        in_range(X) && in_range(Y) && cost <= max_cost(X, Y) ==> cost <= max_cost(X, Y);
*/

/*@
    requires in_range(X) && in_range(Y);
    ensures \result <= max_cost(X, Y);
    assigns \nothing;
*/
uint32_t func(uint32_t X, uint32_t Y)
{
    uint32_t cost;

    cost = X * 2 + (Y / 2) * 2;

    if (Y % 2 != 0)
    {
        cost += 1;
    }

    //@ assert cost <= max_cost(X, Y) + 1;

    if (cost > X * 3 + Y)
    {
        cost = X * 3 + Y;
    }

    //@ assert cost <= max_cost(X, Y);

    return cost;
}
