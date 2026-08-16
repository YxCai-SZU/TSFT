#include <stdint.h>

/* Core predicates from first code snippet */
/*@
    predicate is_even(integer v) = v % 2 == 0;
    predicate is_odd(integer v) = v % 2 != 0;
*/

/* Predicates for second code snippet */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 &&
        1 <= m <= n &&
        m <= 5;

    logic integer base_value(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    logic integer max_value(integer n, integer m) =
        100 * (n - m) + 1900 * m * 2;

    lemma bounds_lemma:
        \forall integer n, m;
        valid_params(n, m) ==> base_value(n, m) <= max_value(n, m);
*/

/* First function: determines parity of iterated halving */
int func(unsigned int n)
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    int result;

    x = n / 2;
    if (x % 2 == 0)
    {
        //@ assert is_even(x);
        result = 1;
        return result;
    }
    else
    {
        y = x / 2;
        if (y % 2 == 0)
        {
            //@ assert is_even(y);
            result = 1;
            return result;
        }
        else
        {
            z = y / 2;
            if (z % 2 == 0)
            {
                //@ assert is_even(z);
                result = 1;
                return result;
            }
            else
            {
                //@ assert is_odd(z);
                result = 0;
                return result;
            }
        }
    }
}

/* Second function: computes a base value with shift adjustment */
int32_t func2(uint32_t n, uint32_t m)
{
    int32_t ans;
    uint32_t shift_count;
    uint32_t temp_m;

    //@ assert valid_params(n, m);
    
    ans = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    shift_count = 0;
    temp_m = m;

    while (temp_m > 0)
    {
        if (shift_count < m)
        {
            ans += 100;
            shift_count += 1;
        }
        temp_m -= 1;
    }

    //@ assert ans >= base_value(n, m);
    return ans;
}

/* 
 * Synthesized function: Real-world scenario - Salary calculation with parity-based bonus
 * 
 * Description: 
 *   Calculates employee salary where base salary is computed from parameters (n, m),
 *   and a bonus multiplier is determined by the parity property of n.
 *   The parity function (func) determines if the iterative halving of n yields an even number.
 *   The salary computation (func2) calculates a base salary with adjustments.
 *   The final salary is the base salary multiplied by a factor (1 or 2) based on the parity result.
 * 
 * Control flow: Sequential - calls func to get parity flag, then uses it to modify func2 result
 */

int32_t calculate_salary(uint32_t n, uint32_t m)
{
    int32_t base_salary;
    int32_t final_salary;
    int parity_flag;

    parity_flag = func(n);
    //@ assert parity_flag == 0 || parity_flag == 1;

    base_salary = func2(n, m);
    //@ assert base_salary >= base_value(n, m);
    //@ assert base_salary <= max_value(n, m);

    if (parity_flag == 1)
    {
        final_salary = base_salary * 2;
    }
    else
    {
        final_salary = base_salary;
    }

    //@ assert final_salary >= base_value(n, m);
    //@ assert final_salary <= 2 * max_value(n, m);
    
    return final_salary;
}
