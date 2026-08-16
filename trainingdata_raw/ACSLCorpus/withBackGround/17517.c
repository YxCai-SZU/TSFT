#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h < 24 && 0 <= m && m < 60;

    predicate valid_k(integer k) =
        0 <= k && k < 24 * 60;

    predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        h1 <= h2 && m1 <= m2;

    logic integer time_diff(integer h1, integer m1, integer h2, integer m2, integer k) =
        h2 * 60 + m2 - h1 * 60 - m1 - k;

    lemma h2_bound: \forall integer h2; 0 <= h2 && h2 < 24 ==> 0 <= h2 * 60 && h2 * 60 <= 24 * 60;
    lemma m2_bound: \forall integer m2; 0 <= m2 && m2 < 60 ==> 0 <= m2 && m2 <= 60;
    lemma h1_bound: \forall integer h1; 0 <= h1 && h1 < 24 ==> 0 <= h1 * 60 && h1 * 60 <= 24 * 60;
    lemma m1_bound: \forall integer m1; 0 <= m1 && m1 < 60 ==> 0 <= m1 && m1 <= 60;
    lemma k_bound: \forall integer k; 0 <= k && k < 24 * 60 ==> 0 <= k && k <= 24 * 60;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires valid_k(k);
    requires time_order(h1, m1, h2, m2);
    ensures \result == time_diff(h1, m1, h2, m2, k);
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    // Variable declarations at top of scope
    int x;

    //@ assert 0 <= h2 && h2 < 24;
    //@ assert 0 <= h2 * 60 && h2 * 60 <= 24 * 60;
    
    //@ assert 0 <= m2 && m2 < 60;
    //@ assert 0 <= m2 && m2 <= 60;
    
    //@ assert 0 <= h1 && h1 < 24;
    //@ assert 0 <= h1 * 60 && h1 * 60 <= 24 * 60;
    
    //@ assert 0 <= m1 && m1 < 60;
    //@ assert 0 <= m1 && m1 <= 60;
    
    //@ assert 0 <= k && k < 24 * 60;
    //@ assert 0 <= k && k <= 24 * 60;

    x = h2 * 60 + m2 - h1 * 60 - m1 - k;
    
    //@ assert x == time_diff(h1, m1, h2, m2, k);
    return x;
}
