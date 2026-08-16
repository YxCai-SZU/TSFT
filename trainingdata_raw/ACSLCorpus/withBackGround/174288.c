/*@
    predicate is_valid_params(integer n, integer a, integer b) =
        1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50;
    
    logic integer max_product(integer n, integer a) = n * a;
*/

/*@
    requires is_valid_params(n, a, b);
    ensures \result <= b;
    ensures \result == b || \result == max_product(n, a);
*/
unsigned int func(unsigned int n, unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int ans;
    
    //@ assert max_product(n, a) <= 1000;
    //@ assert max_product(n, a) >= b || b >= b;
    
    if (n * a < b) {
        ans = n * a;
    } else {
        ans = b;
    }
    
    return ans;
}
