/*@
    requires ((a) <= 100) && ((p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int p)
{
    //@ assert a * 3 <= 300;
    //@ assert p <= 100;
    //@ assert a * 3 + p <= 400;
    //@ assert (a * 3 + p) / 2 <= 200;
    return (a * 3 + p) / 2;
}

int main()
{
    unsigned int a;
    unsigned int p;
    unsigned int result;
    
    a = 0;
    p = 0;
    result = func(a, p);
    return 0;
}
