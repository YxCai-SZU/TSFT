/*@
    requires (1 <= (x) && (x) <= 8) && (1 <= (y) && (y) <= 8);
    ensures \result == x * y;
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert (1 <= (x) && (x) <= 8);
    //@ assert (1 <= (y) && (y) <= 8);
    //@ assert ((x) * (y) <= 64);
    return x * y;
}
