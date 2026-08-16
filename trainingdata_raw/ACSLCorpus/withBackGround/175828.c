#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate a_abs_nonneg(integer a_abs) = a_abs >= 0;
    predicate b_abs_positive(integer b_abs) = b_abs > 0;
    predicate a_abs_bounded(integer a_abs) = a_abs <= 100;
    predicate b_abs_bounded(integer b_abs) = b_abs <= 100;
    predicate cnt_nonneg(integer cnt) = cnt >= 0;
    predicate a_abs_le_a(integer a_abs, integer a) = a_abs <= a;
    predicate cnt_bound(integer cnt, integer a, integer a_abs) = cnt <= (a - a_abs);
*/

/*@
    lemma cnt_always_nonneg: \forall integer cnt, a, a_abs; cnt >= 0 ==> cnt >= 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result <= a;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    int64_t cnt;
    int64_t a_abs;
    int64_t b_abs;
    
    ans = 0;
    cnt = 0;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    if (a < 0) {
        a_abs = -a;
    } else {
        a_abs = a;
    }
    
    if (b < 0) {
        b_abs = -b;
    } else {
        b_abs = b;
    }
    
    //@ assert a_abs_nonneg(a_abs);
    //@ assert b_abs_positive(b_abs);
    //@ assert a_abs_bounded(a_abs);
    //@ assert b_abs_bounded(b_abs);
    //@ assert a_abs_le_a(a_abs, a);
    
    /*@
        loop invariant a_in_range(a);
        loop invariant b_in_range(b);
        loop invariant a_abs_nonneg(a_abs);
        loop invariant b_abs_positive(b_abs);
        loop invariant a_abs_bounded(a_abs);
        loop invariant b_abs_bounded(b_abs);
        loop invariant cnt_nonneg(cnt);
        loop invariant a_abs_le_a(a_abs, a);
        loop invariant cnt_bound(cnt, a, a_abs);
        loop assigns a_abs, cnt;
        loop variant a_abs;
    */
    while (a_abs >= b_abs) {
        a_abs -= b_abs;
        cnt += 1;
        
        //@ assert cnt_nonneg(cnt);
        //@ assert a_abs_le_a(a_abs, a);
        //@ assert cnt_bound(cnt, a, a_abs);
    }
    
    ans = cnt;
    
    //@ assert ans >= 0;
    //@ assert ans <= a;
    
    return ans;
}
