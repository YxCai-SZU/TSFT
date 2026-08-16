#include <stdbool.h>

/* ACSL predicates from first function */
/*@
    predicate exactly_two_equal(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (a == c && a != b) ||
        (b == c && a != b);
 */

/* ACSL predicates from second function */
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 20;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma product_bound: 
        \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> multiply(a, b) <= 400;
*/

/* Original func1: checks if exactly two of three digits are equal */
bool func(int a, int b, int c)
{
    bool result;

    if ((a == b) && (a == c))
    {
        result = false;
    }
    else
    {
        bool ab = (a == b);
        bool bc = (b == c);
        bool ca = (c == a);
        result = (ab && !bc && !ca) || (bc && !ab && !ca) || (ca && !bc && !ab);
    }

    return result;
}

/* Original func2: multiplies two numbers and adjusts result if > 9 */
int func2(int v[2]) {
    int result;
    
    //@ assert valid_range(v[0]);
    //@ assert valid_range(v[1]);
    //@ assert multiply(v[0], v[1]) <= 400;
    
    result = v[0] * v[1];
    
    if (result > 9) {
        result = result - 1;
    }
    
    return result;
}

/* 
 * Real-world scenario: Digital lock code validation system
 * 
 * A security system validates a 3-digit access code (each digit 1-9) 
 * and generates a response code from a paired device ID.
 * 
 * The validation checks if exactly two digits of the access code are equal
 * (a common pattern in simple lock systems for redundancy).
 * 
 * The response is derived by multiplying two components of the device ID
 * (each in range 1-20) and applying a correction if the product exceeds 9.
 * 
 * The combined function ensures that when the access code has exactly two equal digits,
 * the response code must be less than or equal to 9 (i.e., the product was already ≤ 9
 * and no subtraction occurred), representing a valid entry state.
 */
int combined_func(int a, int b, int c, int v[2]) {
    bool code_valid;
    int response;
    
    code_valid = func(a, b, c);
    
    response = func2(v);
    
    if (code_valid && response <= 9) {
        return 1;
    } else {
        return 0;
    }
}
