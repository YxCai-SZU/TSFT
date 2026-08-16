/*@
    predicate valid_array(int *arr, integer n) =
        n > 0 && n <= 20 &&
        \valid(arr + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 100;

    predicate loop_invariant(int *h, integer n, integer index, integer ans, integer max_val) =
        0 <= index <= n-1 &&
        1 <= ans <= index+1 &&
        valid_array(h, n) &&
        \forall integer k; 0 <= k < n ==> 1 <= h[k] <= 100;

    lemma ans_bounds: \forall integer n, ans; 1 <= ans <= n ==> ans >= 1 && ans <= n;
*/

/*@
    requires valid_array(h, n);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *h) {
    int max_val = 0;
    int ans = 1;
    int index = 0;

    //@ ghost int old_max;
    //@ ghost int old_ans;
    //@ ghost int old_index;

    /*@
        loop invariant loop_invariant(h, n, index, ans, max_val);
        loop invariant index < n-1 ==> max_val >= 0;
        loop assigns max_val, ans, index, old_max, old_ans, old_index;
        loop variant n - index;
    */
    while (index < n - 1) {
        //@ ghost old_max = max_val;
        //@ ghost old_ans = ans;
        //@ ghost old_index = index;

        //@ assert 0 <= index < n-1;
        int diff = h[index + 1] - h[index];
        
        if (max_val <= diff) {
            max_val = diff;
            ans += 1;
        }
        index += 1;

        //@ assert index == old_index + 1;
        //@ assert ans >= old_ans;
        //@ assert ans <= index + 1;
    }

    //@ assert ans >= 1 && ans <= n;
    return ans;
}
