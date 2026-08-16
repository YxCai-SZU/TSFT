/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
*/
int func(long long d, long long t, long long s)
{
    long long product;
    
    //@ assert (1 <= (t) <= 10000);
    //@ assert (1 <= (s) <= 10000);
    //@ assert ((t) * (s)) <= 100000000;
    
    product = t * s;
    
    //@ assert product == ((t) * (s));
    //@ assert product <= 100000000;
    
    return d <= product;
}

int main()
{
    return 0;
}
