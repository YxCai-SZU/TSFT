#include <limits.h>
#include <stdbool.h>

/* ACSL specifications for the three underlying functions */

/*@
    predicate valid_range(integer v) = 1 <= v <= 20;

    logic integer compute_result(integer n, integer m) =
        (n > 10 || m > 10) ?
            ((n + m) > 18 ? n + m : 2 * n + 2 * m - 9)
        : n + m;
*/

int func1(int n, int m)
{
    int x;

    //@ assert 1 <= n <= 20;
    //@ assert 1 <= m <= 20;

    if (n > 10 || m > 10) {
        if ((n + m) > 18) {
            x = n + m;
        } else {
            x = 2 * n + 2 * m - 9;
        }
    } else {
        x = n + m;
    }

    //@ assert x == compute_result(n, m);
    return x;
}

/*@ predicate both_odd(integer a, integer b) = 
      a % 2 != 0 && b % 2 != 0; */

bool func2(int a, int b)
{
    bool is_odd;
    bool b_is_odd;
    
    is_odd = false;
    //@ assert is_odd == false;
    if (a % 2 == 1) {
        is_odd = true;
    }
    
    b_is_odd = false;
    //@ assert b_is_odd == false;
    if (b % 2 == 1) {
        b_is_odd = true;
    }
    
    //@ assert is_odd == (a % 2 != 0);
    //@ assert b_is_odd == (b % 2 != 0);
    
    return is_odd && b_is_odd;
}

/*@
    predicate in_range(integer v) = 0 <= v <= 100;

    logic integer condition_check(integer x, integer a, integer b) = x - a;

    lemma condition_lemma:
        \forall integer x, a, b;
            in_range(a) && in_range(b) && in_range(x) ==>
            (condition_check(x, a, b) >= 0 && condition_check(x, a, b) <= b) ==>
            condition_check(x, a, b) >= 0;
*/

bool func3(long long a, long long b, long long x)
{
    long long diff;
    bool result;

    diff = x - a;

    //@ assert in_range(a) && in_range(b) && in_range(x);
    //@ assert diff == condition_check(x, a, b);

    if (diff < 0 || diff > b)
    {
        //@ assert diff < 0 || diff > b;
        result = false;
    }
    else
    {
        //@ assert diff >= 0 && diff <= b;
        result = true;
    }

    //@ assert result == (x - a >= 0 && x - a <= b);
    return result;
}

/* Synthesized function: 
   Scenario: A simple data validation and processing system.
   It takes two small integers (1-20) and validates them, then checks if they are both odd,
   and finally checks if a computed value falls within a valid range.
   The call chain is: process_data -> func1 -> func2 -> func3
*/

bool process_data(int n, int m)
{
    int result1;
    bool result2;
    bool result3;
    bool final_result;

    result1 = func1(n, m);
    //@ assert result1 == compute_result(n, m);

    //@ assert 1 <= n <= 3 && 1 <= m <= 3;
    result2 = func2(n, m);
    //@ assert result2 == (n % 2 != 0 && m % 2 != 0);

    //@ assert in_range((long long)n) && in_range((long long)(n + m)) && in_range((long long)result1);
    result3 = func3((long long)n, (long long)(n + m), (long long)result1);
    //@ assert result3 == (result1 - n >= 0 && result1 - n <= n + m);

    final_result = result2 && result3;

    //@ assert final_result == ((n % 2 != 0 && m % 2 != 0) && (result1 - n >= 0 && result1 - n <= n + m));

    return final_result;
}
