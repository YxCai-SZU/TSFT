#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    predicate scale_const(integer s) = s == 10000;
    predicate pi_const(integer p) = p == 31415;
    
    logic integer scaled_r(integer r, integer s) = r * s;
    logic integer circumference(integer p, integer r) = 2 * p * r;
    
    lemma scaled_r_bounds:
        \forall integer r, s; valid_range(r) && scale_const(s) ==> 
            scaled_r(1, s) <= scaled_r(r, s) <= scaled_r(100, s);
    
    lemma circumference_bounds:
        \forall integer r, p; valid_range(r) && pi_const(p) ==> 
            circumference(p, 1) <= circumference(p, r) <= circumference(p, 100);
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * 31415 * r / 10000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t scale;
    int64_t scaled_r;
    int64_t circumference;
    int64_t ans;
    int64_t temp;
    
    pi = 31415;
    scale = 10000;
    
    //@ assert scale_const(scale);
    //@ assert pi_const(pi);
    
    scaled_r = r * scale;
    //@ assert valid_range(r);
    
    circumference = 2 * pi * r;
    //@ assert circumference == circumference(pi, r);
    
    ans = 0;
    temp = circumference;
    
    /*@
        loop invariant valid_range(r);
        loop invariant pi_const(pi);
        loop invariant scale_const(scale);
        loop invariant 0 <= ans;
        loop invariant 0 <= temp;
        loop invariant circumference == 2 * pi * r;
        loop invariant temp + ans * scale == circumference;
        loop assigns temp, ans;
    */
    while (temp >= scale)
    {
        temp -= scale;
        ans += 1;
    }
    
    //@ assert ans * scale + temp == 2 * pi * r;
    return ans;
}
