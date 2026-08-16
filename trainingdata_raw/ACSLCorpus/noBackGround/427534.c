/*@
    requires a > -0x80000000 && a < 0x80000000;
    requires b > -0x80000000 && b < 0x80000000;
    requires c > -0x80000000 && c < 0x80000000;
    ensures \result == (a < b && b < c);
*/
int func(int a, int b, int c)
{
    //@ assert a > -0x80000000 && a < 0x80000000;
    //@ assert b > -0x80000000 && b < 0x80000000;
    //@ assert c > -0x80000000 && c < 0x80000000;
    return (a < b && b < c);
}

/*@
    requires 1 <= x && x <= 100;
    ensures \result == x * x;
*/
int func2(int x)
{
    //@ assert 1 <= x && x <= 100;
    //@ assert x * x <= 10000;
    return x * x;
}

int main(void)
{
    return 0;
}
