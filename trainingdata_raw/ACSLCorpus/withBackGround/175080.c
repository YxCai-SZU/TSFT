#include <stdint.h>

/*@
    predicate non_negative(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 1;
    
    predicate k_bounds(integer a, integer b, integer c, integer k) =
        k <= a + b + c && k <= 2000000000;
    
    logic integer compute_acnt(integer a, integer k) =
        a < k ? a : k;
    
    logic integer compute_bcnt(integer b, integer k_cnt) =
        b < k_cnt ? b : k_cnt;
    
    logic integer compute_ccnt(integer c, integer k_cnt) =
        c < k_cnt ? c : k_cnt;
    
    lemma acnt_non_negative:
        \forall integer a, k; a >= 0 && k >= 1 ==> compute_acnt(a, k) >= 0;
    
    lemma ccnt_non_negative:
        \forall integer c, k_cnt; c >= 0 && k_cnt >= 0 ==> compute_ccnt(c, k_cnt) >= 0;
    
    lemma acnt_le_k:
        \forall integer a, k; compute_acnt(a, k) <= k;
    
    lemma ccnt_le_k:
        \forall integer c, k_cnt; compute_ccnt(c, k_cnt) <= k_cnt;
*/

/*@
    requires non_negative(a, b, c, k);
    requires k_bounds(a, b, c, k);
    ensures \result <= k;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_cnt;
    int32_t k_cnt;
    int32_t b_cnt;
    int32_t c_cnt;
    int32_t result;
    
    //@ assert a >= 0 && b >= 0 && c >= 0 && k >= 1;
    
    a_cnt = a < k ? a : k;
    //@ assert a_cnt == compute_acnt(a, k);
    
    k_cnt = k - a_cnt;
    //@ assert k_cnt >= 0;
    
    b_cnt = b < k_cnt ? b : k_cnt;
    //@ assert b_cnt == compute_bcnt(b, k_cnt);
    
    k_cnt = k_cnt - b_cnt;
    //@ assert k_cnt >= 0;
    
    c_cnt = c < k_cnt ? c : k_cnt;
    //@ assert c_cnt == compute_ccnt(c, k_cnt);
    
    //@ assert a_cnt >= 0 && c_cnt >= 0;
    
    result = a_cnt - c_cnt;
    //@ assert result <= k;
    
    return result;
}
