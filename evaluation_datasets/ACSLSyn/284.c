#include <stdbool.h>
#include <stdint.h>

/* 
 * Real-world scenario: Network packet validation
 * This function validates a network packet's header fields and determines
 * if the packet should be processed or dropped.
 * 
 * Data flow:
 * 1. Check if the packet type (a) and priority (b) produce a valid odd/even flag
 * 2. Verify the packet identifier (a_val) contains digit 9 (reserved flag)
 * 3. Calculate packet size validation result based on three size fields
 */

/*@
    predicate product_in_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 ==> 1 <= a * b <= 9;

    lemma product_range_lemma:
        \forall integer a, b;
            1 <= a <= 3 && 1 <= b <= 3 ==> 1 <= a * b <= 9;
*/

bool func1(unsigned long a, unsigned long b) {
    unsigned long product;
    long remainder;
    unsigned long div_result;
    unsigned long temp_remainder;
    bool is_odd;

    product = a * b;
    
    //@ assert product_in_range(a, b);
    
    remainder = (long)product;
    
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    while (remainder < 0) {
        remainder += 2;
    }
    
    div_result = 0;
    temp_remainder = product;
    
    while (temp_remainder >= 2) {
        temp_remainder -= 2;
        div_result += 1;
    }
    
    //@ assert temp_remainder == 0 || temp_remainder == 1;
    
    if (temp_remainder == 1) {
        is_odd = true;
    } else {
        is_odd = false;
    }
    
    //@ assert is_odd == ((a * b) % 2 != 0);
    
    return is_odd;
}

/*@
    predicate is_nine(integer a) = a == 9;
    predicate is_two_digit_nine(integer a) = (a >= 90 && a <= 99) || (a % 10 == 9);
*/

bool func2(unsigned long long a)
{
    bool is_nine_val;
    bool is_two_digit_nine_val;
    bool result;

    is_nine_val = (a == 9);
    is_two_digit_nine_val = (a >= 90 && a <= 99) || (a % 10 == 9);

    //@ assert is_nine_val == (a == 9);
    //@ assert is_two_digit_nine_val == ((a >= 90 && a <= 99) || (a % 10 == 9));
    //@ assert is_nine_val || is_two_digit_nine_val == (a % 10 == 9 || a >= 90);

    result = is_nine_val || is_two_digit_nine_val;
    return result;
}

/*@
    predicate valid_range(integer x) = 0 <= x <= 50;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a :
        (b >= a && b >= c) ? b :
        c;

    lemma sum_bounds:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        0 <= a + b + c <= 150;

    lemma max_bound:
        \forall integer a, b, c, m;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        m == max_of_three(a, b, c) ==>
        m <= 50;

    lemma double_max_bound:
        \forall integer a, b, c, m;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        m == max_of_three(a, b, c) ==>
        2 * m <= 100;
*/

uint32_t func3(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max;
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    //@ assert max == max_of_three(a, b, c);
    //@ assert max <= 50;
    //@ assert 2 * max <= 100;
    //@ assert a + b + c >= 0;
    //@ assert a + b + c <= 150;

    if (a + b + c - max >= max)
    {
        result = 1;
    }
    else
    {
        result = 2;
    }

    //@ assert result == 1 || result == 2;
    return result;
}

/* 
 * Main synthesized function: Network packet validation
 * Determines if a packet should be processed based on:
 * - Packet type (type) and priority (priority) producing odd/even flag
 * - Packet identifier (id) containing digit 9 (reserved flag)
 * - Three size fields (size1, size2, size3) determining processing mode
 * 
 * High-level property: The output indicates a valid packet state transition
 * where the packet is either accepted (true) or dropped (false)
 */

bool validate_network_packet(unsigned long type, unsigned long priority,
                             unsigned long long id,
                             uint32_t size1, uint32_t size2, uint32_t size3)
{
    bool parity_flag;
    bool reserved_flag;
    uint32_t processing_mode;
    bool packet_valid;

    parity_flag = func1(type, priority);
    
    reserved_flag = func2(id);
    
    processing_mode = func3(size1, size2, size3);
    
    if (parity_flag && reserved_flag && processing_mode == 1) {
        packet_valid = true;
    } else {
        packet_valid = false;
    }
    
    //@ assert (packet_valid == true) ==> (parity_flag == true && reserved_flag == true && processing_mode == 1);
    
    return packet_valid;
}

int main() {
    return 0;
}
