/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * 3) - (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert 3 <= a * 3 <= 300;
    return (a * 3) - b;
}
