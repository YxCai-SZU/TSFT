/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert x > 0 && x <= 100;
    //@ assert ((x) * (x)) <= 10000;
    //@ assert ((x) * (x)) >= 1;
    result = x * x;
    return result;
}

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func2(int x)
{
    int result;
    //@ assert x > 0 && x <= 100;
    //@ assert ((x) * (x)) <= 10000;
    //@ assert ((x) * (x)) >= 1;
    result = x * x;
    return result;
}

int main()
{
    return 0;
}
