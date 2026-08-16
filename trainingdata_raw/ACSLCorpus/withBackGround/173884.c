/*@
    predicate in_range(integer k, integer a, integer b) =
        1 <= k <= 1000 && 1 <= a <= b <= 1000;

    logic integer div_product(integer b, integer k) = (b / k) * k;

    lemma div_product_bound: \forall integer k, integer b;
        in_range(k, 1, b) ==> b / k <= 1000;

    lemma product_bound: \forall integer k, integer b;
        in_range(k, 1, b) ==> (b / k) * k <= 1000000;
*/

/*@
    requires in_range(k, a, b);
    ensures \result == (b / k * k >= a);
*/
_Bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int bd;
    unsigned int be;
    _Bool result;

    //@ assert b / k <= 1000;
    bd = b / k;
    
    //@ assert (bd * k) <= 1000000;
    be = bd * k;
    
    result = (be >= a);
    return result;
}

int main()
{
    return 0;
}
