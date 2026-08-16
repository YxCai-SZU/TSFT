#include <stdint.h>

/*@ requires (1 <= (l) && (l) <= (r) && (r) <= 100 &&
     1 <= (d) && (d) <= 100);
    ensures 0 <= \result && \result <= r - l + 1;
    assigns \nothing;
*/
int64_t func(int64_t l, int64_t r, int64_t d)
{
    int64_t ans = 0;
    int64_t i = l;
    //@ ghost int64_t original_l = l;
    //@ ghost int64_t original_r = r;
    //@ ghost int64_t original_d = d;
    
    /*@ loop invariant ((1 <= ((original_l)) && ((original_l)) <= ((original_r)) && ((original_r)) <= 100 &&
     1 <= ((original_d)) && ((original_d)) <= 100) &&
     (original_l) <= (i) && (i) <= (original_r) + 1 &&
     0 <= (ans) && (ans) <= (i) - (original_l));
        loop assigns ans, i;
        loop variant original_r - i + 1;
    */
    while (i <= r)
    {
        //@ assert ((1 <= ((original_l)) && ((original_l)) <= ((original_r)) && ((original_r)) <= 100 &&      1 <= ((original_d)) && ((original_d)) <= 100) &&      (original_l) <= (i) && (i) <= (original_r) + 1 &&      0 <= (ans) && (ans) <= (i) - (original_l));
        uint64_t ui = (uint64_t)i;
        uint64_t ud = (uint64_t)d;
        if (ui % ud == 0) 
        {
            ans += 1;
        }
        i += 1;
        //@ assert ((1 <= ((original_l)) && ((original_l)) <= ((original_r)) && ((original_r)) <= 100 &&      1 <= ((original_d)) && ((original_d)) <= 100) &&      (original_l) <= (i) && (i) <= (original_r) + 1 &&      0 <= (ans) && (ans) <= (i) - (original_l));
    }
    //@ assert ans_bounds: 0 <= ans && ans <= original_r - original_l + 1;
    return ans;
}
