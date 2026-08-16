/*@
    requires ((l) >= 0);
    requires ((l) * (l) * (l) <= 2147483647);
    ensures \result == l * l * l;
    assigns \nothing;
*/
int volume_cube(int l)
{
    // Declare all variables at the top
    int result;

    //@ assert ((l) >= 0);
    //@ assert ((l) * (l) * (l) <= 2147483647);
    //@ assert (0 <= (l) <= 1290);
    //@ assert (0 <= (l) * (l) <= 1664100);
    //@ assert (0 <= (l) * (l) * (l) <= 2147483647);

    result = l * l * l;
    return result;
}
