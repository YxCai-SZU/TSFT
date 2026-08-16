#include <stdbool.h>

/* Original first function: checks if a two-digit number satisfies a condition */
/*@
    predicate is_valid_range(integer n) = 10 <= n && n <= 99;
    logic integer condition_holds(integer n) = n % 10 == 9 || n >= 90 ? 1 : 0;
    lemma mod_property: \forall integer n; is_valid_range(n) ==> 
        (n % 10 == 9 || n >= 90) == ((unsigned)n % 10 == 9 || (unsigned)n >= 90);
*/
bool func1(int n)
{
    unsigned int n_unsigned;
    bool result;

    //@ assert is_valid_range(n);
    n_unsigned = (unsigned int)n;

    if (n_unsigned % 10 == 9 || n_unsigned >= 90)
    {
        //@ assert n_unsigned % 10 == 9 || n_unsigned >= 90;
        result = true;
    }
    else
    {
        //@ assert n_unsigned % 10 != 9 && n_unsigned < 90;
        result = false;
    }

    return result;
}

/* Original second function: computes product of two small numbers or returns -1 */
/*@
    predicate is_small(integer v) = 1 <= v && v <= 9;
    predicate both_small(integer a, integer b) = is_small(a) && is_small(b);
    logic integer safe_product(integer a, integer b) = a * b;
*/
int func2(const int a[2]) {
    int result;
    int x;
    int y;

    //@ assert a[0] >= 1 && a[0] <= 20;
    //@ assert a[1] >= 1 && a[1] <= 20;

    if (a[0] >= 10 || a[1] >= 10) {
        result = -1;
        //@ assert (a[0] >= 10 || a[1] >= 10) ==> result == -1;
        return result;
    } else {
        x = a[0];
        y = a[1];
        //@ assert is_small(x);
        //@ assert is_small(y);
        //@ assert both_small(x, y);
        //@ assert 1 <= safe_product(x, y) && safe_product(x, y) <= 81;
        result = x * y;
        //@ assert (a[0] < 10 && a[1] < 10) ==> result == safe_product(a[0], a[1]);
        return result;
    }
}

/* 
 * Scenario: Two-digit number and small multiplier validation in a simple encryption scheme.
 * 
 * The synthesized function takes a two-digit number (10-99) and an array of two integers (1-20 each).
 * It uses func1 to check if the two-digit number is "special" (ends with 9 or is >= 90).
 * Then it uses func2 to compute the product of the two array elements if both are small (< 10).
 * The final result encodes: if the two-digit number is special and both array elements are small,
 * return the product; otherwise return -1.
 * 
 * High-level property: The result is consistent with the special condition and product availability.
 * Specifically, if the two-digit number is special and both multipliers are small, the result is
 * a valid product (1-81). Otherwise, the result is -1.
 */
int synthesized_func(int n, const int a[2]) {
    bool special;
    int product;

    special = func1(n);
    //@ assert special == (condition_holds(n) == 1);

    product = func2(a);
    //@ assert (a[0] < 10 && a[1] < 10) ==> product == safe_product(a[0], a[1]);
    //@ assert (a[0] >= 10 || a[1] >= 10) ==> product == -1;

    if (special && product != -1) {
        //@ assert condition_holds(n) == 1;
        //@ assert a[0] < 10 && a[1] < 10;
        //@ assert 1 <= product && product <= 81;
        return product;
    } else {
        //@ assert !(condition_holds(n) == 1 && a[0] < 10 && a[1] < 10);
        return -1;
    }
}
