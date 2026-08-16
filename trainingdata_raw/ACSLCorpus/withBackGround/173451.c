/*@
    predicate is_valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer multiply_500(integer i) = 500 * i;

    lemma loop_invariant_maintained:
        \forall integer k, i, sum;
            0 <= i <= k && sum == multiply_500(i) ==>
            sum + 500 == multiply_500(i + 1);
*/

/*@
    requires is_valid_params(k, x);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
int func(int k, int x) {
    int sum;
    int i;

    //@ ghost int original_k = k;
    //@ ghost int original_x = x;

    sum = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= original_k;
        loop invariant sum == multiply_500(i);
        loop invariant is_valid_params(original_k, original_x);
        loop assigns sum, i;
        loop variant original_k - i;
    */
    while (i < k) {
        //@ assert sum == 500 * i;
        sum += 500;
        i += 1;
        //@ assert sum == 500 * i;
    }

    //@ assert sum == 500 * original_k;
    return sum >= x;
}
