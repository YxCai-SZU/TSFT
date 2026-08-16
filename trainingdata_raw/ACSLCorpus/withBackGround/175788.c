/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate bounded(integer a, integer b, integer c) =
        a <= 100 && b <= 100 && c <= 100;

    lemma product_bound:
        \forall integer a, b, c;
        non_negative(a, b, c) && bounded(a, b, c) ==>
        a * b * c <= 1000000;
*/

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result <= 1000000;
*/
int non_linear_arith_example(int a, int b, int c)
{
    //@ assert a * b <= 10000;
    //@ assert a * b * c <= 1000000;
    return a * b * c;
}

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result <= 1000000;
*/
int non_linear_arith_example2(int a, int b, int c)
{
    //@ assert a * b <= 10000;
    //@ assert a * b * c <= 1000000;
    return a * b * c;
}

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result <= 1000000;
*/
int non_linear_arith_example3(int a, int b, int c)
{
    //@ assert a * b <= 10000;
    //@ assert a * b * c <= 1000000;
    return a * b * c;
}
