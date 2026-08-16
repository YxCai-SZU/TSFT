/*@
    requires (0 <= (x) <= 10);
    ensures \result == ((x) * (x) * 3);
    assigns \nothing;
*/
int func(int x)
{
    //@ assert (0 <= (x) <= 10);
    //@ assert (0 <= (x));
    //@ assert x * x <= 100;
    //@ assert x * x * 3 <= 300;
    return x * x * 3;
}

int main()
{
    return 0;
}
