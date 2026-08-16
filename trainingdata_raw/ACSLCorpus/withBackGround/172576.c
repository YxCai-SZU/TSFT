/*@
    predicate is_valid_params(integer n, integer a) =
        1 <= n <= 10000 && 0 <= a <= 1000;

    logic integer remainder(integer n) = n % 500;

    lemma remainder_bounds: \forall integer n; 1 <= n <= 10000 ==> 0 <= remainder(n) < 500;
*/

/*@
    requires is_valid_params(n, a);
    ensures \result == (remainder(n) <= a);
*/
_Bool func(int n, int a)
{
    int r = 0;
    int temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= a <= 1000;
        loop invariant 0 <= temp_n <= n;
        loop invariant remainder(temp_n) == remainder(n);
        loop invariant r == (n - temp_n) / 500;
        loop assigns temp_n, r;
    */
    while (temp_n >= 500)
    {
        temp_n -= 500;
        r += 1;
    }
    
    int remainder = temp_n;
    
    //@ assert remainder == remainder(n);
    
    return remainder <= a;
}
