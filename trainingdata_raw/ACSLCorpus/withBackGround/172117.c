/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer compute_sum(integer a, integer b) = a * b + 1;
    
    lemma sum_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> compute_sum(a, b) <= 10001;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (a * b + 1) / 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    unsigned int sum;
    unsigned int result = 0;
    unsigned int count;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    sum = a * b + 1;
    count = sum;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant result == (sum - count) / 2;
        loop invariant sum == a * b + 1;
        loop invariant count + 2 * result == sum;
        loop invariant count <= sum;
        loop assigns result, count;
        loop variant count;
    */
    while (count >= 2) {
        //@ assert count >= 2;
        result += 1;
        count -= 2;
        //@ assert count + 2 * result == sum;
    }
    
    //@ assert result == (a * b + 1) / 2;
    return result;
}
