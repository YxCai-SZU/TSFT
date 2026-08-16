/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;
    predicate result_range(integer r) = 0 <= r <= 500;
    predicate loop_invariant(integer n, integer count, integer result) =
        1 <= n <= 100 && 0 <= count <= n && 0 <= result <= 500 && result == count;
    lemma loop_decreases: \forall integer n, count; 0 <= count <= n ==> n - count >= 0;
*/

/*@
    requires is_valid_range(n);
    ensures result_range(\result);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int count;
    int local_n;

    //@ assert is_valid_range(n);
    
    if (n % 2 == 0) {
        //@ assert result_range(0);
        return 0;
    } else {
        local_n = n / 2 + 1;
        //@ assert 1 <= local_n <= 100;
        result = 0;
        count = 0;
        
        /*@
            loop invariant loop_invariant(local_n, count, result);
            loop assigns result, count;
            loop variant local_n - count;
        */
        while (count < local_n) {
            //@ assert loop_invariant(local_n, count, result);
            result += 1;
            count += 1;
            //@ assert loop_invariant(local_n, count, result);
        }
        //@ assert result_range(result);
        return result;
    }
}
