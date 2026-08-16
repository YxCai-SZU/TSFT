/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) * (x) * (x) + (x) * (x) + (x));
    assigns \nothing;
*/
int func(int x)
{
    //@ assert (1 <= (x) <= 10);
    //@ assert x * x <= 100;
    //@ assert x * x * x <= 1000;
    //@ assert x * x * x + x * x + x <= 1110;
    return x * x * x + x * x + x;
}
