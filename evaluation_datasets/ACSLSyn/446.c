#include <stdbool.h>

/* Original functions with their ACSL specifications */

/* Function 1: Range validation and product bound checking */
/*@
    predicate max_val(integer n, integer m, integer result) =
        (n > m ==> result == n) && (n <= m ==> result == m);
    predicate min_val(integer n, integer m, integer result) =
        (n < m ==> result == n) && (n >= m ==> result == m);
    predicate product_bounds(integer n, integer m) =
        1 <= n <= 1000 && 1 <= m <= 1000 ==> n * m <= 1000 * 1000;
    predicate subtraction_safe(integer n, integer m) =
        1 <= n <= 1000 && 1 <= m <= 1000 ==> n * m >= (n - 1) + (m - 1);
    lemma product_bound_lemma:
        \forall integer n, m; 1 <= n <= 1000 && 1 <= m <= 1000 ==> n * m <= 1000000;
    lemma subtraction_safe_lemma:
        \forall integer n, m; 1 <= n <= 1000 && 1 <= m <= 1000 ==> n * m >= (n - 1) + (m - 1);
*/

bool func1(int n, int m, int k)
{
    int max_val;
    int min_val;
    bool result;

    //@ assert product_bounds(n, m);
    //@ assert subtraction_safe(n, m);

    if (n > m)
    {
        max_val = n;
    }
    else
    {
        max_val = m;
    }
    //@ assert max_val(n, m, max_val);

    if (n < m)
    {
        min_val = n;
    }
    else
    {
        min_val = m;
    }
    //@ assert min_val(n, m, min_val);

    //@ assert n * m <= 1000 * 1000;
    //@ assert n * m >= (n - 1) + (m - 1);

    result = k <= (n * m - (max_val - 1) - (min_val - 1));
    //@ assert result == (k <= (n * m - (n - 1) - (m - 1)));
    return result;
}

/* Function 2: Pair validation with offset check */
/*@ predicate within_range(integer x) = -100 <= x && x <= 100; */

bool func2(int v[2]) {
    int a;
    int b;
    
    a = v[0];
    b = v[1];
    
    //@ assert within_range(a);
    //@ assert within_range(b);
    
    return a <= b + 2 && b <= a - 2;
}

/* Function 3: Two-digit number containing digit 9 check */
/*@
    predicate is_two_digit(integer n) = 10 <= n && n <= 99;
    lemma two_digit_range: \forall integer n; is_two_digit(n) ==> 10 <= n && n <= 99;
*/

bool func3(unsigned long n)
{
    //@ assert is_two_digit(n);
    return n / 10 == 9 || n % 10 == 9;
}

/* Function 4: Conditional formula checker for three values */
/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 9;
    predicate condition_formula(integer a, integer b, integer c) =
        (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
*/

bool func4(long a, long b, long c)
{
    bool result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);

    if (a == b)
    {
        if (a == c)
        {
            result = false;
        }
        else
        {
            result = true;
        }
    }
    else if (a == c)
    {
        result = true;
    }
    else if (b == c)
    {
        result = true;
    }
    else
    {
        //@ assert !condition_formula(a, b, c);
        result = false;
    }

    //@ assert result == true <==> condition_formula(a, b, c);
    return result;
}

/* Scenario: Lottery ticket validation system
 * A lottery ticket has:
 * - 3 main numbers (1-9) that must have exactly one pair matching
 * - A bonus number (10-99) that must contain digit 9
 * - A multiplier pair (-100 to 100) that must be offset by at least 2
 * - The ticket value must be within product bounds
 * The system validates all these conditions and returns whether the ticket is valid.
 */

/*@
    predicate ticket_valid(integer a, integer b, integer c, unsigned long bonus, 
                          int *mult, integer n, integer m, integer k) =
        condition_formula(a, b, c) && 
        (bonus / 10 == 9 || bonus % 10 == 9) &&
        (mult[0] <= mult[1] + 2 && mult[1] <= mult[0] - 2) &&
        (k <= (n * m - (n - 1) - (m - 1)));
*/

bool validate_lottery_ticket(long a, long b, long c, unsigned long bonus, 
                             int *mult, int n, int m, int k)
{
    bool pair_condition = func4(a, b, c);
    //@ assert pair_condition == true <==> condition_formula(a, b, c);
    
    bool bonus_condition = func3(bonus);
    //@ assert bonus_condition == (bonus / 10 == 9 || bonus % 10 == 9);
    
    bool multiplier_condition = func2(mult);
    //@ assert multiplier_condition == (mult[0] <= mult[1] + 2 && mult[1] <= mult[0] - 2);
    
    bool bounds_condition = func1(n, m, k);
    //@ assert bounds_condition == (k <= (n * m - (n - 1) - (m - 1)));
    
    bool result = pair_condition && bonus_condition && multiplier_condition && bounds_condition;
    
    //@ assert result == true <==> ticket_valid(a, b, c, bonus, mult, n, m, k);
    return result;
}
