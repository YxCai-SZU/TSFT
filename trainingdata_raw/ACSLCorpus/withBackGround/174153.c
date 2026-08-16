/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer manual_div_100(integer n, integer count) = n - 100 * count;
    logic integer manual_div_5(integer n, integer count) = n % 100 - 5 * count;
    
    lemma div_100_loop_invariant:
        \forall integer n, count;
        is_valid_n(n) && 0 <= count && count <= n / 100 ==>
        manual_div_100(n, count) == n - 100 * count;
    
    lemma div_5_loop_invariant:
        \forall integer n, count;
        is_valid_n(n) && 0 <= count && count <= (n % 100) / 5 ==>
        manual_div_5(n, count) == n % 100 - 5 * count;
*/

/*@
    requires is_valid_n(n);
    ensures \result == (n / 100) * 5 + (n % 100 / 5) * 1;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    int count = 0;
    
    //@ assert is_valid_n(n);
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= count <= n / 100;
        loop invariant temp_n == n - 100 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 100)
    {
        //@ assert temp_n >= 100;
        temp_n -= 100;
        count += 1;
        //@ assert temp_n == n - 100 * count;
    }
    result += count * 5;
    
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= count <= (n % 100) / 5;
        loop invariant temp_n == n % 100 - 5 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert temp_n >= 5;
        temp_n -= 5;
        count += 1;
        //@ assert temp_n == n % 100 - 5 * count;
    }
    result += count * 1;
    
    //@ assert result == (n / 100) * 5 + (n % 100 / 5) * 1;
    return result;
}
