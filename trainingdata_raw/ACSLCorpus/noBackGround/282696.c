#include <stddef.h>
#include <stdint.h>

/*@
    requires ((len) > 0 && (len) < 0x80000000 &&
        \valid((nums) + (0 .. (len)-1)));
    ensures \exists integer i; 0 <= i < len && \result == nums[i];
    assigns \nothing;
*/
int32_t find_min(int32_t* nums, size_t len)
{
    int32_t min_val;
    size_t i;
    
    //@ assert len > 0 && len < 0x80000000;
    min_val = nums[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\exists integer j; 0 <= j < (i) && (nums)[j] == (min_val));
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min_val) <= (nums)[k]);
        loop invariant ((len) > 0 && (len) < 0x80000000 &&
        \valid((nums) + (0 .. (len)-1)));
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert i < len;
        if (nums[i] < min_val)
        {
            min_val = nums[i];
        }
        i = i + 1;
    }
    
    //@ assert (\exists integer j; 0 <= j < (len) && (nums)[j] == (min_val));
    return min_val;
}
