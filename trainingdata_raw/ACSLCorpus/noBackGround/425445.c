/*@
    requires 0 <= x <= 31;
    requires 0 <= y <= 31;
    ensures \result == ((x) * (y));
    assigns \nothing;
 */
int multiply(int x, int y)
{
    //@ assert x * y <= 31 * 31;
    return x * y;
}

int main()
{
    return 0;
}
