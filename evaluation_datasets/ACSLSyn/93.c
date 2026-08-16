#include <stdint.h>
#include <stdbool.h>

/* Original function 1: counts something based on n and p */
/*@ predicate p_in_range(integer n, integer p) = 1 <= p <= n <= 200000; */


/*@ lemma count_bound: \forall integer n, integer p, integer count;
      p_in_range(n, p) && count <= n - p + 1 ==> count <= n; */

uint32_t func1(uint32_t n, uint32_t p)
{
    uint32_t count = 0;
    uint32_t i = 1;

    while (i <= n - p + 1)
    {
        //@ assert 1 <= i <= n - p + 2;
        //@ assert count <= i - 1;
        
        if ((p - 1 + i) <= n)
        {
            //@ assert p - 1 + i <= n;
            count += 1;
            i += 1;
        }
        else
        {
            break;
        }
        
        //@ assert count <= i - 1;
        //@ assert count <= n;
        //@ assert count <= n - p + 1;
    }
    
    //@ assert count <= n;
    //@ assert count <= n - p + 1;
    return count;
}

/* Original function 2: checks if a+b is even */
/*@
    predicate valid_params(integer n, integer a, integer b) =
        2 <= n && n <= 100 &&
        1 <= a && a < b && b <= n;

    logic integer absolute_diff(integer a, integer b) =
        a > b ? a - b : b - a;

    lemma diff_bound: \forall integer n, a, b;
        valid_params(n, a, b) ==> absolute_diff(a, b) <= n;
*/

bool func2(unsigned int n, unsigned int a, unsigned int b)
{
    unsigned int diff;

    //@ assert valid_params(n, a, b);
    diff = a > b ? a - b : b - a;
    
    //@ assert absolute_diff(a, b) <= n;
    return (a + b) % 2 == 0;
}

/* Original function 3: checks if all pairs sum to even */
/*@
    predicate all_even(integer a, integer b, integer c) =
        (a + b) % 2 == 0 && (b + c) % 2 == 0 && (a + c) % 2 == 0;
*/

bool func3(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int t;
    t = 0;

    if ((A + B) % 2 == 0)
    {
        t += 1;
    }
    if ((B + C) % 2 == 0)
    {
        t += 1;
    }
    if ((A + C) % 2 == 0)
    {
        t += 1;
    }

    //@ assert t == 3 ==> ((B + C) % 2 == 0 && (A + C) % 2 == 0 && (A + B) % 2 == 0);

    return t == 3;
}

/* Synthesized function: Simulates a three-stage data validation pipeline
   Scenario: A data processing system validates a sequence of data packets.
   Stage 1 (func1): Counts available slots in a buffer (n, p parameters represent buffer capacity and packet size)
   Stage 2 (func2): Validates if two data fields (a, b) have even parity sum
   Stage 3 (func3): Checks if three data fields (A, B, C) all have even parity sums

   The pipeline processes input data and asserts that if all stages pass, the final output 
   guarantees the data has consistent parity properties across all fields. */
bool synthesized_func(uint32_t n, uint32_t p, unsigned int n2, unsigned int a, unsigned int b,
                      unsigned int A, unsigned int B, unsigned int C)
{
    uint32_t count;
    bool parity_ok;
    bool all_even_ok;

    count = func1(n, p);
    //@ assert count <= n && count <= n - p + 1;

    parity_ok = func2(n2, a, b);
    //@ assert parity_ok == ((a + b) % 2 == 0);

    all_even_ok = func3(A, B, C);
    //@ assert all_even_ok ==> all_even(A, B, C);

    //@ assert (parity_ok && all_even_ok) ==> (all_even(A, B, C) && ((a + b) % 2 == 0));

    return parity_ok && all_even_ok;
}
