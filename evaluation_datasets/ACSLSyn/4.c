#include <stdint.h>
#include <stdbool.h>

/* First function: computes product if operands are in [1,9], else -1 */
/*@
    predicate in_small_range(integer a, integer b) =
        1 <= a && a <= 9 && 1 <= b && b <= 9;

    logic integer safe_product(integer a, integer b) =
        a * b;

    lemma product_bound:
        \forall integer a, b;
            in_small_range(a, b) ==> safe_product(a, b) <= 81;
*/

int64_t func1(int64_t a, int64_t b)
{
    int64_t result;
    result = -1;

    if (a >= 1 && a <= 9 && b >= 1 && b <= 9)
    {
        //@ assert in_small_range(a, b);
        //@ assert safe_product(a, b) <= 81;
        result = a * b;
    }

    return result;
}

/* Second function: equality check for boolean-like values (0 or 1) */
/*@ predicate in_range(integer v) = 0 <= v <= 1; */

bool func2(int x, int y)
{
    bool result;
    //@ assert in_range(x);
    //@ assert in_range(y);
    
    if (x == y) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (x == y);
    return result;
}

/* Scenario: Simple protocol validator.
   - Receives two pairs of values (a1,b1) and (a2,b2).
   - First pair is validated: if both values are in [1,9], compute product; else flag = -1.
   - Second pair must be boolean flags (0 or 1) indicating some status.
   - The synthesized function checks if the product is valid (non-negative) AND the boolean flags are equal.
   - High-level property: the output indicates a consistent state where both conditions hold.
*/

bool protocol_validator(int64_t a1, int64_t b1, int a2, int b2)
{
    int64_t prod;
    bool eq;

    prod = func1(a1, b1);
    //@ assert (in_small_range(a1, b1) ==> prod == a1 * b1) && (!in_small_range(a1, b1) ==> prod == -1);

    eq = func2(a2, b2);
    //@ assert eq == (a2 == b2);

    bool result = (prod != -1) && eq;

    //@ assert result <==> (in_small_range(a1, b1) && (a2 == b2));
    return result;
}
