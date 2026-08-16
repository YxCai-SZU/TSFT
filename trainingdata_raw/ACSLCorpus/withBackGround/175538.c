/*@
    predicate valid_x(integer x) = 1 <= x <= 100000;

    logic integer div_500(integer x) = x / 500;
    logic integer mod_500(integer x) = x % 500;
    logic integer div_5(integer r) = r / 5;
    logic integer mod_5(integer r) = r % 5;
    logic integer expected_result(integer x) = 1000 * div_500(x) + 5 * div_5(mod_500(x));

    lemma division_property_500:
        \forall integer x, q, r;
            x >= 1 && x <= 100000 && 0 <= q && q <= div_500(x) && r == x - q * 500 ==>
            r == mod_500(x) ==> q == div_500(x);

    lemma division_property_5:
        \forall integer r, q5, r5;
            r >= 0 && r < 500 && 0 <= q5 && q5 <= div_5(r) && r5 == r - q5 * 5 ==>
            r5 == mod_5(r) ==> q5 == div_5(r);
*/

/*@
    requires valid_x(x);
    ensures \result == expected_result(x);
*/
int func(int x)
{
    int quotient_500;
    int remainder_500;
    int quotient_5;
    int remainder_5;
    int result;

    quotient_500 = 0;
    remainder_500 = x;

    /*@
        loop invariant 0 <= quotient_500 <= div_500(x);
        loop invariant remainder_500 == x - quotient_500 * 500;
        loop invariant valid_x(x);
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        quotient_500 = quotient_500 + 1;
        remainder_500 = remainder_500 - 500;
    }

    //@ assert remainder_500 == mod_500(x);

    quotient_5 = 0;
    remainder_5 = remainder_500;

    /*@
        loop invariant 0 <= quotient_5 <= div_5(remainder_500);
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop invariant valid_x(x);
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        quotient_5 = quotient_5 + 1;
        remainder_5 = remainder_5 - 5;
    }

    //@ assert remainder_5 == mod_5(remainder_500);

    result = 1000 * quotient_500 + 5 * quotient_5;
    return result;
}
