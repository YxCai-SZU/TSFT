#include <stdbool.h>

/* ACSL specifications from first snippet */
/*@ predicate is_valid_range(integer a, integer b) =
    a >= 1 && a <= 100 && b >= 1 && b <= 100;
*/

/*@ lemma comparison_lemma:
    \forall integer a, b;
    is_valid_range(a, b) ==> (a > b) == (a > b);
*/

bool func1(int A[2])
{
    int a;
    int b;
    bool result;
    
    a = A[0];
    b = A[1];
    
    //@ assert is_valid_range(a, b);
    
    if (a > b) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (a > b);
    return result;
}

/* ACSL specifications from second snippet */
/*@
    predicate is_uint32(integer v) = 0 <= v <= 4294967295;

    logic integer bitwise_or(integer a, integer b) = a | b;

    lemma commutative_and:
        \forall integer x, y; is_uint32(x) && is_uint32(y) ==> (x & y) == (y & x);

    lemma commutative_or:
        \forall integer x, y; is_uint32(x) && is_uint32(y) ==> (x | y) == (y | x);
*/

unsigned int func2(unsigned int x, unsigned int y)
{
    unsigned int result;

    //@ assert is_uint32(x) && is_uint32(y);
    //@ assert (x & y) == (y & x);
    //@ assert (x | y) == (y | x);

    result = x | y;

    //@ assert result == bitwise_or(x, y);
    return result;
}

/* 
 * Scenario: Network packet header validation and flag combination
 * 
 * In network protocol processing, a packet header contains two 8-bit fields 
 * (range 1-100) that indicate priority and TTL values. The first function 
 * (func1) checks if priority > TTL (indicating high-priority packet). 
 * The second function (func2) combines two 32-bit flags from the packet 
 * header using bitwise OR. The synthesized function validates the packet 
 * header and combines the flags only if the packet has high priority.
 *
 * Data flow:
 * 1. Parse header fields A[0]=priority, A[1]=TTL from packet descriptor
 * 2. Use func1 to determine if priority > TTL (high priority)
 * 3. If high priority, use func2 to combine two flag values from header
 * 4. Result is the combined flags for high-priority packets, 0 otherwise
 */

unsigned int process_packet_header(int A[2], unsigned int flags1, unsigned int flags2)
{
    bool is_high_priority;
    unsigned int combined_flags;
    
    is_high_priority = func1(A);
    
    if (is_high_priority) {
        combined_flags = func2(flags1, flags2);
    } else {
        combined_flags = 0;
    }
    
    //@ assert (combined_flags == 0) || (combined_flags == bitwise_or(flags1, flags2));
    
    return combined_flags;
}
