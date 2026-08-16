#include <stdbool.h>

/* Original function 1: Checks if b >= a */
/*@
    predicate within_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    predicate result_condition(bool result, integer a, integer b) =
        result == (b >= a);
*/

bool func1(int a, int b)
{
    int c;
    bool result;
    
    c = a + b;
    result = true;
    
    if (b < a)
    {
        result = false;
    }
    
    //@ assert result == (b >= a);
    
    return result;
}

/* Original function 2: Checks if bit 15 (0x8000) is set in x */
/*@
    predicate is_bit_set(integer x) = (x & 0x8000) == 0x8000;
*/

bool func2(unsigned int x)
{
    bool result;
    
    //@ assert x <= 0x10000;
    //@ assert x >= 1;
    
    result = (x & 0x8000) == 0x8000;
    
    return result;
}

/* 
 * Synthesized function: Real-world scenario - Network packet priority validation
 * For a network packet with priority field (a) and payload size (b), and a flag (x)
 * representing a protocol feature bitmask, the function validates that:
 * - Priority and payload size are within valid range
 * - If the packet is "high priority" (priority <= 50), then the protocol must support
 *   a specific feature (bit 15 set in x) for the payload to be non-zero (b >= a)
 * - The final result indicates a valid packet configuration
 */
/*@
    predicate valid_packet_config(int a, int b, unsigned int x) =
        (within_range(a, b) && (a <= 50 ==> (is_bit_set(x) ==> (b >= a))));
*/

bool process_packet(int a, int b, unsigned int x)
{
    bool priority_valid = func1(a, b);       // b >= a
    bool feature_valid = func2(x);           // bit 15 set in x
    
    bool result;
    
    if (a <= 50 && feature_valid)
    {
        result = priority_valid;
    }
    else
    {
        result = true;  // Other cases are always valid
    }
    
    //@ assert result <==> (within_range(a, b) && (a <= 50 ==> (is_bit_set(x) ==> (b >= a))));
    
    return result;
}
