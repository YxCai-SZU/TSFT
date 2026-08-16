#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_condition(integer n) = (n % 100) < 6;
*/

bool func_condition(unsigned long n)
{
    unsigned long remainder;

    remainder = n % 100;

    if (remainder < 6)
    {
        //@ assert remainder < 6;
        return true;
    }
    else
    {
        //@ assert remainder >= 6;
        return false;
    }
}

/*@
    predicate is_even(integer v) = v % 2 == 0;
    predicate is_odd(integer v) = v % 2 == 1;
*/

uint64_t func_even(uint64_t x)
{
    bool is_even = true;
    uint64_t temp = x;

    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp != 0)
    {
        is_even = false;
    }

    if (is_even)
    {
        //@ assert is_even(x);
        return x;
    }
    else
    {
        //@ assert is_odd(x);
        //@ assert is_even(2 * x);
        return 2 * x;
    }
}

/*@
    predicate valid_range(integer l) = 1 <= l && l <= 1000;
    
    logic integer remainder_condition(integer l) = 
        (l % 100 >= 10 && l % 100 <= 99) ? 1 : 0;
*/

bool func_range(unsigned int l)
{
    unsigned int n = 0;
    unsigned int temp_l = l;
    unsigned int r = 0;
    
    while (temp_l >= 100)
    {
        temp_l -= 100;
        n += 1;
    }
    
    r = temp_l;
    
    //@ assert r == l % 100;
    //@ assert remainder_condition(l) == ((r >= 10 && r <= 99) ? 1 : 0);
    
    return r >= 10 && r <= 99;
}

/*@
    predicate is_valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    predicate postcondition(integer n, integer k, bool result) =
        result == ((n + 1) / 2 >= k);
*/

bool func_params(unsigned long n, unsigned long k)
{
    bool result;
    
    //@ assert is_valid_params(n, k);
    
    //@ assert n >= 1;
    //@ assert ((n + 1) / 2 >= k) || ((n + 1) / 2 < k);
    
    if (((n + 1) / 2) >= k) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert postcondition(n, k, result);
    return result;
}

/*@
    predicate valid_packet(integer id, integer size, integer priority) =
        1 <= id <= 1000000000 &&
        1 <= size <= 1000 &&
        1 <= priority <= 100;

    predicate packet_processed_correctly(integer id, integer size, integer priority, 
                                          bool is_urgent, bool is_valid, bool is_high_priority) =
        (is_urgent == ((id % 100) < 6)) &&
        (is_valid == (size % 100 >= 10 && size % 100 <= 99)) &&
        (is_high_priority == (((priority + 1) / 2) >= 3));
*/

struct packet_result {
    bool is_urgent;
    bool is_valid;
    bool is_high_priority;
};

struct packet_result process_packet(unsigned long packet_id, unsigned int packet_size, unsigned long packet_priority)
{
    struct packet_result result;
    
    //@ assert 1 <= packet_id <= 1000000000;
    result.is_urgent = func_condition(packet_id);
    
    //@ assert 1 <= packet_size <= 1000;
    result.is_valid = func_range(packet_size);
    
    //@ assert 1 <= packet_priority <= 100;
    result.is_high_priority = func_params(packet_priority, 3);
    
    //@ assert packet_processed_correctly(packet_id, packet_size, packet_priority, result.is_urgent, result.is_valid, result.is_high_priority);
    
    return result;
}
