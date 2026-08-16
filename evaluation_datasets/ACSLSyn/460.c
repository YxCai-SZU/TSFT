#include <stdbool.h>
#include <limits.h>

/* ============================================================
   Function 1: Core computation with valid_range constraints
   ============================================================ */

/*@
    predicate valid_range_1(integer x) = 1 <= x <= 100;

    logic integer calculate_result(integer a, integer b, integer c) =
        a < b ?
            (b < c ? c + b : a + c)
        : (a < c ? a + c : a + b);

    lemma result_lower_bound:
        \forall integer a, b, c;
            valid_range_1(a) && valid_range_1(b) && valid_range_1(c) ==>
            calculate_result(a, b, c) >= 1;

    lemma result_upper_bound:
        \forall integer a, b, c;
            valid_range_1(a) && valid_range_1(b) && valid_range_1(c) ==>
            calculate_result(a, b, c) <= a + b + c;
*/

long func1(long a, long b, long c)
{
    long result;

    //@ assert valid_range_1(a) && valid_range_1(b) && valid_range_1(c);

    if (a < b)
    {
        if (b < c)
        {
            result = c + b;
        }
        else
        {
            result = a + c;
        }
    }
    else if (a < c)
    {
        result = a + c;
    }
    else
    {
        result = a + b;
    }

    //@ assert result == calculate_result(a, b, c);
    //@ assert result >= 1;
    //@ assert result <= a + b + c;

    return result;
}

/* ============================================================
   Function 2: Even sum check
   ============================================================ */

/*@ predicate is_even_sum(integer a, integer b) = (a + b) % 2 == 0; */

bool func2(int n, int a, int b)
{
    int diff;
    int sum;
    bool is_even;
    
    if (a > b) {
        diff = a - b;
    } else {
        diff = b - a;
    }
    
    sum = a + b;
    is_even = (sum % 2 == 0);
    
    //@ assert is_even == ((a + b) % 2 == 0);
    
    return is_even;
}

/* ============================================================
   Function 3: Division-based score mapping
   ============================================================ */

/*@
    predicate valid_range_3(integer x) = 400 <= x <= 1999;
    
    logic integer division_result(integer x) = 10 - (x / 200);
*/

int func3(int x)
{
    int result = -1;
    int quotient = 0;
    int remainder = x;
    int divisor = 200;
    
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }
    
    if (quotient == 1) {
        result = 9;
    } else if (quotient == 2) {
        result = 8;
    } else if (quotient == 3) {
        result = 7;
    } else if (quotient == 4) {
        result = 6;
    } else if (quotient == 5) {
        result = 5;
    } else if (quotient == 6) {
        result = 4;
    } else if (quotient == 7) {
        result = 3;
    } else if (quotient == 8) {
        result = 2;
    } else if (quotient == 9) {
        result = 1;
    }
    
    //@ assert result == 10 - (x / 200);
    
    return result;
}

/* ============================================================
   Function 4: Circle circumference approximation
   ============================================================ */

/*@
    predicate valid_range_4(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_pi = 31415926535;
    logic integer scaling_factor = 10000000000;
    
    logic integer target_value(integer r) = 
        (2 * r * scaled_pi) / scaling_factor;
*/

long func4(unsigned int r) {
    long pi_approx;
    long scale;
    long result;
    long temp;
    
    pi_approx = 31415926535L;
    scale = 10000000000L;
    result = 0;
    temp = 2 * (long)r * pi_approx;
    
    while (temp >= scale) {
        //@ assert temp >= scale;
        result += 1;
        temp -= scale;
    }
    
    //@ assert result == target_value(r);
    return result;
}

/* ============================================================
   Synthesized Function: Complex geometry problem solver
   Scenario: Given three points A, B, C on the boundary of a circle 
   with integer radius r (1-100), compute:
   1. The perimeter of triangle ABC (using func1)
   2. Whether the sum of two sides is even (using func2)
   3. A difficulty score for the problem (using func3)
   4. The circumference of the circle (using func4)
   Then combine these results into a final integer result.
   ============================================================ */

/*@
    predicate valid_scenario(integer r, integer a, integer b, integer c) =
        valid_range_4(r) && valid_range_1(a) && valid_range_1(b) && valid_range_1(c) &&
        2 <= (a+b) && (a+b) <= 100 && 1 <= a < b <= (a+b);
*/

long synthesized_function(unsigned int r, long a, long b, long c) 
{
    long perimeter_val = func1(a, b, c);
    
    int n = (int)(a + b);
    int a_int = (int)a;
    int b_int = (int)b;
    bool is_even = func2(n, a_int, b_int);
    
    int x;
    if (perimeter_val < 400) {
        x = 400;
    } else if (perimeter_val > 1999) {
        x = 1999;
    } else {
        x = (int)perimeter_val;
    }
    int score = func3(x);
    
    long circumference = func4(r);
    
    long final_result;
    if (is_even) {
        final_result = perimeter_val + circumference + (long)score;
    } else {
        final_result = perimeter_val * (long)score + circumference;
    }
    
    //@ assert final_result >= 0;
    
    return final_result;
}
