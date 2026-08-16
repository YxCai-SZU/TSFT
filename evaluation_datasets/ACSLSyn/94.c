#include <stddef.h>
#include <stdbool.h>
#include <string.h>

/* ==================== Original Functions (adapted) ==================== */

/*@
    predicate valid_string(char *s, size_t len) =
        len >= 0 && \valid(s + (0 .. len-1));
    
    logic integer count_k_length_substrings_logic(integer s_len, integer k) =
        s_len < k ? 0 : s_len - k + 1;
*/

size_t count_k_length_substrings(const char *s, size_t s_len, size_t k) {
    size_t count;
    
    if (s_len < k) {
        count = 0;
    } else {
        //@ assert s_len >= k;
        //@ assert s_len - k + 1 <= s_len;
        count = s_len - k + 1;
    }
    
    return count;
}

/*@
    predicate is_valid_params(integer n, integer a) =
        1 <= n && n <= 10000 &&
        0 <= a && a <= 1000;

    logic integer remainder(integer n) =
        n - 500 * (n / 500);

    lemma remainder_bounds:
        \forall integer n; 1 <= n && n <= 10000 ==> 0 <= remainder(n) && remainder(n) < 500;
*/

bool check_allowance(unsigned int n, unsigned int a)
{
    unsigned int sub;
    
    //@ assert 1 <= n && n <= 10000;
    //@ assert 0 <= a && a <= 1000;
    
    sub = n - 500 * (n / 500);
    
    //@ assert sub == remainder(n);
    //@ assert 0 <= sub && sub < 500;
    
    return sub <= a;
}

/*@
    predicate in_range(integer x) = 0 <= x <= 20;

    lemma product_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> 0 <= a * b <= 400;
*/

bool check_product(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert in_range(a) && in_range(b) && in_range(c);
    //@ assert 0 <= a * b <= 400;

    result = (a * b <= c);
    return result;
}

/* ==================== Synthesized Function ==================== */


bool validate_packet(const char *s, size_t s_len, size_t k, 
                     unsigned int n, unsigned int a,
                     unsigned int a_val, unsigned int b_val, unsigned int c_val) 
{
    bool packet_valid;
    
    size_t sub_count = count_k_length_substrings(s, s_len, k);
    
    if (sub_count > 0) {
        bool allowance_ok = check_allowance(n, a);
        
        if (allowance_ok) {
            bool product_ok = check_product(a_val, b_val, c_val);
            packet_valid = product_ok;
        } else {
            packet_valid = false;
        }
    } else {
        packet_valid = false;
    }
    
    //@ assert packet_valid == (sub_count > 0 && remainder(n) <= a && a_val * b_val <= c_val);
    
    return packet_valid;
}

int main() {
    return 0;
}
