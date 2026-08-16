/******************************************************************************
 * Real-world scenario: 
 *   "Smart Home Energy Budget Calculator"
 * 
 * The synthesized function calculates if a household's energy consumption 
 * (in scaled units, e.g., deca-Watt-hours) is within the budget.
 * Data flow:
 *   1. func1: scales an integer n (number of devices) by pi/100000 (some conversion factor)
 *   2. func2: computes ceil(n/2) for the number of active devices
 *   3. func3: calculates a "budget threshold" based on two parameters (a, b)
 *   4. func4: checks if at least one of three consumption readings is "active" (1)
 *
 * The synthesized function determines if the scaled consumption exceeds the budget,
 * and if so, checks if there is at least one "active high-consumption device" among three.
 ******************************************************************************/

#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

/* ==================== Provided functions (with ACSL) ==================== */

/* --- func1 (scaling with pi) --- */
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    logic integer scaled_pi(integer n) = (2 * n * 314159) / 100000;
*/

long func1(unsigned long n)
{
    unsigned long pi = 314159;
    unsigned long two = 2;
    unsigned long scale = 100000;
    unsigned long result = 0;
    unsigned long temp = n * two * pi;
    
    while (temp >= scale)
    {
        temp -= scale;
        result += 1;
    }
    
    //@ assert result == scaled_pi(n);
    
    return (long)result;
}

/* --- func2 (ceil(n/2)) --- */
/*@
    predicate is_valid_n(integer n) = 0 <= n && n <= 1000;
    
    logic integer half_plus_remainder(integer n) = n / 2 + n % 2;
    
    lemma division_property: \forall integer n; is_valid_n(n) ==> n == 2*(n/2) + n%2;
*/

unsigned int func2(unsigned int n)
{
    unsigned int half_n;
    unsigned int temp_n;
    unsigned int remainder;
    unsigned int result;
    
    half_n = 0;
    temp_n = n;
    
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        half_n += 1;
    }
    
    //@ assert temp_n == 0 || temp_n == 1;
    remainder = (temp_n == 1) ? 1 : 0;
    result = half_n + remainder;
    
    //@ assert result == half_n + remainder;
    return result;
}

/* --- func3 (budget threshold) --- */
/*@
    predicate a_in_range(integer a) = 2 <= a <= 100;
    predicate b_in_range(integer b) = 2 <= b <= 100;
    predicate both_in_range(integer a, integer b) = a_in_range(a) && b_in_range(b);
    
    logic integer target_value(integer a, integer b) = a * b - a - b + 1;
    
    lemma product_bound: \forall integer a, b; both_in_range(a, b) ==> a * b <= 10000;
    lemma expression_positive: \forall integer a, b; both_in_range(a, b) ==> target_value(a, b) > 0;
    lemma no_underflow: \forall integer a, b; both_in_range(a, b) ==> a * b >= a + b;
*/

uint32_t func3(uint32_t a, uint32_t b) {
    uint32_t result;
    
    //@ assert both_in_range(a, b);
    //@ assert a * b <= 10000;
    
    result = a * b;
    
    if (a < result) {
        result -= a;
    } else {
        result = 0;
    }
    
    if (b < result) {
        result -= b;
    } else {
        result = 0;
    }
    
    if (result != UINT32_MAX) {
        result += 1;
    }
    
    //@ assert result == target_value(a, b);
    //@ assert result > 0;
    
    return result;
}

/* --- func4 (check if any element is 1) --- */
/*@ predicate is_valid_element(integer x) = x == 0 || x == 1; */

/*@ lemma sum_positive_iff_one_exists:
      \forall integer a, b, c;
        is_valid_element(a) && is_valid_element(b) && is_valid_element(c) ==>
        (a + b + c >= 1 <==> (a == 1 || b == 1 || c == 1)); */

bool func4(const long v[3]) {
    long a;
    long b;
    long c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a == v[0];
    //@ assert b == v[1];
    //@ assert c == v[2];

    result = (a + b + c) >= 1;

    //@ assert a + b + c == v[0] + v[1] + v[2];
    return result;
}

/* ==================== Synthesized function ==================== */

int smart_home_energy_budget(
    unsigned long n,        // number of devices (1-100)
    unsigned int m,         // active device count (0-1000)
    uint32_t a,             // budget parameter a (2-100)
    uint32_t b,             // budget parameter b (2-100)
    const long v[3]         // three device status flags (0 or 1)
) {
    long consumption = func1(n);
    unsigned int active_devices = func2(m);
    uint32_t budget_threshold = func3(a, b);
    bool any_high_consumption = func4(v);

    int result = 0;
    if ((consumption + (long)active_devices) > (long)budget_threshold) {
        if (any_high_consumption) {
            result = 1;
        }
    }

    /*@ assert (result == 1) <==> 
          ( (scaled_pi(n) + (int)half_plus_remainder(m)) > (int)target_value(a, b) 
            && (v[0] == 1 || v[1] == 1 || v[2] == 1) ); */

    return result;
}
