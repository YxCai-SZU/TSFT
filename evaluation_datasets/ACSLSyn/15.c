#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates from first function */
/*@
    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
    predicate strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;
    predicate is_monotonic(integer a, integer b, integer c) =
        strictly_increasing(a, b, c) || strictly_decreasing(a, b, c);
*/

/* Original first function: check monotonicity of three values */
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;
    
    //@ assert a != b && b != c && a != c;
    
    if (a < b)
    {
        if (b < c)
        {
            //@ assert strictly_increasing(a, b, c);
            result = true;
        }
        else
        {
            //@ assert !strictly_decreasing(a, b, c);
            result = false;
        }
    }
    else
    {
        if (b > c)
        {
            //@ assert strictly_decreasing(a, b, c);
            result = true;
        }
        else
        {
            //@ assert !strictly_increasing(a, b, c);
            result = false;
        }
    }
    
    //@ assert result == (a < b && b < c || a > b && b > c);
    return result;
}

/* Original second function: safe doubling */
/*@
    predicate is_valid_u8(integer x) = 0 <= x < 256;
    logic integer double_spec(integer x) = 2 * x;
*/

uint8_t double_u8(uint8_t x)
{
    //@ assert 0 <= x < 128;
    //@ assert 2 * x < 256;
    return 2 * x;
}

/* Synthesized function: validate monotonic sequence of byte-sized values
 * Scenario: In a sensor data processing pipeline, we receive three consecutive 
 * readings (0-100) that must be strictly monotonic. Each reading is doubled 
 * (as a uint8_t) for transmission, and we verify the doubled values remain 
 * monotonic, ensuring data integrity through transformation.
 */
bool validate_monotonic_doubled(uint8_t a, uint8_t b, uint8_t c)
{
    uint8_t da, db, dc;
    bool monotonic_original;
    
    da = double_u8(a);
    db = double_u8(b);
    dc = double_u8(c);
    
    //@ assert da == 2 * a && db == 2 * b && dc == 2 * c;
    
    monotonic_original = func(a, b, c);
    
    //@ assert monotonic_original ==> (da < db && db < dc || da > db && db > dc);
    
    //@ assert monotonic_original == (a < b && b < c || a > b && b > c);
    return monotonic_original;
}
