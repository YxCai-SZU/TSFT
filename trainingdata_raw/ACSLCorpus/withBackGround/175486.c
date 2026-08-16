/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;
    
    logic integer target_result(integer n) = (n - 1) / 2;
    
    lemma result_range: \forall integer n; is_valid_n(n) ==> 0 <= target_result(n);
*/

/*@
    requires is_valid_n(n);
    ensures \result == target_result(n);
    assigns \nothing;
*/
long func(long n)
{
    long count = 0;
    long temp = n - 1;
    
    /*@
        loop invariant 0 <= count <= target_result(n);
        loop invariant temp == n - 1 - 2 * count;
        loop invariant temp >= 0;
        loop assigns count, temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        count += 1;
        temp -= 2;
    }
    
    //@ assert temp < 2;
    //@ assert count == target_result(n);
    return count;
}
