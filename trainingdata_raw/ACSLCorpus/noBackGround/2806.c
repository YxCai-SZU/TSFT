/*@
    requires (-536870911 <= (s) <= 536870911);
    ensures \result == (4 * (s));
    assigns \nothing;
*/
int perimeter_square(int s)
{
    //@ assert (-536870911 <= (s) <= 536870911);
    return 4 * s;
}
