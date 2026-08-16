/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    lemma sum_bound: \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> a + b <= 200;
    lemma product_bound: \forall integer a, b, h; a + b <= 200 && 1 <= h <= 100 ==> (a + b) * h <= 20000;
    lemma division_bound: \forall integer a, b, h; (a + b) * h <= 20000 ==> (a + b) * h / 2 <= 10000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int h)
{
    // Variable declarations at top of scope
    unsigned int sum;
    unsigned int product;
    unsigned int result;

    //@ assert a + b <= 200;
    sum = a + b;

    //@ assert sum * h <= 20000;
    product = sum * h;

    //@ assert product / 2 <= 10000;
    result = product / 2;

    //@ assert result == (a + b) * h / 2;
    return result;
}
