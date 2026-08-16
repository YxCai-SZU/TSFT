#include <stdbool.h>

/* ACSL specifications from first snippet */
/*@
    predicate is_odd(integer x) = (x % 2) == 1;
    predicate is_even(integer x) = (x % 2) == 0;
    
    lemma odd_times_two_even: \forall integer x; is_odd(x) ==> is_even(x * 2);
    lemma even_divisible_by_input: \forall integer x, y; (y == x * 2 || y == x) && 1 <= x ==> y % x == 0;
*/

unsigned int func(unsigned int input)
{
    unsigned int result = input;
    const unsigned int two = 2;
    bool is_odd = false;
    unsigned int temp = input;
    
    
    while (temp >= two)
    {
        temp -= two;
    }
    
    if (temp == 1 || temp == 0)
    {
        is_odd = true;
    }
    
    if (is_odd)
    {
        result *= 2;
    }
    
    //@ assert result == input * 2 || result == input;
    //@ assert result % 2 == 0;
    //@ assert result >= input;
    
    return result;
}

/* ACSL specifications from second snippet */
/*@
    logic integer incrementor(integer x, integer k) = k + x;
*/

/*@
    lemma test_incrementor:
        incrementor(7, 3) == 10 &&
        incrementor(7, 0) == 7;
*/

/*@
    lemma proof_incrementor_all:
        \forall integer k, x;
            k >= 0 && x >= 0 ==>
            incrementor(x, k) == k + x;
*/

/* ACSL specifications from third snippet */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate c_in_range(integer c) = 1 <= c <= 10000;
    predicate d_in_range(integer d) = 1 <= d <= 10000;
    
    logic integer min_ab(integer a, integer b) = a < b ? a : b;
    logic integer min_cd(integer c, integer d) = c < d ? c : d;
    logic integer total_min(integer a, integer b, integer c, integer d) = 
        min_ab(a, b) + min_cd(c, d);
    
    lemma min_ab_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> min_ab(a, b) <= 10000;
    lemma min_cd_bound: \forall integer c, d; c_in_range(c) && d_in_range(d) ==> min_cd(c, d) <= 10000;
    lemma total_bound: \forall integer a, b, c, d; 
        a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d) ==> 
        total_min(a, b, c, d) <= 20000;
*/

long func2(long a, long b, long c, long d)
{
    long ans;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    
    ans = (a < b ? a : b) + (c < d ? c : d);
    
    //@ assert ans == total_min(a, b, c, d);
    return ans;
}

/* 
 * Scenario: Resource Allocator in a Packet Processing System
 * 
 * Data flow:
 * 1. func() computes an even, aligned buffer size (size) from a base size input
 * 2. func2() computes the minimum of two pairs of resource counts (min_res)
 * 3. incrementor() combines aligned size with min resource count to get total allocation
 */

unsigned long synthesize_function(unsigned int input, long a, long b, long c, long d)
{
    unsigned int size;
    long min_res;
    unsigned long total_allocation;
    
    size = func(input);
    
    min_res = func2(a, b, c, d);
    
    //@ assert incrementor((integer)size, (integer)min_res) == min_res + size;
    total_allocation = (unsigned long)(min_res + size);
    
    //@ assert total_allocation >= input + ((a < b ? a : b) + (c < d ? c : d));
    
    return total_allocation;
}
