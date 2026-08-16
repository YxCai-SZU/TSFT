/*@
    requires (0 <= (l) && 0 <= (b));
    requires ((l) * (b) <= 2147483647);
    ensures \result == ((l) * (b));
    assigns \nothing;
*/
int rectangle_area(int l, int b)
{
    //@ assert ((l) * (b) <= 2147483647);
    return l * b;
}

/*@
    requires (0 <= (l) && 0 <= (b));
    requires (2 * ((l) + (b)) <= 2147483647);
    ensures \result == (2 * ((l) + (b)));
    assigns \nothing;
*/
int rectangle_perimeter(int l, int b)
{
    //@ assert (2 * ((l) + (b)) <= 2147483647);
    return 2 * (l + b);
}
