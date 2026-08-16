/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer remainder(integer n) = n % 1000;
    
    lemma remainder_bounds: \forall integer n; is_valid_n(n) ==> 0 <= remainder(n) && remainder(n) <= 999;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 1000 - (n % 1000) || \result == 0;
    assigns \nothing;
*/
int func(int n)
{
    int res;
    int temp_n;
    
    res = 1000;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= temp_n <= n;
        loop invariant res == 1000;
        loop invariant n == temp_n + 1000 * ((n - temp_n) / 1000);
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        //@ assert temp_n >= 1000;
        temp_n -= 1000;
    }
    
    if (temp_n != 0)
    {
        //@ assert temp_n >= 1 && temp_n <= 999;
        res -= temp_n;
    }
    else
    {
        res = 0;
    }
    
    //@ assert res == 1000 - (n % 1000) || res == 0;
    return res;
}
