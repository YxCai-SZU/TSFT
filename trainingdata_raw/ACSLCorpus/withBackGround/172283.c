/*@
    predicate is_odd(integer n) = n % 2 == 1;
    predicate is_even(integer n) = n % 2 == 0;
    
    lemma odd_even_lemma:
        \forall integer n; 1 <= n <= 100 ==> (is_odd(n) || is_even(n));
*/

/*@
    requires 1 <= n <= 100;
    ensures is_odd(n) ==> \result == 1;
    ensures is_even(n) ==> \result == 0;
*/
int func(int n)
{
    int result;
    
    if (n % 2 == 0)
    {
        result = 0;
        //@ assert is_even(n) ==> result == 0;
        return result;
    }
    else
    {
        int i = 0;
        
        /*@
            loop invariant 0 <= i <= 10;
            loop invariant 1 <= n <= 100;
            loop assigns i;
        */
        while (i < 10)
        {
            i = i + 1;
        }
        
        result = 1;
        //@ assert is_odd(n) ==> result == 1;
        return result;
    }
}
