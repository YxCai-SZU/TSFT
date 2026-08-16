/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int a_pow_2;
    unsigned int a_pow_3;
    unsigned int ans;

    //@ assert 1 <= a && a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;

    a_pow_2 = a * a;
    a_pow_3 = a * a * a;
    ans = a + a_pow_2 + a_pow_3;

    return ans;
}
