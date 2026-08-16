#include <stdbool.h>

/* ========== Original func (travel days check) ========== */

/*@
    predicate ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    logic integer total_days(integer a, integer b, integer c, integer d, integer e) =
        (b > a ? b - a : a - b) +
        (c > b ? c - b : b - c) +
        (d > c ? d - c : c - d) +
        (e > d ? e - d : d - e);
*/

/*@
    lemma days_equals_diff:
        \forall integer a, b, c, d, e;
        ordered(a, b, c, d, e) ==> total_days(a, b, c, d, e) == e - a;
*/

bool travel_days_check(unsigned int a, unsigned int b, unsigned int c,
                       unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int days = 0;
    //@ assert ordered(a, b, c, d, e);
    
    if (b > a) {
        days += b - a;
    } else {
        days += a - b;
    }
    
    if (c > b) {
        days += c - b;
    } else {
        days += b - c;
    }
    
    if (d > c) {
        days += d - c;
    } else {
        days += c - d;
    }
    
    if (e > d) {
        days += e - d;
    } else {
        days += d - e;
    }
    
    //@ assert days == e - a;
    return days <= k;
}

/* ========== Original func (budget check) ========== */

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer manual_div_100(integer x, integer n) = x - 100 * n;
    logic integer manual_div_500(integer x, integer m) = x - 500 * m;

    lemma div_100_bound: \forall integer x, n; 
        is_valid_range(x) && 0 <= n <= x/100 ==> 0 <= manual_div_100(x, n) <= x;
    lemma div_500_bound: \forall integer x, m; 
        is_valid_range(x) && 0 <= m <= x/500 ==> 0 <= manual_div_500(x, m) <= x;
*/

bool budget_check(unsigned int x) {
    unsigned int n = 0;
    unsigned int temp_x = x;
    const unsigned int hundred = 100;

    //@ assert is_valid_range(x);
    
    while (temp_x >= hundred) {
        temp_x -= hundred;
        n += 1;
    }

    unsigned int m = 0;
    temp_x = x;

    while (temp_x >= 500) {
        temp_x -= 500;
        m += 1;
    }

    bool ans = x >= 2000 || (100 * n <= x && 500 * m <= x && 100 * n + 500 * m <= x);
    //@ assert ans == (x >= 2000 || (100 * (x/100) <= x && 500 * (x/500) <= x && 100 * (x/100) + 500 * (x/500) <= x));
    return ans;
}

/* ========== Synthesized function: travel budget planner ========== */

bool travel_budget_planner(unsigned int a, unsigned int b, unsigned int c,
                           unsigned int d, unsigned int e, unsigned int k,
                           unsigned int budget)
{
    bool days_ok = travel_days_check(a, b, c, d, e, k);
    
    bool budget_ok = budget_check(budget);
    
    //@ assert days_ok == (e - a <= k);
    //@ assert budget_ok == (budget >= 2000 || (100 * (budget/100) <= budget && 500 * (budget/500) <= budget && 100 * (budget/100) + 500 * (budget/500) <= budget));
    
    bool result = days_ok && budget_ok;
    
    //@ assert result <==> ( (e - a <= k) && (budget >= 2000 || (100 * (budget/100) <= budget && 500 * (budget/500) <= budget && 100 * (budget/100) + 500 * (budget/500) <= budget)) );
    
    return result;
}
