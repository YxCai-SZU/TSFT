#include <stdbool.h>
#include <stdint.h>

/* ACSL predicates from the first function */
/*@
    predicate within_range(integer a, integer b, integer c) =
        1 <= a && a <= 5000 &&
        1 <= b && b <= 5000 &&
        1 <= c && c <= 10000;

    predicate condition_holds(integer a, integer b, integer c) =
        c >= a && c - a <= b;
*/

/* First function: checks if c is within [a, a+b] */
bool func1(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;

    //@ assert within_range(a, b, c);

    if (c < a)
    {
        result = false;
        //@ assert !(c >= a && c - a <= b);
        return result;
    }

    if (c == a)
    {
        result = true;
        //@ assert c >= a && c - a <= b;
        return result;
    }

    if (c - a <= b)
    {
        result = true;
        //@ assert c >= a && c - a <= b;
        return result;
    }

    result = false;
    //@ assert !(c >= a && c - a <= b);
    return result;
}

/* ACSL predicates from the second function */
/*@
    predicate is_n_one(integer n) = n == 1;
    predicate is_n_zero(integer n) = n == 0;
*/

/* Second function: maps 1->0, 0->1 */
int32_t func2(uint32_t n)
{
    int32_t res;
    //@ assert n <= 1;
    
    if (n == 1) {
        //@ assert is_n_one(n);
        res = 0;
        //@ assert res == 0;
        return res;
    } else {
        //@ assert !is_n_one(n);
        //@ assert n == 0;
        //@ assert is_n_zero(n);
        res = 1;
        //@ assert res == 1;
        return res;
    }
}

/* ACSL predicates from the third function */
/*@
    predicate valid_range(integer n, integer m) =
        2 <= n && n <= 100 && 2 <= m && m <= 100;

    logic integer n_m(integer n, integer m) = n * m;
    logic integer n_p_m(integer n, integer m) = n + m - 1;
    logic integer expected_result(integer n, integer m) =
        n_m(n, m) - n_p_m(n, m);

    lemma product_bound: \forall integer n, m;
        valid_range(n, m) ==> n_m(n, m) <= 10000;
    lemma sum_bound: \forall integer n, m;
        valid_range(n, m) ==> n_p_m(n, m) <= 199;
    lemma product_ge_sum: \forall integer n, m;
        valid_range(n, m) ==> n_m(n, m) >= n_p_m(n, m);
*/

/* Third function: computes n*m - (n+m-1) */
int func3(unsigned int n, unsigned int m)
{
    unsigned int n_m_val;
    unsigned int n_p_m_val;
    unsigned int result;
    int final_result;

    //@ assert valid_range(n, m);
    
    //@ assert n_m(n, m) <= 10000;
    n_m_val = n * m;
    
    //@ assert n_p_m(n, m) <= 199;
    n_p_m_val = n + m - 1;
    
    //@ assert n_m(n, m) >= n_p_m(n, m);
    result = n_m_val - n_p_m_val;
    
    final_result = (int)result;
    //@ assert final_result == expected_result(n, m);
    return final_result;
}

/* Synthesized high-level function: 
   Scenario: Network packet buffer validation.
   Given a buffer size (a) and offset (b), we check if a packet of size (c) fits.
   Then we verify buffer alignment status (func2).
   Finally, we compute the number of valid data units in a grid-like structure.
   
   The high-level property: if the packet fits, the alignment status func2 returns 
   a non-negative value, and the computed result is consistent with the input ranges.
*/

int synthesized_func(unsigned int a, unsigned int b, unsigned int c,
                     unsigned int n, unsigned int m)
{
    bool fits;
    int32_t align_status;
    int grid_result;
    int final_output;

    fits = func1(a, b, c);
    //@ assert fits == (c >= a && c - a <= b);

    align_status = func2((uint32_t)fits);
    //@ assert (fits == 1) ==> (align_status == 0);
    //@ assert (fits == 0) ==> (align_status == 1);

    grid_result = func3(n, m);
    //@ assert grid_result == expected_result(n, m);

    if (fits) {
        //@ assert align_status == 0;
        final_output = grid_result;
    } else {
        final_output = align_status;
    }

    //@ assert final_output >= 0;
    return final_output;
}
