/*@
    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            0 <= x <= 100 && 0 <= y <= 100 ==>
            0 <= product(x, y) <= 10000;
*/

/*@
    requires 0 <= x <= 100 && 0 <= y <= 100;
    ensures 0 <= \result <= 10000;
    assigns \nothing;
*/
int compute_product(int x, int y)
{
    int result;
    result = x * y;
    //@ assert 0 <= result <= 10000;
    return result;
}

int main(void)
{
    int a, b, c, d, e, f;
    a = 10;
    b = 20;
    c = compute_product(a, b);
    //@ assert 0 <= c <= 10000;
    
    d = 5;
    e = 8;
    f = compute_product(d, e);
    //@ assert 0 <= f <= 10000;
    
    return 0;
}
