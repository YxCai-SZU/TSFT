/*@
    predicate is_valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer max_product(integer a, integer n) = a * n;

    lemma product_bound: \forall integer a, integer n;
        is_valid_params(n, a, 1) ==> max_product(a, n) <= 1000;
*/

/*@ requires is_valid_params(n, a, b);
    ensures \result == a * n || \result == b;
    ensures \result <= b;
*/
int func(int n, int a, int b)
{
    // Variable declarations at top of scope
    int min_value;
    int product;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert a * n <= 1000;

    product = a * n;
    
    if (b < product) {
        min_value = b;
    } else {
        min_value = product;
    }

    //@ assert min_value == a * n || min_value == b;
    //@ assert min_value <= b;
    
    return min_value;
}
