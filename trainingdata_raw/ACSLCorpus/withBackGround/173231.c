/*@
    predicate valid_range(integer x) = 0 <= x && x <= 100;
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    logic integer mul_mod(integer a, integer b, integer n) = (a * b) % n;
*/

/*@
    requires valid_n(n);
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == mul_mod(a, b, n);
    assigns \nothing;
*/
int func(int a, int b, int n)
{
    //@ assert valid_n(n);
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert a * b <= 10000;
    return (a * b) % n;
}

int main()
{
    return 0;
}
