#include <stdbool.h>
#include <stdint.h>

/* Original function 1: comparison with threshold */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_condition(integer a, integer b, bool result) = 
        result == (a > b && a - b > 2);
*/
bool func1(unsigned int a, unsigned int b)
{
    bool a_greater_than_b;
    bool a_minus_b_greater_than_2;
    bool result;
    
    a_greater_than_b = a > b;
    a_minus_b_greater_than_2 = a > b && a - b > 2;
    
    //@ assert a_minus_b_greater_than_2 == (a > b && a - b > 2);
    
    result = a_minus_b_greater_than_2;
    return result;
}

/* Original function 2: conditional multiplication */
/*@
    predicate in_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_even(integer a, integer b) =
        a * b * 2;

    logic integer compute_odd(integer a, integer b) =
        a * (b - 1) * 2;

    lemma even_bound: \forall integer a, b; in_range(a, b) && b % 2 == 0 ==> compute_even(a, b) <= 20000;
    lemma odd_bound: \forall integer a, b; in_range(a, b) && b % 2 == 1 ==> compute_odd(a, b) <= 19800;
*/
int64_t func2(uint64_t a, uint64_t b)
{
    int64_t result;

    if (b % 2 == 0) {
        //@ assert compute_even(a, b) <= 20000;
        result = (int64_t)a * (int64_t)b * 2;
    } else {
        //@ assert compute_odd(a, b) <= 19800;
        result = (int64_t)a * ((int64_t)b - 1) * 2;
    }

    return result;
}

/* Original function 3: interval condition check */
/*@
    predicate condition1(integer a, integer d, integer c) =
        a <= d && d <= a + c;

    predicate condition2(integer a, integer d, integer b, integer c) =
        d <= a + b && a + b <= d + c;

    predicate combined_condition(integer a, integer b, integer c, integer d) =
        condition1(a, d, c) || condition2(a, d, b, c);
*/
bool func3(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int diff;
    bool condition1;
    bool condition2;
    bool combined_condition;
    bool answer;

    if (a > d)
    {
        diff = a - d;
    }
    else
    {
        diff = d - a;
    }

    condition1 = (a <= d) && (d <= a + c);
    condition2 = (d <= a + b) && (a + b <= d + c);
    combined_condition = condition1 || condition2;

    if (combined_condition)
    {
        answer = true;
    }
    else
    {
        answer = false;
    }

    //@ assert answer == true <==> (a <= d && d <= a + c) || (d <= a + b && a + b <= d + c);
    return answer;
}

/* Original function 4: bounded increment loop */
uint32_t func4(uint32_t n, uint32_t m)
{
    uint32_t result = 0;
    uint32_t remaining = n;

    while (remaining > 0 && m > result) {
        //@ assert remaining > 0 && m > result;
        remaining -= 1;
        result += 1;
    }

    //@ assert result <= m;
    return result;
}

/* 
 * Synthesized function: Resource allocation with eligibility and capacity check
 */
uint32_t synthesize_func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, 
                         uint32_t n, uint32_t m)
{
    bool eligible;
    int64_t capacity_score;
    bool fits_in_window;
    uint32_t allocation;
    
    eligible = func1(a, b);
    
    capacity_score = func2((uint64_t)a, (uint64_t)b);
    
    unsigned int cap_uint;
    if (capacity_score <= 0) {
        cap_uint = 1;
    } else {
        cap_uint = (unsigned int)(capacity_score % 5000) + 1;
    }
    fits_in_window = func3(a, b, c, cap_uint);
    
    if (eligible && fits_in_window) {
        allocation = func4(n, m);
    } else {
        allocation = 0;
    }
    
    //@ assert allocation <= m;
    
    return allocation;
}
