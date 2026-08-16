#include <stdbool.h>

/* ============================================================
   Underlying function 1: compute a bounded product or cap
   ============================================================ */

/*@
    predicate valid_vector(int *v, integer len) =
        len == 3 &&
        1 <= v[0] <= 100 &&
        1 <= v[1] <= 20 &&
        1 <= v[2] <= 2000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 20 ==> product(a, b) <= 2000;
*/

int func_int(int *v)
{
    int x;
    int result;

    //@ assert 1 <= v[0] && v[0] <= 100 && 1 <= v[1] && v[1] <= 20;
    //@ assert product(v[0], v[1]) <= 2000;

    x = v[0] * v[1];
    
    if (x < v[2])
    {
        result = x;
    }
    else
    {
        result = v[2];
    }

    return result;
}

/* ============================================================
   Underlying function 2: detect if a lies in [0, a+b)
   ============================================================ */

/*@
    predicate is_valid_params(integer a, integer b) =
        1 <= a <= 32 && 1 <= b <= 32;
    
    logic integer sum(integer a, integer b) = a + b;
    
    lemma sum_bounds:
        \forall integer a, b;
        is_valid_params(a, b) ==> 1 <= sum(a, b) <= 64;
*/

unsigned int func_uint(unsigned int a, unsigned int b)
{
    unsigned int n;
    unsigned int result;
    unsigned int i;
    
    //@ assert is_valid_params(a, b);
    n = a + b;
    //@ assert 1 <= n <= 64;
    result = 0;
    i = 0;
    
    while (i < n)
    {
        if (i == a)
        {
            result = 1;
        }
        i = i + 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}

/* ============================================================
   Scenario: Network packet rate‑limiting decision
   
   We have a small flow table where each entry contains:
     - flow_priority (1..100)
     - burst_factor   (1..20)
     - max_rate       (1..2000)
   
   The first function computes an effective rate cap:
     effective = min(priority * burst_factor, max_rate)
   
   Then we use a second "window check" function:
     given a (current_window_index, 1..32) and b (window_count, 1..32),
     it returns 1 if current_window_index < a+b (i.e. window is active),
     else 0.
   
   We combine them: if the effective rate is <= 500 AND the window
   is active, we set a flag to 1 (allow the burst); otherwise 0.
   
   High‑level property: the final decision flag is always 0 or 1.
   ============================================================ */

unsigned int rate_limiting_decision(int *v, unsigned int a, unsigned int b)
{
    int effective_rate;
    unsigned int window_active;
    unsigned int decision;

    effective_rate = func_int(v);

    window_active = func_uint(a, b);

    if (effective_rate <= 500 && window_active == 1)
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }

    //@ assert decision == 0 || decision == 1;
    return decision;
}
