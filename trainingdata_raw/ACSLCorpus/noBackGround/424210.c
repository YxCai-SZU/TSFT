/*@
    requires \valid(nums + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result >= nums[i];
*/
int find_max_num(int *nums, int len) {
    int max_num;
    int i;
    
    max_num = nums[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && max_num >= nums[k];
        loop assigns max_num, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert \exists integer k; 0 <= k < i && max_num >= nums[k];
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
        //@ assert \exists integer k; 0 <= k < i+1 && max_num >= nums[k];
        i++;
    }
    return max_num;
}
