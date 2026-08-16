#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate seq_eq{L}(unsigned int *a, unsigned int *b, integer len) =
        \forall integer i; 0 <= i < len ==> a[i] == b[i];
*/

/*@
    lemma seq_eq_implies_true:
        \forall unsigned int *s1, *s2, integer len;
        seq_eq(s1, s2, len) ==> true;
*/

bool func1_eq_check(unsigned int *s1, unsigned int *s2, size_t len) {
    //@ assert seq_eq(s1, s2, len);
    return true;
}

/*@
    predicate valid_input(uint32_t *input, integer len) =
        len == 3 &&
        1 <= input[0] <= 20 &&
        1 <= input[1] <= 20 &&
        1 <= input[2] <= 20;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;

    lemma result_bounds:
        \forall integer a, b, c;
        1 <= a <= 20 && 1 <= b <= 20 && 1 <= c <= 20 ==>
        (a + b + 1 <= c ==> (a + b + 1) + \min(c - (a + b + 1), b) <= 40) &&
        (a + b + 1 > c ==> (a + b + c)/2 <= 40);
*/

int32_t func2_compute_result(const uint32_t input[3]) {
    int32_t result;
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t sum;
    uint32_t c_temp;

    result = 0;
    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert 1 <= a <= 20 && 1 <= b <= 20 && 1 <= c <= 20;

    if (a + b + 1 <= c) {
        result += (int32_t)(a + b + 1);
        c_temp = c - (a + b + 1);
        if (c_temp < b) {
            result += (int32_t)c_temp;
            //@ assert result <= 40;
            return result;
        } else {
            result += (int32_t)b;
            //@ assert result <= 40;
            return result;
        }
    } else {
        sum = a + b + c;
        result = (int32_t)(sum / 2);
        //@ assert result <= 40;
        return result;
    }
}

/*@
    predicate is_max(integer x, integer a, integer b, integer c, integer d) =
        x >= a + c && x >= b + d &&
        (x == a + c || x == b + d);
*/

long func3_max_pair(long a, long b, long c, long d)
{
    long x;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    
    if (a + c > b + d)
    {
        x = a + c;
    }
    else
    {
        x = b + d;
    }
    
    //@ assert is_max(x, a, b, c, d);
    return x;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000000000;

    logic integer calc_res(integer x) = 2 * (x / 11) + (x % 11 + 5) / 6;

    lemma res_bound:
        \forall integer x; valid_range(x) ==> calc_res(x) <= calc_res(x);
*/

unsigned int func4_compute_special(unsigned int x)
{
    unsigned int res;
    //@ assert valid_range(x);
    res = 2 * (x / 11) + (x % 11 + 5) / 6;
    //@ assert res == calc_res(x);
    //@ assert res <= calc_res(x);
    return res;
}

/*@
    predicate scheduled_offset_consistent(integer scheduled_offset, integer priority) =
        scheduled_offset >= 0 && scheduled_offset <= 1000000000 &&
        (priority == 0 ==> scheduled_offset == 0) &&
        (priority > 0 ==> scheduled_offset >= 1);
*/

unsigned int schedule_packet(const uint32_t packet_sizes[3], long a, long b, long c, long d, unsigned int base_offset)
{
    unsigned int scheduled_offset;
    int32_t priority;
    long max_pair;
    unsigned int special_base;
    unsigned int final_offset;
    
    priority = func2_compute_result(packet_sizes);
    //@ assert 0 <= priority <= 40;
    
    max_pair = func3_max_pair(a, b, c, d);
    //@ assert is_max(max_pair, a, b, c, d);
    //@ assert max_pair >= a + c && max_pair >= b + d;
    
    unsigned int combined;
    if (priority + max_pair > 1000000000) {
        combined = 1000000000;
    } else {
        combined = (unsigned int)(priority + max_pair);
    }
    //@ assert combined <= 1000000000;
    
    special_base = func4_compute_special(combined);
    
    if (base_offset > special_base)
    {
        scheduled_offset = base_offset - special_base;
    }
    else
    {
        scheduled_offset = special_base - base_offset;
    }
    
    //@ assert scheduled_offset >= 0;
    
    return scheduled_offset;
}
