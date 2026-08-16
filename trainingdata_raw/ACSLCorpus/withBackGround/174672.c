/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer max_product(integer n, integer a) = n * a;

    lemma product_bounds: \forall integer n, integer a;
        valid_params(n, a, 1) ==> max_product(n, a) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at top of scope
    int res;
    int product;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    product = n * a;
    
    if (product < b) {
        res = product;
    } else {
        res = b;
    }
    
    //@ assert res == n * a || res == b;
    //@ assert res <= b;
    
    return res;
}
