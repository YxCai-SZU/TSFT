#include <stdint.h>

/* First function: maps (X,Y) to an integer answer based on ranges */
/*@
    predicate valid_range(integer x) = 1 <= x <= 205;

    logic integer calculate_ans(integer X, integer Y) =
        X < 4 ?
            (Y < 4 ? 1 : 0)
        : X == 4 ?
            (Y < 4 ? Y - 1 : 3)
        :
            (Y < 4 ? X - 1 : 6);

    lemma ans_non_negative: \forall integer X, Y;
        valid_range(X) && valid_range(Y) ==> calculate_ans(X, Y) >= 0;

    lemma ans_upper_bound: \forall integer X, Y;
        valid_range(X) && valid_range(Y) ==> calculate_ans(X, Y) <= 1000000000;
*/

int32_t func_a(uint32_t X, uint32_t Y)
{
    int32_t ans = 0;

    //@ assert valid_range(X) && valid_range(Y);

    if (X < 4)
    {
        if (Y < 4)
        {
            ans += 1;
        }
    }
    else if (X == 4)
    {
        if (Y < 4)
        {
            //@ assert Y >= 1;
            ans += (int32_t)(Y - 1);
        }
        else
        {
            ans += 3;
        }
    }
    else
    {
        if (Y < 4)
        {
            //@ assert X >= 5;
            ans += (int32_t)(X - 1);
        }
        else
        {
            ans += 6;
        }
    }

    //@ assert ans == calculate_ans(X, Y);
    //@ assert ans <= 1000000000;

    return ans;
}

/* Second function: computes a cost as x + y/2 */
/*@
    predicate valid_range_v(integer v) = 1 <= v && v <= 100000;
    
    logic integer compute_cost(integer x, integer y) = x + y / 2;
    
    lemma cost_well_defined: \forall integer x, y; 
        valid_range_v(x) && valid_range_v(y) ==> compute_cost(x, y) >= 0;
*/

unsigned int func_b(unsigned int x, unsigned int y)
{
    unsigned int cost;
    
    //@ assert x >= 1 && x <= 100000;
    //@ assert y >= 1 && y <= 100000;
    
    cost = x + y / 2;
    
    //@ assert cost == x + y / 2;
    
    return cost;
}


/*@
    predicate valid_input(integer X, integer Y, unsigned int p, unsigned int q) =
        1 <= X <= 205 && 1 <= Y <= 205 && 1 <= p <= 100000 && 1 <= q <= 100000;

    logic integer combined_cost(integer X, integer Y, integer p, integer q) =
        (calculate_ans(X, Y) >= 0 ? (calculate_ans(X, Y) + 1) * compute_cost(p, q) : 0);
*/

unsigned long long network_cost_calculator(uint32_t X, uint32_t Y, unsigned int p, unsigned int q)
{
    int32_t priority;
    unsigned int bandwidth_cost;
    unsigned long long total_cost;

    priority = func_a(X, Y);
    //@ assert priority == calculate_ans(X, Y);
    //@ assert priority >= 0;

    bandwidth_cost = func_b(p, q);
    //@ assert bandwidth_cost == compute_cost(p, q);

    total_cost = (unsigned long long)(priority + 1) * (unsigned long long)bandwidth_cost;

    //@ assert total_cost == ((unsigned long long)(calculate_ans(X, Y) + 1)) * ((unsigned long long)compute_cost(p, q));
    //@ assert total_cost >= 0;  // since both factors are non-negative

    return total_cost;
}
