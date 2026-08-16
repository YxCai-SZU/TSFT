/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
int func(int a)
{
    int result;
    //@ assert 1 <= a && a <= 10;
    //@ assert ((a) + (a) * (a) + (a) * (a) * (a)) <= 1331;
    result = a + a * a + a * a * a;
    return result;
}
