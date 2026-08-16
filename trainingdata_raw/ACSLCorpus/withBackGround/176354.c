#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_bounds(integer x) = 0 <= x <= 50;
    
    logic integer min(integer x, integer y) = (x < y) ? x : y;
    
    lemma ans_bounds:
        \forall integer a, b, c, ans;
        within_bounds(a) && within_bounds(b) && within_bounds(c) &&
        ans == min(b, c) + min(a - min(b, c), c - min(b, c)) ==>
        non_negative(ans) && ans <= a + b + c;
*/

/*@
    requires within_bounds(a) && within_bounds(b) && within_bounds(c);
    ensures non_negative(\result);
    ensures \result <= a + b + c;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans = 0;
    int64_t a_temp = a;
    int64_t b_temp = b;
    int64_t c_temp = c;
    int64_t min_val;
    
    //@ assert within_bounds(a_temp) && within_bounds(b_temp) && within_bounds(c_temp);
    
    if (b_temp < c_temp) {
        min_val = b_temp;
    } else {
        min_val = c_temp;
    }
    //@ assert min_val == min(b, c);
    
    ans += min_val;
    a_temp -= min_val;
    b_temp = 0;
    c_temp -= min_val;
    
    //@ assert ans == min(b, c);
    //@ assert a_temp == a - min(b, c);
    //@ assert c_temp == c - min(b, c);
    
    if (a_temp < c_temp) {
        ans += a_temp;
    } else {
        ans += c_temp;
    }
    //@ assert ans == min(b, c) + min(a - min(b, c), c - min(b, c));
    
    //@ assert non_negative(ans);
    //@ assert ans <= a + b + c;
    
    return ans;
}
