/*@
    predicate is_valid_range(integer n) =
        1 <= n && n <= 100;

    logic integer compute_result(integer n, integer count) =
        800 * n - 200 * count;

    lemma count_bound: \forall integer n, count;
        is_valid_range(n) && n == 15 * count + (n % 15) ==> count <= 6;
*/

/*@
    requires is_valid_range(n);
    ensures \result == compute_result(n, n / 15);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    int count;
    int temp_n;
    
    //@ assert is_valid_range(n);
    
    // Ensure no overflow in 800 * n
    //@ assert 800 * n <= 800 * 100;
    
    result = 800 * n;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n + 15 * count == n;
        loop invariant count <= 6;
        loop invariant count >= 0;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n + 15 * count == n;
    }
    
    //@ assert count == n / 15;
    result = result - 200 * count;
    
    //@ assert result == compute_result(n, count);
    return result;
}
