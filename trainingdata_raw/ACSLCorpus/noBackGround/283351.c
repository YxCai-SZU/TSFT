/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == x * y;
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert ((x) >= 1 && (x) <= 100 && (y) >= 1 && (y) <= 100);
    //@ assert x * y >= 1;
    //@ assert x * y <= 10000;
    return x * y;
}
