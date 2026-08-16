/*@
    requires (2 <= (x) && (x) <= 100) && (2 <= (y) && (y) <= 100);
    ensures \result == (((x) - 1) * ((y) - 1));
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert x - 1 >= 1;
    //@ assert y - 1 >= 1;
    //@ assert (x - 1) * (y - 1) <= 99 * 99;
    return (x - 1) * (y - 1);
}
