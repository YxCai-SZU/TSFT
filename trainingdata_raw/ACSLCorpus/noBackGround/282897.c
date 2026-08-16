/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    ensures 1 <= \result <= 10000;
*/
int func(int a, int b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= a * b <= 10000;
    return a * b;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    ensures 1 <= \result <= 10000;
*/
int func2(int a, int b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= a * b <= 10000;
    return a * b;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    ensures 1 <= \result <= 10000;
*/
int func3(int a, int b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= a * b <= 10000;
    return a * b;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    ensures 1 <= \result <= 10000;
*/
int func4(int a, int b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= a * b <= 10000;
    return a * b;
}

int main()
{
    return 0;
}
