/*@
    requires \valid(nums+(0..len-1));
    requires len >= 0;
    ensures \result >= 0;
    ensures \result <= len;
    assigns \nothing;
*/
int count_nonzeronum(int *nums, int len) {
    int count;
    int i;

    count = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer k; 0 <= k < (i) ==> ((nums)[k] != 0 ==> (count) > 0));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (nums[i] != 0) {
            count = count + 1;
        }
        i = i + 1;
    }

    //@ assert (0 <= (count) <= (i) && (i) <= (len));
    return count;
}
