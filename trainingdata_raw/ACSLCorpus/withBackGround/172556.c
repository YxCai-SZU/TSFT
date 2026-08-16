/*@
    predicate bounds(integer x) = 1 <= x <= 100;

    lemma product_bound:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> x * y <= 100 * 100;

    lemma triple_product_bound:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) ==> (x * y) * z <= (100 * 100) * 100;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    ensures \result == 0;
    ensures x * y <= 100 * 100;
    ensures (x * y) * z <= (100 * 100) * 100;
*/
int non_linear_arith_example(int x, int y, int z)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    
    //@ assert x * y <= 100 * 100;
    //@ assert (x * y) * z <= (100 * 100) * 100;
    
    return 0;
}

int main()
{
    return 0;
}
