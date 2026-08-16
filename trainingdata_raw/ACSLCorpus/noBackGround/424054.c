#include <stddef.h>
#include <stdbool.h>

/*@
    requires len < 0x80000000;
    requires \valid(nums + (0 .. len-1));
    ensures \result <= len;
    ensures \forall size_t i; 0 <= i < len ==> (nums[i] == element ==> \result >= 1);
    ensures \forall size_t i; 0 <= i < len ==> (nums[i] != element ==> \result >= 0);
*/
size_t count_element_list(int *nums, size_t len, int element)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant ((i) <= (len) &&
    (count) <= (i) &&
    (\forall size_t k; 0 <= k < (i) ==> ((nums)[k] == (element) ==> (count) >= 1)) &&
    (\forall size_t k; 0 <= k < (i) ==> ((nums)[k] != (element) ==> (count) >= 0)));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        if (nums[i] == element)
        {
            count++;
        }
        i++;
        
        //@ assert count <= i;
    }
    
    return count;
}
