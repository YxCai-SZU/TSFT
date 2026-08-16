/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 &&
        1 <= k <= 100 &&
        k <= n;

    logic integer remainder(integer n, integer k, integer temp) =
        temp;

    lemma remainder_bounds:
        \forall integer n, integer k, integer temp;
        valid_params(n, k) && 0 <= temp <= n - k + 1 ==>
        0 <= remainder(n, k, temp);
*/

/*@
    requires valid_params(n, k);
    ensures 0 <= \result <= 1;
    assigns \nothing;
*/
int func(int n, int k) {
    int result;
    int temp;
    int divisor;
    
    result = 0;
    temp = n - k + 1;
    divisor = k;
    
    /*@
        loop invariant 0 <= temp <= n - k + 1;
        loop invariant divisor == k;
        loop invariant result == 0;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= k;
        temp -= divisor;
    }
    
    //@ assert 0 <= temp < k;
    
    if (temp == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert 0 <= result <= 1;
    return result;
}
