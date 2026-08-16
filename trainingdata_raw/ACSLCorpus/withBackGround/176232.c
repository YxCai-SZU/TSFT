/*@
    predicate is_valid_range(integer X, integer Y) =
        1 <= X <= 100 && 1 <= Y <= 100 && Y % 2 == 0;

    logic integer final_result(integer X, integer Y) = X + (Y / 2);

    lemma division_property:
        \forall integer Y; Y % 2 == 0 ==> Y - 2 * (Y / 2) == 0;
*/

/*@
    requires is_valid_range(X, Y);
    ensures \result == final_result(X, Y);
    assigns \nothing;
*/
int func(int X, int Y)
{
    int ans;
    int temp_Y;
    int quotient;
    int remainder;

    ans = X;
    temp_Y = Y;
    quotient = 0;
    remainder = temp_Y;

    /*@
        loop invariant 0 <= quotient <= Y / 2;
        loop invariant remainder == Y - 2 * quotient;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        quotient += 1;
        remainder -= 2;
    }

    //@ assert remainder == 0;
    ans += quotient;
    return ans;
}
