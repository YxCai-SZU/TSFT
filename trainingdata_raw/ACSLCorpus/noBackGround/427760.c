/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    //@ assert a * b <= 10000;
    return a * b;
}
