/*@
    predicate is_even(integer n) = n % 2 == 0;
    
    lemma abs_value: \forall integer n; n >= 0 ==> (n < 0 ? -n : n) == n;
*/

/*@
    requires 1 <= n <= 100000;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> n % 2 == 0;
*/
int func(int n)
{
    int is_even = 0;
    int abs_n;
    
    //@ assert 1 <= n <= 100000;
    
    if (n < 0) {
        abs_n = -n;
    } else {
        abs_n = n;
    }
    
    //@ assert abs_n >= 0;
    //@ assert abs_n == (n < 0 ? -n : n);
    
    /*@
        loop invariant 0 <= abs_n <= n;
        loop invariant abs_n % 2 == n % 2;
        loop assigns abs_n;
        loop variant abs_n;
    */
    while (abs_n >= 2)
    {
        //@ assert abs_n >= 2;
        abs_n -= 2;
        //@ assert abs_n >= 0;
    }
    
    //@ assert abs_n == 0 || abs_n == 1;
    
    if (abs_n == 0) {
        is_even = 1;
        //@ assert n % 2 == 0;
    }
    
    //@ assert is_even == (n % 2 == 0);
    
    if (is_even) {
        //@ assert n % 2 == 0;
        return 1;
    } else {
        return 0;
    }
}
