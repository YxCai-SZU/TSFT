#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    logic integer compute_condition(integer a, integer b) = a * 2 > b + 1 ? 1 : 0;
*/

int func(unsigned int a, unsigned int b)
{
    int result;

    //@ assert a_in_range(a);
    //@ assert b_in_range(b);

    result = (a * 2 > b + 1);
    return result;
}

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer compute_result(integer n, integer m) =
        m <= n - 2 ? 0 :
        (m > n - 2 && m < n) ? n - m :
        1;

    lemma result_cases:
        \forall integer n, m;
        valid_range(n, m) ==>
        (m <= n - 2 && compute_result(n, m) == 0) ||
        (m > n - 2 && m < n && compute_result(n, m) == n - m) ||
        (m >= n && compute_result(n, m) == 1);
*/

int func2(int n, int m)
{
    int result;
    //@ assert valid_range(n, m);

    if (m <= n - 2)
    {
        result = 0;
        //@ assert m <= n - 2 && result == 0;
    }
    else
    {
        if (m > n - 2 && m < n)
        {
            result = n - m;
            //@ assert m > n - 2 && m < n && result == n - m;
        }
        else
        {
            result = 1;
            //@ assert m >= n && result == 1;
        }
    }

    //@ assert (m <= n - 2 && result == 0) || (m > n - 2 && m < n && result == n - m) || (m >= n && result == 1);
    return result;
}

/*@
    predicate valid_game_state(integer a, integer b, integer n, integer m) =
        a_in_range(a) && b_in_range(b) && valid_range(n, m) &&
        (compute_condition(a, b) == 1 ==> m > n - 2) &&
        (compute_condition(a, b) == 0 ==> m <= n - 2);

    logic integer combined_computation(integer a, integer b, integer n, integer m) =
        compute_condition(a, b) == 1 ? compute_result(n, m) : 0;
*/

int game_decision(unsigned int a, unsigned int b, int n, int m)
{
    int decision;
    int condition = func(a, b);
    int result;

    //@ assert condition == compute_condition(a, b);

    if (condition == 1)
    {
        result = func2(n, m);
        //@ assert result == compute_result(n, m);
        decision = result;
    }
    else
    {
        decision = 0;
    }

    //@ assert (condition == 1 && decision == compute_result(n, m)) || (condition == 0 && decision == 0);
    return decision;
}
