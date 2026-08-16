/*@
    requires (1 <= (x) && (x) <= 10) && (1 <= (y) && (y) <= 10);
    ensures \result == x * x + y * y + x * y;
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert (1 <= (y) && (y) <= 10);
    //@ assert x * x <= 100;
    //@ assert y * y <= 100;
    //@ assert x * y <= 100;
    return x * x + y * y + x * y;
}
