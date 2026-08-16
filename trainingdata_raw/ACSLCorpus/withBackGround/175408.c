/*@
    predicate is_valid_input(integer n) = 1 <= n && n <= 10000;
    
    logic integer compute_mod(integer n) = n % 100;
    
    lemma mod_positive: \forall integer n; is_valid_input(n) ==> compute_mod(n) >= 0;
*/

/*@
    requires is_valid_input(n);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n % 100 * 21 < 1000;
*/
int func(int n)
{
    unsigned int n_unsigned;
    unsigned int n_mod_100;
    int result;
    
    //@ assert is_valid_input(n);
    
    if (n < 0)
    {
        n_unsigned = (unsigned int)(-n);
    }
    else
    {
        n_unsigned = (unsigned int)n;
    }
    
    //@ assert n_unsigned == (unsigned int)(n < 0 ? -n : n);
    
    n_mod_100 = n_unsigned % 100;
    
    //@ assert n_mod_100 == compute_mod(n);
    
    if (n_mod_100 * 21 < 1000)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    
    //@ assert result == 0 ==> n % 100 * 21 < 1000;
    
    return result;
}
