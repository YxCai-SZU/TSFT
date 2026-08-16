#include <stdbool.h>

/* ====== First underlying function: compute remainder-related quotient ====== */
/*@
    predicate valid_params(integer x, integer y, integer z) =
        1 <= x && 1 <= y && 1 <= z &&
        x <= 100000 && y <= 100000 && z <= 100000 &&
        y + 2 * z <= x;

    logic integer numerator(integer x, integer z) = x - z;
    logic integer denominator(integer y, integer z) = y + z;

    lemma remainder_bounds:
        \forall integer x, y, z;
        valid_params(x, y, z) ==> 0 <= numerator(x, z) && numerator(x, z) <= x;

    lemma denominator_positive:
        \forall integer x, y, z;
        valid_params(x, y, z) ==> 1 <= denominator(y, z);
*/

long func1(long x, long y, long z) {
    long numerator;
    long denominator;
    long remainder;
    long result = 0;
    long temp;

    //@ assert 1 <= x && 1 <= y && 1 <= z;
    //@ assert x <= 100000 && y <= 100000 && z <= 100000;
    //@ assert y + 2 * z <= x;

    //@ assert x - z >= 0;
    numerator = x - z;

    //@ assert y + z >= 0;
    denominator = y + z;

    remainder = numerator;

    while (remainder >= denominator) {
        //@ assert remainder >= denominator;
        remainder -= denominator;
        //@ assert remainder >= 0;
    }

    temp = numerator;

    while (temp >= denominator) {
        //@ assert temp >= denominator;
        temp -= denominator;
        //@ assert temp >= 0;
        result += 1;
        //@ assert result >= 0;
    }

    //@ assert result <= 100000;
    return result;
}

/* ====== Second underlying function: boolean check on parity and bound ====== */
/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate within_double_k(integer n, integer k) = n <= k * 2;
    predicate should_return_true(integer n, integer k) = 
        is_even(n) || within_double_k(n, k);
*/

bool func2(unsigned int n, unsigned int k)
{
    bool result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    if (n % 2 == 0 || n <= k * 2)
    {
        result = true;
        //@ assert should_return_true(n, k);
    }
    else
    {
        //@ assert n % 2 != 0 && n > k * 2;
        result = false;
    }
    
    //@ assert result == true <==> (n % 2 == 0 || n <= k * 2);
    return result;
}

/* ====== Third underlying function: compute score based on array values ====== */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 20 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 20;

    logic integer max_val(integer a, integer b, integer c) =
        a > b ? (a > c ? a : c) : (b > c ? b : c);

    logic integer compute_result(integer a, integer b, integer c) =
        (a == b && b == c ? 3 : (a == b || b == c || c == a ? 2 : 0)) +
        (max_val(a, b, c) - 1);

    lemma result_nonnegative:
        \forall integer a, b, c;
            valid_input(a, b, c) ==> compute_result(a, b, c) >= 0;

    lemma result_bounded:
        \forall integer a, b, c;
            valid_input(a, b, c) ==> compute_result(a, b, c) <= a + b + c;
*/

int func3(int v[3]) {
    int a;
    int b;
    int c;
    int result;
    int max_val;
    bool cond1;
    bool cond2;
    bool cond3;
    bool cond4;
    bool cond5;
    bool cond6;

    a = v[0];
    b = v[1];
    c = v[2];
    result = 0;

    cond1 = (a == b);
    cond2 = (b == c);
    cond3 = (c == a);

    //@ assert valid_input(a, b, c);

    if (cond1 && cond2) {
        result += 3;
    } else if (cond1 || cond2 || cond3) {
        result += 2;
    }

    cond4 = (a > b);
    cond5 = (a > c);
    cond6 = (b > c);

    if (cond4) {
        if (cond5) {
            max_val = a;
        } else {
            max_val = c;
        }
    } else {
        if (cond6) {
            max_val = b;
        } else {
            max_val = c;
        }
    }

    result += max_val - 1;

    //@ assert result == compute_result(a, b, c);
    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}

/* ====== Synthesized function: resource allocation with eligibility check ====== 
   Real-world scenario: A resource allocation system that determines how many 
   resource units to allocate to a user based on their priority (x, y, z), 
   checks if the user is eligible (even ID or within limit), and computes 
   a final score from configuration array. The final assertion ensures the 
   allocated amount is consistent with the eligibility check result.
   Call chain: func1 -> func2 -> func3
   Data flow: 
     - func1 computes quota (q) from (x,y,z)
     - func2 checks eligibility (eligible) from (n, k) where n = q % 100 + 1, k = q % 10 + 1
     - func3 computes config score from array [a,b,c] where a,b,c are derived from q and eligible
   ======================================================================== */

int synthesized_func(long x, long y, long z, unsigned int n, unsigned int k, int v[3]) {
    long quota;
    bool eligible;
    int config_score;
    int result;
    int adjusted_quota;

    quota = func1(x, y, z);
    //@ assert 0 <= quota && quota <= x;

    eligible = func2(n, k);
    //@ assert eligible == true <==> (n % 2 == 0 || n <= k * 2);

    config_score = func3(v);
    //@ assert config_score >= 0 && config_score <= v[0] + v[1] + v[2];

    if (eligible) {
        if (quota > 1000) {
            adjusted_quota = 1000;
        } else {
            adjusted_quota = (int)quota;
        }
        result = config_score + adjusted_quota;
    } else {
        result = config_score;
    }

    //@ assert result >= 0 && result <= x + v[0] + v[1] + v[2];

    return result;
}
