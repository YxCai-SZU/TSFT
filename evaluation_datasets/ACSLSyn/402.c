#include <stdint.h>
#include <stdbool.h>

/* First function: calculate_target_count */
/*@ predicate valid_params(integer k, integer x) =
     1 <= k <= 100 && 1 <= x <= 100000;
*/
uint32_t calculate_target_count(uint32_t k, uint32_t x)
{
    uint32_t current_count;
    uint32_t remaining_growth;
    
    current_count = 1;
    remaining_growth = x - 1;
    
    while (remaining_growth >= k)
    {
        //@ assert remaining_growth >= k;
        current_count = current_count + k;
        remaining_growth = remaining_growth - k;
        //@ assert current_count + remaining_growth == x;
    }
    
    //@ assert current_count >= 1;
    //@ assert current_count <= x;
    return current_count;
}

/* Second function: ordered check */
/*@
    predicate bounds(integer v) = -100 <= v <= 100;
    predicate in_range(integer v) = 0 <= v <= 1;
    predicate result_condition(integer a, integer b, integer c, bool r) =
        r == (a < b && b < c);
*/
bool func_ordered(int a, int b, int c)
{
    int d;
    int e;
    bool ret_val;

    d = 0;
    e = 0;

    if (a < b) {
        d = 1;
    } else {
        d = 0;
    }

    if (b < c) {
        e = 1;
    } else {
        e = 0;
    }

    //@ assert in_range(d);
    //@ assert in_range(e);
    //@ assert d * e <= 1;

    ret_val = (d * e == 1);
    return ret_val;
}

/* Third function: temperature classification */
/*@
    predicate valid_range(integer x) = 400 <= x && x <= 1999;
    logic integer compute_temp(integer x, integer c) = x - 400 - 200 * c;
    lemma temp_nonnegative:
        \forall integer x, c; valid_range(x) && c >= 0 && compute_temp(x, c) >= 200 ==>
            compute_temp(x, c) >= 0;
*/
int64_t func_temperature(int64_t x)
{
    int64_t result;
    int64_t temp;
    int64_t count;
    
    result = 8;
    temp = x - 400;
    count = 0;
    
    while (temp >= 200) {
        //@ assert temp >= 200;
        temp -= 200;
        count += 1;
    }
    
    result -= count;
    //@ assert 1 <= result && result <= 8;
    return result;
}

/* Fourth function: change calculation */
/*@
    predicate is_valid_params(integer n, integer a) =
        1 <= n <= 100000 && 0 <= a <= 1000000000;
    logic integer compute_change(integer n, integer pay) = n - (pay * 500);
*/
bool func_change(unsigned long n, unsigned long a)
{
    unsigned long pay;
    unsigned long change;
    bool result;

    pay = n / 500;
    change = n - (pay * 500);

    //@ assert change == compute_change(n, pay);

    result = change <= a;
    return result;
}

struct ticket_result {
    uint32_t count;
    bool ordered;
    int64_t category;
    bool affordable;
};

/* Synthesized function: ticket pricing and availability checker */
/*@
    predicate valid_ticket_params(integer k, integer x, integer a, integer b, integer c, integer temp,
                                   unsigned long n, unsigned long a_val) =
        valid_params(k, x) && bounds(a) && bounds(b) && bounds(c) && 
        valid_range(temp) && is_valid_params(n, a_val);
    
    predicate synthesized_property(integer k, integer x, integer a, integer b, integer c, integer temp,
                                   unsigned long n, unsigned long a_val,
                                   uint32_t count, bool ordered, int64_t category, bool affordable) =
        (count >= 1 && count <= x) &&
        (ordered == (a < b && b < c)) &&
        (category >= 1 && category <= 8) &&
        (affordable == ((n % 500) <= a_val));
*/
struct ticket_result process_ticket(uint32_t k, uint32_t x, int a, int b, int c, int64_t temp, unsigned long n, unsigned long a_val)
{
    struct ticket_result res;
    
    res.count = calculate_target_count(k, x);
    
    res.ordered = func_ordered(a, b, c);
    
    res.category = func_temperature(temp);
    
    res.affordable = func_change(n, a_val);
    
    //@ assert (res.count >= 1 && res.count <= x) && (res.ordered == (a < b && b < c)) && (res.category >= 1 && res.category <= 8) && (res.affordable == ((n % 500) <= a_val));
    
    return res;
}
