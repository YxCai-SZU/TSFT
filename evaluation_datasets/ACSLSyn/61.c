#include <stdbool.h>

/* First function: computes a price with discount */
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    predicate loop_inv(integer n, integer q, integer r) =
        valid_n(n) &&
        0 <= q && q <= n / 15 &&
        r == n - q * 15 &&
        r >= 0;
    
    logic integer compute_result(integer n) = n * 800 - (n / 15) * 200;
*/

int compute_price(unsigned int n)
{
    int x;
    unsigned int quotient;
    unsigned int remainder;
    int y;
    int ans;
    int max_value;
    
    //@ assert valid_n(n);
    
    x = 800 * (int)n;
    
    quotient = 0;
    remainder = n;
    
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
        //@ assert loop_inv(n, quotient, remainder);
    }
    
    y = (int)quotient * 200;
    
    ans = x - y;
    
    if (ans < 0)
    {
        max_value = 0;
    }
    else
    {
        max_value = ans;
    }
    
    //@ assert max_value == compute_result(n);
    
    return max_value;
}

/* Second function: checks if a valid ticket sequence has close numbers */
/*@
    predicate valid_range(int *v, integer len) =
        len == 6 &&
        \forall integer i; 0 <= i < len ==> (v[i] == 0 || v[i] == 1 || v[i] == 2) &&
        v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4] && v[4] < v[5];

    logic integer diff_condition(int *v) = (v[4] - v[0] <= 3) ? 1 : 0;
*/

bool check_ticket_sequence(int *v) {
    int i;
    bool result;

    //@ assert v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4] && v[4] < v[5];

    i = 0;
    while (i < 6) {
        //@ assert v[i] == 0 || v[i] == 1 || v[i] == 2;
        i++;
    }

    //@ assert v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4] && v[4] < v[5];

    if (v[4] - v[0] <= 3) {
        result = true;
        //@ assert diff_condition(v) == 1;
    } else {
        result = false;
        //@ assert diff_condition(v) == 0;
    }

    return result;
}

/* Synthesized function: simulates a lottery ticket purchase system
   where ticket price depends on quantity and special sequences get a bonus */
/*@
    predicate valid_ticket_data(unsigned int n, int *v) =
        valid_n(n) && \valid(v+(0..5)) && valid_range(v, 6);

    logic integer compute_bonus(int *v) = (diff_condition(v) == 1) ? 100 : 0;
    logic integer final_cost(unsigned int n, int *v) = 
        compute_result(n) - compute_bonus(v);
*/

int process_ticket_order(unsigned int n, int *v)
{
    int base_price;
    bool has_bonus;
    int bonus_amount;
    int final_price;

    base_price = compute_price(n);
    //@ assert base_price == compute_result(n);

    has_bonus = check_ticket_sequence(v);
    //@ assert (has_bonus == true) <==> (diff_condition(v) == 1);

    if (has_bonus) {
        bonus_amount = 100;
        //@ assert bonus_amount == 100;
    } else {
        bonus_amount = 0;
        //@ assert bonus_amount == 0;
    }

    final_price = base_price - bonus_amount;

    if (final_price < 0) {
        final_price = 0;
    }

    //@ assert final_price == final_cost(n, v);

    return final_price;
}

int main(void)
{
    return 0;
}
