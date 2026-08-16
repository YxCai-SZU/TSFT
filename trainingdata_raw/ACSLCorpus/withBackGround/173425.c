/*@
    predicate is_valid_cube(integer n) =
        n * n * n <= 2147483647 && n * n * n >= -2147483648;

    lemma cube_bounds: \forall integer n; is_valid_cube(n) ==> n * n * n <= 2147483647 && n * n * n >= -2147483648;
*/

/*@
    requires is_valid_cube(n);
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert n * n * n <= 2147483647;
    //@ assert n * n * n >= -2147483648;
    
    return n * n * n;
}
