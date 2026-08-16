/*@
    requires \valid_read(nums + (0..len-1));
    requires ((len) > 0);
    assigns \nothing;
    ensures ((len) > 0 ==> (\result) <= (nums)[0]);
*/
int search(int *nums, int len) {
    int min_num;
    unsigned int index;

    min_num = 2147483647;
    index = 0;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant min_num <= 2147483647;
        loop invariant (\forall integer k; 0 <= k < (index) ==> (min_num) <= (nums)[k]);
        loop assigns min_num, index;
        loop variant len - index;
    */
    while (index < len) {
        int num = nums[index];
        if (num < min_num) {
            min_num = num;
        }
        index++;
    }

    //@ assert (\forall integer k; 0 <= k < (len) ==> (min_num) <= (nums)[k]);
    return min_num;
}
