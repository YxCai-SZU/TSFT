#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/*@
    predicate x_in_bounds(integer x) = 1 <= x && x <= 1000000;
    
    logic integer division_by_11(integer x) = x / 11;
    
    lemma q_bounds:
        \forall integer x, q;
        x_in_bounds(x) && 0 <= q && q <= division_by_11(x) ==>
        0 <= 2 * q <= 2 * division_by_11(x);
*/

uint32_t func1(uint32_t x)
{
    uint32_t q = 0;
    uint32_t temp_x = x;
    
    while (temp_x >= 11)
    {
        temp_x -= 11;
        q += 1;
    }
    
    //@ assert 0 <= 2 * q <= 2 * (x / 11);
    
    uint32_t ans = q * 2;
    if (temp_x >= 7) ans += 1;
    if (temp_x >= 6) ans += 1;
    
    return ans;
}

/*@
    predicate condition1(integer a, integer b, integer c) =
        a == b + 1 && b == c + 1;
    
    predicate condition2(integer a, integer b, integer c) =
        b == a + 1 && a == c + 1;
    
    predicate condition3(integer a, integer b, integer c) =
        c == a + 1 && a == b + 1;
    
    lemma final_result:
        \forall integer a, b, c;
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 ==>
        (condition1(a, b, c) || condition2(a, b, c) || condition3(a, b, c)) ==>
        ((a == b + 1 && b == c + 1) || (b == a + 1 && a == c + 1) || (c == a + 1 && a == b + 1));
*/

bool func2(int a, int b, int c) {
    bool result = false;
    bool condition1;
    bool condition2;
    bool condition3;
    bool temp_result = false;
    
    condition1 = (a == b + 1 && b == c + 1);
    condition2 = (b == a + 1 && a == c + 1);
    condition3 = (c == a + 1 && a == b + 1);
    
    if (condition1) {
        temp_result = true;
    } else if (condition2) {
        temp_result = true;
    } else if (condition3) {
        temp_result = true;
    }
    
    result = temp_result;
    
    //@ assert result == ((a == b + 1 && b == c + 1) || (b == a + 1 && a == c + 1) || (c == a + 1 && a == b + 1));
    
    return result;
}

/*@
    predicate is_valid_n(integer n) = 1 <= n <= 100000;

    logic integer mod_100(integer n) = n % 100;
    logic integer div_100(integer n) = n / 100;
    logic integer six_times(integer d) = 6 * d;
    logic integer thirteen_times(integer d) = 13 * d;

    lemma bounds_lemma:
        \forall integer n;
            is_valid_n(n) ==>
            div_100(n) <= 1000 &&
            six_times(div_100(n)) <= 6000 &&
            thirteen_times(div_100(n)) <= 13000;
*/

int func3(int n)
{
    int res;
    int mod_result;
    int div_result;
    int six_mul;
    int thirteen_mul;

    //@ assert is_valid_n(n);
    
    mod_result = n % 100;
    div_result = n / 100;
    six_mul = 6 * div_result;
    thirteen_mul = 13 * div_result;

    //@ assert div_result <= 1000;
    //@ assert six_mul <= 6000;
    //@ assert thirteen_mul <= 13000;

    if (mod_result < six_mul) {
        res = 0;
    } else if (mod_result < thirteen_mul) {
        res = 1;
    } else {
        res = -1;
    }

    return res;
}

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= c <= 100 &&
        1 <= k <= a + b + c &&
        a + b + c >= 1;

    logic integer min(integer x, integer y) = (x < y) ? x : y;
*/

int32_t func4(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t ans = 0;
    uint32_t remaining_k = k;
    uint32_t a_cards_to_use;
    uint32_t b_cards_to_use;
    uint32_t c_cards_to_use;

    //@ assert valid_params(a, b, c, k);

    if (a < remaining_k) {
        a_cards_to_use = a;
    } else {
        a_cards_to_use = remaining_k;
    }
    ans += (int32_t)a_cards_to_use;
    remaining_k -= a_cards_to_use;

    //@ assert ans >= -1 * (int32_t)c && ans <= (int32_t)a;

    if (remaining_k < b) {
        b_cards_to_use = remaining_k;
    } else {
        b_cards_to_use = b;
    }
    remaining_k -= b_cards_to_use;

    //@ assert ans >= -1 * (int32_t)c && ans <= (int32_t)a;

    if (remaining_k < c) {
        c_cards_to_use = remaining_k;
    } else {
        c_cards_to_use = c;
    }
    ans -= (int32_t)c_cards_to_use;

    //@ assert ans >= -1 * (int32_t)c;
    //@ assert ans <= (int32_t)a;

    return ans;
}

int32_t process_network_packet(
    uint32_t packet_size,
    int flag_a, int flag_b, int flag_c,
    int priority_code,
    uint32_t resource_a, uint32_t resource_b, uint32_t resource_c,
    uint32_t budget
)
{
    int32_t final_result = 0;
    
    uint32_t quality_score = func1(packet_size);
    
    bool flags_valid = func2(flag_a, flag_b, flag_c);
    
    int priority_class = func3(priority_code);
    
    int32_t handling_cost = func4(resource_a, resource_b, resource_c, budget);
    
    if (priority_class == 0) {
        final_result = handling_cost;
    } else if (priority_class == 1) {
        if (flags_valid) {
            final_result = handling_cost + (int32_t)quality_score;
        } else {
            final_result = handling_cost;
        }
    } else {
        int32_t capped_score = (int32_t)quality_score;
        if (capped_score > (int32_t)packet_size) {
            capped_score = (int32_t)packet_size;
        }
        final_result = handling_cost + capped_score;
    }
    
    //@ assert final_result >= -1 * (int)resource_c - 1 && final_result <= (int)resource_a + (int)packet_size;
    
    return final_result;
}
