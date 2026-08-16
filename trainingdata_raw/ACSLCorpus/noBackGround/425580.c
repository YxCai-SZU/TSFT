/*@
    requires 0 <= a <= 100;
    ensures \result == a;
*/
int identity(int a)
{
    //@ assert 0 <= a <= 100;
    //@ assert a <= 100;
    return a;
}

int main()
{
    int a = 50;
    //@ assert 0 <= a <= 100;
    int result = identity(a);
    return 0;
}
