/*@
    predicate is_safe_mul(integer n) =
        n * n * n <= 2147483647 &&
        n * n * n >= -2147483648;

    lemma mul_square_bounds:
        \forall integer n;
            is_safe_mul(n) ==>
                n * n <= 2147483647 &&
                n * n >= -2147483648;

    lemma cube_bounds:
        \forall integer n;
            is_safe_mul(n) ==>
                n * n * n <= 2147483647 &&
                n * n * n >= -2147483648;
*/

/*@
    requires is_safe_mul(n);
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int ans;
    int square;

    //@ assert n * n <= 2147483647 && n * n >= -2147483648;
    square = n * n;
    
    //@ assert square * n <= 2147483647 && square * n >= -2147483648;
    ans = square * n;
    
    return ans;
}
