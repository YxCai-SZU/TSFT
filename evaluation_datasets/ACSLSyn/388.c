#include <stdbool.h>
#include <stdint.h>

/* predicate and lemma from first snippet */
/*@
    predicate valid_range_4(integer x) = 1 <= x <= 100;

    logic integer sum(integer x, integer y) = x + y;

    lemma equivalence:
        \forall integer a, b, c, d;
        valid_range_4(a) && valid_range_4(b) && valid_range_4(c) && valid_range_4(d) ==>
        (a + b == c && b + c == d && a + c == b && a + d == c) ==>
        (a + b == c && b + c == d && a + c == b && a + d == c);
*/

int func_first(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    int result = 1;

    //@ assert valid_range_4(a) && valid_range_4(b) && valid_range_4(c) && valid_range_4(d);

    if (a + b != c)
    {
        result = 0;
    }
    else if (b + c != d)
    {
        result = 0;
    }
    else if (a + c != b)
    {
        result = 0;
    }
    else if (a + d != c)
    {
        result = 0;
    }

    //@ assert result == 1 <==> (a + b == c && b + c == d && a + c == b && a + d == c);
    return result;
}

/* predicate and lemma from second snippet */
/*@
    predicate is_valid_N(integer N) =
        1 <= N && N <= 10000 && N % 1000 != 0;

    logic integer compute_result(integer N) =
        1000 - (N % 1000);

    lemma result_bounds:
        \forall integer N;
        is_valid_N(N) ==> 0 < compute_result(N) && compute_result(N) < 1000;
*/

int32_t func_second(int32_t N)
{
    uint32_t N_unsigned;
    uint32_t r;
    uint32_t result;

    //@ assert is_valid_N(N);
    
    if (N < 0)
    {
        N_unsigned = (uint32_t)(-N);
    }
    else
    {
        N_unsigned = (uint32_t)N;
    }
    
    r = N_unsigned % 1000;
    
    if (r == 0)
    {
        //@ assert r == 0;
        return 0;
    }
    else
    {
        //@ assert r != 0;
        result = 1000 - r;
        
        //@ assert result > 0;
        //@ assert result < 1000;
        //@ assert result == 1000 - (N % 1000);
        
        return (int32_t)result;
    }
}

/* predicate and lemma from third snippet */
/*@
    predicate valid_range_ab(integer a, integer b) =
        1 <= a && a <= b && b <= 20;

    lemma loop_decreases:
        \forall integer x, integer b; x < b ==> b - x > 0;
*/

int func_third(unsigned int a, unsigned int b)
{
    unsigned int x = 1;

    while (x < b)
    {
        x += 1;
        if (x == a)
        {
            //@ assert x == a;
            return 1;
        }
    }

    //@ assert x == b;
    return 0;
}

/* predicate and lemma from fourth snippet */
/*@ predicate valid_range_uv(integer a, integer b) =
      1 <= a && a <= 100 &&
      1 <= b && b <= 100;
*/

/*@ predicate result_condition(integer a, integer b, integer res) =
      res == (a * b + 1) || res == -1;
*/

/*@ lemma product_bounds: \forall integer a, b;
      valid_range_uv(a, b) ==> 1 <= a * b <= 10000;
*/

/*@ lemma addition_bounds: \forall integer a, b, product;
      valid_range_uv(a, b) && product == a * b ==> product + 1 <= 10001;
*/

int32_t func_fourth(uint32_t a, uint32_t b)
{
    uint32_t product;
    bool is_overflow = false;
    uint32_t result;
    int32_t final_result;
    
    //@ assert valid_range_uv(a, b);
    
    //@ assert 1 <= a * b && a * b <= 10000;
    product = a * b;
    
    if (a > 1 && b > 1)
    {
        if (a >= 100 && b >= 100)
        {
            is_overflow = true;
        }
        else if (a * b >= 10000)
        {
            is_overflow = true;
        }
    }
    
    if (is_overflow)
    {
        final_result = -1;
        //@ assert final_result == -1;
        return final_result;
    }
    
    //@ assert product + 1 <= 10001;
    result = product + 1;
    final_result = (int32_t)result;
    
    //@ assert final_result == (a * b + 1);
    return final_result;
}

/* ============================================================
   Synthesized function: validate_and_compute
   Scenario: A data validation and computation system for a
   resource allocation algorithm. Inputs represent resource
   parameters that must satisfy multiple constraints.
   The function validates a set of constraints using the first
   function, then computes a complementary value using the
   second function, checks a membership condition using the
   third function, and finally computes a derived metric using
   the fourth function. The high-level property ensures that
   when the first validation passes, the final computation
   result is consistent with the input parameters.
   ============================================================ */

int32_t validate_and_compute(
    unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    int32_t N,
    unsigned int x, unsigned int y,
    uint32_t u, uint32_t v)
{
    int32_t final_result;
    int valid_flag;
    int32_t complement;
    int membership_flag;
    int32_t computed_value;
    
    valid_flag = func_first(a, b, c, d);
    
    complement = func_second(N);
    
    membership_flag = func_third(x, y);
    
    computed_value = func_fourth(u, v);
    
    if (valid_flag == 1)
    {
        final_result = computed_value;
    }
    else
    {
        final_result = -1;
    }
    
    //@ assert final_result == -1 || final_result == (u * v + 1);
    return final_result;
}
