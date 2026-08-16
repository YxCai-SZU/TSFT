/*@
    requires ((n) > 0);
    ensures \result == ((((a) % (n)) * ((b) % (n))) % (n));
    assigns \nothing;
*/
int non_linear_arith_example10(int a, int b, int n)
{
    //@ assert ((n) > 0);
    return ((a % n) * (b % n)) % n;
}

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result == 1;
    assigns \nothing;
*/
int non_linear_arith_example11(int a, int b, int c)
{
    //@ assert a * b <= 10000;
    return 1;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
