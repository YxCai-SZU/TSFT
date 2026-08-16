/*@
    requires 0 <= x <= 10;
    requires 0 <= y <= 10;
    ensures \result == (x <= y);
    assigns \nothing;
*/
_Bool func(int x, int y)
{
    //@ assert x <= y ==> (x <= y);
    return x <= y;
}
