/*@
    predicate is_valid_k(integer k) = 1 <= k && k <= 99999;
    predicate loop_inv(integer k, integer a, integer i) =
        1 <= k && k <= 99999 &&
        0 <= a && a < k + 1 &&
        1 <= i && i <= k + 1;
    lemma termination: \forall integer k, i; loop_inv(k, 0, i) ==> k - i + 1 >= 0;
*/

/*@
    requires is_valid_k(k);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(unsigned int k) {
    unsigned int a;
    unsigned int i;
    int result;
    
    a = 0;
    i = 1;
    
    /*@
        loop invariant loop_inv(k, a, i);
        loop assigns a, i;
        loop variant k - i + 1;
    */
    while (i <= k) {
        a = (a * 10 + 7) % k;
        //@ assert a < k;
        if (a == 0) {
            result = 1;
            //@ assert result == 1;
            return result;
        }
        i = i + 1;
    }
    result = 0;
    //@ assert result == 0;
    return result;
}
