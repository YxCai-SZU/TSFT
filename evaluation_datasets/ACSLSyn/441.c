#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

/* ===== Original functions (adapted with ACSL specs) ===== */

/* Function 1: is_within_bound_i32 */
/*@
    predicate is_within_bound_i32(integer x) =
        x >= INT_MIN && x <= INT_MAX;

    predicate is_within_bound_u32(integer x) =
        x >= 0 && x <= UINT_MAX;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer x, y;
            1 <= x && x <= 100 && 1 <= y && y <= 100 ==> product(x, y) <= 10000;
*/

bool is_within_bound(int x)
{
    //@ assert is_within_bound_i32(x);
    return true;
}

bool is_within_bound_u32(unsigned int x)
{
    //@ assert is_within_bound_u32(x);
    return true;
}

bool example(int x, int y)
{
    //@ assert product(x, y) <= 10000;
    return true;
}

/* Function 2: func (diff_val) */
/*@
    predicate diff_val(integer X, integer d) = d == X * 2 - 1;
*/

bool func(int X, int Y)
{
    int diff;
    bool result;

    if (X == 1 && Y == 1)
    {
        result = true;
    }
    else
    {
        diff = X * 2 - 1;
        //@ assert diff_val(X, diff);
        result = (Y >= diff);
    }

    return result;
}

/* Function 3: func2 (valid_range) */
/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a <= 500 &&
        1 <= b <= 500 &&
        1 <= c <= 1000;

    logic integer compute_x(integer b, integer c) = c - b;
*/

bool func2(int a, int b, int c)
{
    int min;
    int x;

    min = 0;
    x = 0;

    //@ assert valid_range(a, b, c);

    min = (a < b) ? a : b;
    x = c - b;

    //@ assert x == compute_x(b, c);
    
    //@ assert compute_x(b, c) >= 0 && compute_x(b, c) < a ==> (x >= 0 && x < a);
    return (x >= 0 && x < a);
}

/* Function 4: func3 (max_of_three) */
/*@
    predicate valid_range2(integer x) = 0 <= x <= 50;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a : ((b >= a && b >= c) ? b : c);

    lemma max_properties:
        \forall integer a, b, c;
        valid_range2(a) && valid_range2(b) && valid_range2(c) ==>
        max_of_three(a, b, c) >= 0 &&
        max_of_three(a, b, c) <= a + b + c;
*/

int64_t func3(int64_t a, int64_t b, int64_t c)
{
    int64_t result = 0;
    int64_t max1;
    int64_t max2;
    int64_t a_new;
    int64_t b_new;
    int64_t c_new;

    //@ assert valid_range2(a) && valid_range2(b) && valid_range2(c);

    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }

    if (max1 > c) {
        max2 = max1;
    } else {
        max2 = c;
    }

    //@ assert max2 == max_of_three(a, b, c);
    //@ assert max2 >= 0 && max2 <= a + b + c;

    result += max2;

    a_new = a;
    b_new = b;
    c_new = c;

    if (max2 == a_new) {
        a_new -= max2;
    } else if (max2 == b_new) {
        b_new -= max2;
    } else {
        c_new -= max2;
    }

    //@ assert a_new >= 0 && a_new <= a;
    //@ assert b_new >= 0 && b_new <= b;
    //@ assert c_new >= 0 && c_new <= c;

    if (a_new > 0) {
        result += a_new;
    }

    if (b_new > 0) {
        result += b_new;
    }

    if (c_new > 0) {
        result += c_new;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}

/* ===== Synthesized function: process_packet ===== */

int64_t process_packet(int packet_size, int payload_a, int payload_b,
                       int header_a, int header_b, int header_c,
                       int64_t config_a, int64_t config_b, int64_t config_c)
{
    bool valid_size = is_within_bound(packet_size);
    //@ assert valid_size == true;

    bool payload_ok = example(payload_a, payload_b);
    //@ assert payload_ok == (payload_a * payload_b <= 10000);

    bool relation_ok = func(payload_a, payload_b);
    //@ assert relation_ok == (payload_b >= (payload_a * 2 - 1) || (payload_a == 1 && payload_b == 1));

    bool header_ok = func2(header_a, header_b, header_c);
    //@ assert header_ok == ((header_c - header_b) >= 0 && (header_c - header_b) < header_a);

    int64_t config_sum = func3(config_a, config_b, config_c);
    //@ assert config_sum >= 0 && config_sum <= config_a + config_b + config_c;

    int64_t result = 0;
    if (valid_size && payload_ok && relation_ok && header_ok) {
        result = config_sum;
    } else {
        result = 0;
    }

    //@ assert (result == 0 || (result >= 0 && result <= config_a + config_b + config_c));

    return result;
}
