#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) <= 0x80000000 &&
        \valid((nums) + (0 .. (n)-1)));
    ensures ((\result) <= (n));
    ensures (\forall integer i; 0 <= i < (n) ==> ((((nums))[(i)] == 2) ==> (\result) > 0));
*/
size_t count_2s_in_vec(int *nums, size_t n)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant i <= n;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (((nums)[(j)] == 2) ==> count > 0);
        loop invariant n <= 0x80000000;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert i < n;
        if (nums[i] == 2)
        {
            //@ assert ((nums)[(i)] == 2);
            count++;
        }
        i++;
    }

    //@ assert ((count) <= (n));
    //@ assert (\forall integer i; 0 <= i < (n) ==> ((((nums))[(i)] == 2) ==> (count) > 0));
    return count;
}
