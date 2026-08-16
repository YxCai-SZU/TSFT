/*@
    requires a > b && b > c;
    ensures \result == 0;
    ensures a > c;
*/
int func(int a, int b, int c)
{
    //@ assert a > b;
    //@ assert b > c;
    //@ assert a > c;
    //@ assert a >= c + 1;
    //@ assert c + 1 > c;
    //@ assert a > c + 1;
    return 0;
}

int main()
{
    return 0;
}
