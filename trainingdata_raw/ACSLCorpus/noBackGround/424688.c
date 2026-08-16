/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures 1 <= \result <= 400;
    assigns \nothing;
*/
int proof_example_2(int a, int b)
{
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    //@ assert 1 <= a * b;
    //@ assert a * b <= 400;
    //@ assert 1 <= a * b <= 400;
    return a * b;
}

int main()
{
    int a;
    int b;
    int result;
    
    a = 10;
    b = 15;
    result = proof_example_2(a, b);
    
    return 0;
}
