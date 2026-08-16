#include <stdbool.h>

/*@
    predicate is_valid_byte(integer x) = 0 <= x < 16;
    predicate is_valid_params(integer k, integer n) = 1 <= k <= 100 && 1 <= n <= 100;
    
    logic integer mask_high_nibble(integer x) = x & 0xf0;
    logic integer compute_q(integer n) = n / 2 + n % 2;
    
    predicate is_valid_packet(unsigned char high, unsigned char low, int id, int seq) =
        is_valid_byte(high) && is_valid_byte(low) && is_valid_params(id, seq);
    
    lemma mask_preservation:
        \forall integer x;
            is_valid_byte(x) ==> mask_high_nibble(x) == mask_high_nibble(mask_high_nibble(x));
    
    lemma q_bound_lemma:
        \forall integer n; 1 <= n <= 100 ==> compute_q(n) <= 51;
    
    lemma q_calculation_lemma:
        \forall integer n; 1 <= n <= 100 ==>
            compute_q(n) == n / 2 + n % 2;
    
    lemma nibble_match_implies_threshold:
        \forall unsigned char a, b, int k, int n;
            is_valid_byte(a) && is_valid_byte(b) && is_valid_params(k, n) ==>
                ((mask_high_nibble(a) == mask_high_nibble(b)) ==> (k >= compute_q(n) || k < compute_q(n)));
*/

bool func_nibble_match(unsigned char a, unsigned char b)
{
    bool result;

    //@ assert mask_high_nibble(a) == mask_high_nibble(mask_high_nibble(a));
    //@ assert mask_high_nibble(b) == mask_high_nibble(mask_high_nibble(b));

    result = (a & 0xf0) == (b & 0xf0);
    return result;
}

bool func_threshold_check(int k, int n)
{
    int q;
    
    //@ assert n / 2 <= 50;
    //@ assert n % 2 <= 1;
    //@ assert n / 2 + n % 2 <= 51;
    
    q = n / 2 + n % 2;
    
    //@ assert n / 2 + n % 2 == q;
    
    return k >= q;
}

bool process_packet(unsigned char high, unsigned char low, int id, int seq)
{
    bool nibble_match;
    bool threshold_ok;
    bool result;
    
    nibble_match = func_nibble_match(high, low);
    
    threshold_ok = func_threshold_check(id, seq);
    
    result = nibble_match && threshold_ok;
    
    //@ assert (mask_high_nibble(high) == mask_high_nibble(low)) ==> (id >= compute_q(seq) || id < compute_q(seq));
    //@ assert result == (mask_high_nibble(high) == mask_high_nibble(low) && id >= compute_q(seq));
    
    return result;
}
