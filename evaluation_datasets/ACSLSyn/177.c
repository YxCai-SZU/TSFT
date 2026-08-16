#include <stdbool.h>

/* First function: range check with bounds */
/*@
    predicate valid_range(integer a, integer b, integer x) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100;
    
    logic integer sum_val(integer a, integer b) = a + b;
    
    lemma sum_bound: \forall integer a, b; 0 <= a <= 100 && 0 <= b <= 100 ==> sum_val(a, b) <= 200;
*/

bool func1(unsigned long long a, unsigned long long b, unsigned long long x) {
    unsigned long long sum;
    unsigned long long min_val;
    
    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100;
    
    sum = a + b;
    
    //@ assert sum <= 200;
    
    if (a < sum) {
        min_val = a;
    } else {
        min_val = sum;
    }
    
    //@ assert min_val <= 100;
    
    return b <= x && x <= a + b;
}

/* Second function: digit check for numbers 10-99 */
/*@
    predicate is_mod_10(integer n, integer r) =
        n % 10 == r;

    lemma mod_property:
        \forall integer n, m;
            n >= 10 && m >= 0 && m <= n && m % 10 == 0 ==>
            (n - m) % 10 == n % 10;
*/

int func2(unsigned long n)
{
    int result = 0;
    unsigned long temp_n = n;

    while (temp_n >= 10)
    {
        //@ assert temp_n % 10 == n % 10;
        temp_n -= 10;
    }

    //@ assert temp_n == n % 10;
    if (temp_n == 9 || n >= 90)
    {
        result = 1;
    }

    //@ assert result == (n % 10 == 9 || n >= 90);
    return result;
}

/* Synthesized function: Input validation for a two-digit security code system
   Scenario: A security system validates access codes. 
   The code consists of two parts: a range (a, b, x) and a two-digit number n.
   The function checks if the code is valid for a specific access level.
   Data flow: 
   - First, check if the range parameters are valid and the value x falls within [b, a+b]
   - Then, check if the two-digit number n has special properties (ends in 9 or >= 90)
   - The final result indicates whether the combined code is valid for high-security access
*/
int validate_access_code(unsigned long long a, unsigned long long b, unsigned long long x, unsigned long n)
{
    bool range_valid;
    int digit_valid;
    int result;
    
    range_valid = func1(a, b, x);
    
    digit_valid = func2(n);
    
    if (range_valid && digit_valid)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result == (b <= x && x <= a + b && (n % 10 == 9 || n >= 90));
    
    return result;
}
