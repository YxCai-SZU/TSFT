/*@
    predicate count_in_range(integer count, integer n) =
        1 <= count && count * 3 <= n + 3;
    
    predicate result_in_range(integer result, integer n) =
        result >= 0 && result <= n;
    
    predicate loop_invariant(integer count, integer result, integer n) =
        count_in_range(count, n) && result_in_range(result, n) && 
        result <= count && 2 <= n && n <= 1000000 && count > 0;
    
    logic integer decreases(integer n, integer count) = n - count;
    
    lemma result_non_negative:
        \forall integer n, result; 2 <= n <= 1000000 && result_in_range(result, n) ==> result >= 0;
*/

/*@
    requires 2 <= n && n <= 1000000;
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n) {
    int result = 0;
    int count = 1;
    
    /*@
        loop invariant loop_invariant(count, result, n);
        loop assigns result, count;
        loop variant n - count;
    */
    while (count * 3 <= n) {
        //@ assert result >= 0 && result <= n;
        result += 1;
        count += 1;
    }
    
    int remaining = n - count * 3;
    if (remaining == 1 || remaining == 2) {
        result += 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n;
    
    return result;
}
