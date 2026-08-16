/*@
    requires 1 <= n && n <= 100;
    ensures \result == n * n * 3;
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) * (n)) <= 10000;
    //@ assert ((n) * (n) * 3) <= 30000;
    return n * n * 3;
}

/*@
    requires 1 <= n && n <= 100 && 1 <= k && k <= 100;
    ensures \result == n * k;
    assigns \nothing;
*/
unsigned int func2(unsigned int n, unsigned int k)
{
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    //@ assert ((n) * (k)) <= 10000;
    return n * k;
}

/*@
    requires 1 <= n && n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
unsigned int func3(unsigned int n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) * (n)) <= 10000;
    return n * n;
}

/*@
    requires 1 <= n && n <= 100 && 1 <= k && k <= 100;
    ensures \result == n * k * 2;
    assigns \nothing;
*/
unsigned int func4(unsigned int n, unsigned int k)
{
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    //@ assert ((n) * (k)) <= 10000;
    //@ assert ((n) * (k) * 2) <= 20000;
    return n * k * 2;
}
