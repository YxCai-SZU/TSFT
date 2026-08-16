#include <stdbool.h>

/* ACSL predicates for the first function */
/*@
    predicate is_small(integer n) = n <= 100;
 */

/* First underlying function: checks if a number is small (<= 100) */
bool is_small_number(unsigned long long n)
{
    bool result;
    //@ assert n <= 100 || n > 100;
    result = (n <= 100);
    return result;
}

/* ACSL auxiliary definitions for the second function */
/*@
    logic integer power(integer x, integer n) = x * x;
    logic integer cuber(integer x) = x * x * x;

    lemma power_lemma:
        \forall integer x, integer n; x == 3 && n == 2 ==> power(x, n) == 9;

    lemma cuber_lemma:
        \forall integer x; x == 3 ==> cuber(x) == 27;
*/

/* Second underlying function: computes a + a^2 + a^3 for small a */
int compute_polynomial(int a)
{
    int result;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;

    result = a + (a * a) + (a * a * a);
    return result;
}

/* Synthesized function: Real-world scenario - Data validation for a simple
   sensor reading processor.
   The sensor provides a raw reading (n). If the reading is "small" (≤ 100),
   we process it as a coefficient (a) and compute a polynomial value.
   If the reading is large, we cap the coefficient to 10 and compute.
   The function ensures that the output polynomial value is always
   within a bounded range: [3, 1110] (since a in [1,10] gives min 1+1+1=3,
   max 10+100+1000=1110). */

int process_sensor_reading(unsigned long long n)
{
    int a;
    int result;

    if (is_small_number(n))
    {
        a = (int)n;
        //@ assert 1 <= a <= 10 || (a > 10 && a <= 100);
        if (a > 10)
        {
            a = 10;
        }
        //@ assert 1 <= a <= 10;
    }
    else
    {
        a = 10;
        //@ assert a == 10;
    }

    //@ assert 1 <= a <= 10;
    result = compute_polynomial(a);

    //@ assert 3 <= result <= 1110;

    return result;
}
