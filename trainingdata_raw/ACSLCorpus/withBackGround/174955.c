#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 16 &&
        1 <= m <= 16 &&
        n + m <= 16;

    logic integer total_minutes(integer n, integer m) =
        n * 2 + m * 4;

    predicate result_condition(integer n, integer m) =
        total_minutes(n, m) <= 16;
*/

/*@
    requires valid_range(n, m);
    ensures \result == (total_minutes(n, m) <= 16);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int n_minutes;
    unsigned int m_minutes;
    bool result;

    //@ assert 1 <= n <= 16;
    n_minutes = n * 2;
    //@ assert n_minutes == n * 2;
    
    //@ assert 1 <= m <= 16;
    m_minutes = m * 4;
    //@ assert m_minutes == m * 4;
    
    //@ assert n + m <= 16;
    result = (n_minutes + m_minutes) <= 16;
    
    //@ assert result == (n * 2 + m * 4 <= 16);
    return result;
}

/*@
    predicate valid_inputs(integer a, integer b) =
        0 <= a <= 10 &&
        0 <= b <= 10;

    logic integer compute_result(integer a, integer b) =
        a * b + a * (10 - b);

    lemma product_bounds1:
        \forall integer a, b;
            valid_inputs(a, b) ==> 0 <= a * b <= 100;

    lemma product_bounds2:
        \forall integer a, b;
            valid_inputs(a, b) ==> 0 <= a * (10 - b) <= 100;

    lemma result_bounds:
        \forall integer a, b;
            valid_inputs(a, b) ==> 0 <= compute_result(a, b) <= 200;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func_complex(int a, int b)
{
    int result;

    //@ assert 0 <= a <= 10;
    //@ assert 0 <= b <= 10;
    
    //@ assert 0 <= a * b <= 100;
    //@ assert 0 <= a * (10 - b) <= 100;
    
    result = a * b + a * (10 - b);
    
    //@ assert result == a * b + a * (10 - b);
    return result;
}
