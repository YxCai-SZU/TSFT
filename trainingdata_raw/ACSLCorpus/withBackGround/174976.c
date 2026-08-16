/*@
    predicate nonnegative(integer x) = x >= 0;
    predicate sum_squares_bounded(integer a, integer b) = a * a + b * b <= 0x7FFFFFFF;

    logic integer sum_of_squares(integer a, integer b) = a * a + b * b;

    lemma squares_nonnegative:
        \forall integer a, b; nonnegative(a) && nonnegative(b) ==> sum_of_squares(a, b) >= 0;
    lemma squares_bounded:
        \forall integer a, b; nonnegative(a) && nonnegative(b) && sum_squares_bounded(a, b) ==>
            sum_of_squares(a, b) <= 0x7FFFFFFF;
*/

/*@
    requires nonnegative(l) && nonnegative(b);
    requires sum_squares_bounded(l, b);
    ensures \result == sum_of_squares(l, b);
    assigns \nothing;
*/
int rectangle_diagonal_squared(int l, int b)
{
    //@ assert nonnegative(l) && nonnegative(b);
    //@ assert sum_squares_bounded(l, b);
    return l * l + b * b;
}

/*@
    requires nonnegative(a) && nonnegative(b);
    requires sum_squares_bounded(a, b);
    ensures \result == sum_of_squares(a, b);
    assigns \nothing;
*/
int right_triangle_hypotenuse_squared(int a, int b)
{
    //@ assert nonnegative(a) && nonnegative(b);
    //@ assert sum_squares_bounded(a, b);
    return a * a + b * b;
}
