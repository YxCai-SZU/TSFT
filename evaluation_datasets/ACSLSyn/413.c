#include <stdbool.h>
#include <stdint.h>

/* Predicates from original functions */
/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer product(integer n, integer m) = n * m;
    lemma product_range: 
        \forall integer n, integer m; 
        1 <= n <= 100 && 1 <= m <= 100 ==> 1 <= product(n, m) <= 10000;
*/

/*@
    predicate is_in_range(integer x) = 1 <= x <= 9;
    predicate two_equal_one_different(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (b == c && b != a) ||
        (c == a && c != b);
*/

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    logic integer mul(integer a, integer b) = a * b;
    logic integer add(integer a, integer b) = a + b;
    logic integer double_val(integer x) = x * 2;
    lemma mul_bounds: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> mul(a, b) <= 9;
    lemma double_bounds: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> double_val(mul(a, b)) <= 18;
    lemma add_bounds: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> add(a, b) <= 6;
*/

/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100000;
    predicate is_valid_bound(integer m) = 1 <= m && m <= 1000000000;
    predicate is_valid_element(integer x, integer m) = 1 <= x && x <= m;
    predicate is_power_of_two_and_in_range(integer x, integer m) = 
          (x & 1) == 0 && (x & m) == x;
    lemma count_bound: \forall integer count, integer n; 
          is_valid_range(n) && count <= n ==> count <= 100000;
*/

/* Original function 1 */
bool func1(unsigned int n, unsigned int m)
{
    unsigned int product_val;
    bool result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    //@ assert 1 <= product(n, m) <= 10000;
    
    product_val = n * m;
    result = (product_val % 2 == 0);
    
    //@ assert result == true <==> is_even(product(n, m));
    
    return result;
}

/* Original function 2 */
bool func2(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);

    if (a == b && a != c) {
        result = true;
    } else if (b == c && b != a) {
        result = true;
    } else if (c == a && c != b) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

/* Original function 3 */
bool func3(unsigned long long a, unsigned long long b)
{
    unsigned long long c;
    unsigned long long d;
    bool result;
    
    //@ assert a * b <= 9;
    //@ assert a * b * 2 <= 18;
    //@ assert a + b <= 6;
    
    c = a * b * 2;
    d = a + b;
    
    if (c == d)
    {
        result = true;
    }
    else if (c == d - 1)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}

/* Original function 4 */
uint32_t func4(uint32_t n, uint32_t m, uint32_t numbers[]) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    while (index < n) {
        uint32_t x = numbers[index];
        
        //@ assert is_valid_element(x, m);
        if ((x & 1) == 0 && (x & m) == x) {
            count++;
            //@ assert count <= index + 1;
        }
        index++;
        //@ assert count <= index;
    }
    
    //@ assert count <= n;
    return count;
}

/* 
 * Scenario: Data validation pipeline for a smart grid power distribution system.
 * The system processes voltage readings from multiple sensors, checks for valid 
 * patterns, and counts how many sensors meet specific power-of-two distribution criteria.
 * 
 * Data flow:
 * 1. Check if product of two sensor IDs is even (power distribution check)
 * 2. Validate that three frequency readings have exactly two equal (phase matching)
 * 3. Verify that two amplitude values satisfy a specific energy relation
 * 4. Count sensors with valid power-of-two distribution patterns
 */

uint32_t synthesized_func(
    unsigned int n, unsigned int m,
    unsigned int a, unsigned int b,
    unsigned int d, unsigned int e, unsigned int f,
    uint32_t g, uint32_t h, uint32_t numbers[])
{
    bool result1, result2, result3;
    uint32_t result4;
    uint32_t final_count = 0;
    
    result1 = func1(n, m);
    
    result2 = func2(d, e, f);
    
    result3 = func3(a, b);
    
    result4 = func4(g, h, numbers);
    
    if (result1 && result2 && result3) {
        final_count = result4;
    }
    
    //@ assert final_count <= g;
    
    return final_count;
}
