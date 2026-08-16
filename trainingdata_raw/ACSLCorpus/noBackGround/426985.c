/*@
    requires \valid(nums + (0..len-1));
    assigns \nothing;
    ensures \result <= len;
    ensures (\forall integer j; 0 <= j < (len) ==> ((nums)[j] == (target) ==> (\result) > 0));
 */
unsigned int count_occurrences(int *nums, unsigned int len, int target)
{
    unsigned int count = 0;
    unsigned int i = 0;

    /*@
        loop invariant i <= len;
        loop invariant count <= i;
        loop invariant (\forall integer j; 0 <= j < (i) ==> ((nums)[j] == (target) ==> (count) > 0));
        loop assigns i, count;
        loop variant len - i;
     */
    while (i < len)
    {
        //@ assert i < len;
        if (nums[i] == target)
        {
            count++;
        }
        i++;
    }
    return count;
}
