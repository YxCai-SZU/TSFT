#include <stdint.h>
#include <stdbool.h>

/* First function: compute a bounded sum based on constraints */
/*@
    predicate valid_range(integer x) = 0 <= x <= 50;
    logic integer sum(integer a, integer b, integer c) = a + b + c;
*/

int64_t func1(int64_t a, int64_t b, int64_t c)
{
    int64_t result = 0;
    
    if (c > 0)
    {
        if (b < c)
        {
            //@ assert b * 2 + 1 <= 101;
            result += b * 2 + 1;
            
            int64_t c_temp = c - (b + 1);
            int64_t a_temp = (a > 1) ? (a - 1) : 0;
            int64_t add_val = (a_temp + 1 < c_temp) ? (a_temp + 1) : c_temp;
            result += add_val;
        }
        else
        {
            //@ assert c * 2 <= 100;
            result += c * 2;
        }
    }
    
    //@ assert result <= sum(a, b, c);
    return result;
}

/* Second function: check if (n % 100) * 21 < n */
/*@
    predicate is_valid_n(integer n) = 1 <= n <= 100000;

    logic integer mod_100(integer n) = n % 100;
    logic integer div_100(integer n) = n / 100;

    lemma mod_div_relation:
        \forall integer n; n == div_100(n) * 100 + mod_100(n);

    lemma mod_range:
        \forall integer n; n >= 0 ==> 0 <= mod_100(n) < 100;

    lemma div_range:
        \forall integer n; n >= 0 ==> 0 <= div_100(n) <= n;
*/

int func2(int n)
{
    int n_mod_100;
    int n_div_100;
    int n_mod_100_times_21;
    int i;
    int n_div_100_times_100;

    //@ assert is_valid_n(n);
    n_mod_100 = n % 100;
    n_div_100 = n / 100;

    //@ assert n_mod_100 == mod_100(n);
    //@ assert n_div_100 == div_100(n);
    //@ assert n == n_div_100 * 100 + n_mod_100;

    n_mod_100_times_21 = 0;
    i = 0;

    while (i < n_mod_100)
    {
        n_mod_100_times_21 += 21;
        i += 1;
    }

    //@ assert n_mod_100_times_21 == n_mod_100 * 21;

    n_div_100_times_100 = 0;
    i = 0;

    while (i < n_div_100)
    {
        n_div_100_times_100 += 100;
        i += 1;
    }

    //@ assert n_div_100_times_100 == n_div_100 * 100;
    //@ assert n == n_div_100_times_100 + n_mod_100;

    if (n_mod_100_times_21 < n)
    {
        //@ assert (n % 100) * 21 < n;
        return 1;
    }
    else
    {
        //@ assert (n % 100) * 21 >= n;
        return 0;
    }
}

/* Synthesized function: Resource allocation validator */
/* Scenario: A resource allocator that checks if a request can be granted
   based on available resources (a, b, c) and a priority code (n).
   The function computes a bounded usage from func() and validates it
   against a threshold derived from func()'s result using the check from func().
   Data flow: func(a,b,c) computes max usage, then func() checks if that usage
   satisfies a property relative to the priority code n. */

int resource_allocator(int64_t a, int64_t b, int64_t c, int n)
{
    int64_t usage = func1(a, b, c);
    
    //@ assert usage >= 0 && usage <= sum(a, b, c);
    
    /* Convert usage to int for func() - it fits because usage <= sum(a,b,c) <= 150 */
    int usage_int = (int)usage;
    
    /* Ensure usage_int is valid for func */
    if (usage_int < 1)
    {
        usage_int = 1;
    }
    if (usage_int > 100000)
    {
        usage_int = 100000;
    }
    
    int result = func2(usage_int);
    
    /* High-level property: The allocation decision is consistent with the bounded usage
       and the priority check. Specifically, if func() returns 1, then the usage satisfies
       (usage % 100) * 21 < usage, meaning the usage is "efficient" relative to its last two digits.
       If it returns 0, the usage is not efficient. */
    //@ assert (result == 1) ==> ((usage_int % 100) * 21 < usage_int);
    //@ assert (result == 0) ==> ((usage_int % 100) * 21 >= usage_int);
    
    return result;
}
