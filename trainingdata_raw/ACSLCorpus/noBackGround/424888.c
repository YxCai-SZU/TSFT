/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int a_2;
    unsigned int a_3;
    unsigned int ans;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;

    a_2 = a * a;
    a_3 = a_2 * a;
    ans = a + a_2 + a_3;

    return ans;
}
