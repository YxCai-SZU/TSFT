/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer half_plus_one(integer n) = (n + 1) / 2;
    
    lemma half_plus_one_positive: \forall integer n; is_valid_n(n) ==> half_plus_one(n) >= 0;
*/

/*@
    requires is_valid_n(n);
    ensures \result == half_plus_one(n);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int result;
    unsigned int temp_n;
    
    //@ assert n + 1 >= 2;
    
    result = 0;
    temp_n = n + 1;
    
    /*@
        loop invariant 0 <= temp_n <= n + 1;
        loop invariant result == (n + 1 - temp_n) / 2;
        loop invariant temp_n + 2 * result == n + 1;
        loop assigns temp_n, result;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        result += 1;
        //@ assert temp_n + 2 * result == n + 1;
    }
    
    //@ assert result == half_plus_one(n);
    return result;
}
