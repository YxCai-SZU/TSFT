/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    unsigned int ans;

    a1 = a;
    //@ assert a1 == a;

    //@ assert ((a) * (a)) <= 100;
    a2 = a * a;
    //@ assert a2 == ((a) * (a));

    //@ assert ((a) * (a) * (a)) <= 1000;
    a3 = a * a * a;
    //@ assert a3 == ((a) * (a) * (a));

    ans = a1 + a2 + a3;
    return ans;
}
