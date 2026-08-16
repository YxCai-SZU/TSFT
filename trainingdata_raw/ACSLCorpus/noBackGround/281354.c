/*@
    requires \valid_read(nums + (0..len-1));
    requires len > 0;
    ensures (\forall integer j; 0 <= j < (len) ==> (\result) >= (nums)[j]);
    ensures (\exists integer j; 0 <= j < (len) && (\result) == (nums)[j]);
    assigns \nothing;
*/
int find_max_num(int* nums, int len) {
    int max_num;
    int i;
    
    max_num = nums[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (max_num) >= (nums)[j]);
        loop invariant (\exists integer j; 0 <= j < (i) && (max_num) == (nums)[j]);
        loop assigns max_num, i;
        loop variant len - i;
    */
    while (i < len) {
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
        //@ assert (\forall integer j; 0 <= j < (i+1) ==> (max_num) >= (nums)[j]);
        i++;
    }
    return max_num;
}
