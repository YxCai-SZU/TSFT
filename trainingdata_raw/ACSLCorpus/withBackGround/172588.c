/*@
    predicate pos(integer x) = x > 0;
    predicate product_in_range(integer x, integer y) = x * y <= 4294967295;
*/

/*@
    requires pos(x) && pos(y) && product_in_range(x, y);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y)
{
    //@ assert pos(x) && pos(y) && product_in_range(x, y);
    return x * y;
}

/*@
    requires pos(x) && pos(y) && product_in_range(x, y);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int func2(unsigned int x, unsigned int y)
{
    //@ assert pos(x) && pos(y) && product_in_range(x, y);
    //@ assert product_in_range(x, y);
    return x * y;
}

/*@
    lemma product_eq: \forall integer x, y; pos(x) && pos(y) && product_in_range(x, y) ==> x * y == x * y;
*/

/*@
    requires pos(x) && pos(y) && product_in_range(x, y);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int func3(unsigned int x, unsigned int y)
{
    //@ assert pos(x) && pos(y) && product_in_range(x, y);
    //@ assert product_in_range(x, y);
    //@ assert x * y == x * y;
    return x * y;
}

/*@
    lemma product_in_range_lemma: \forall integer x, y; pos(x) && pos(y) && product_in_range(x, y) ==> product_in_range(x, y);
*/

/*@
    requires pos(x) && pos(y) && product_in_range(x, y);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int func4(unsigned int x, unsigned int y)
{
    //@ assert pos(x) && pos(y) && product_in_range(x, y);
    //@ assert product_in_range(x, y);
    //@ assert x * y == x * y;
    //@ assert product_in_range(x, y);
    return x * y;
}
