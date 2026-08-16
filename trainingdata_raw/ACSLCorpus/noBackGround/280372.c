/*@
requires 1 <= a && a <= 100;
requires 1 <= b && b <= 100;
ensures 1 <= \result && \result <= 200;
*/
int proof_func(int a, int b)
{
    //@ assert 1 <= a + b;
    //@ assert a + b <= 200;
    return a + b;
}

int main()
{
    int a;
    int b;
    int result;
    
    a = 50;
    b = 60;
    result = proof_func(a, b);
    
    return 0;
}
