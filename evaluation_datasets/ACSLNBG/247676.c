
int example_function(int a, int b)
{
    //@ assert a == b + 1;
    //@ assert b < a + 2;
    //@ assert a <= b + 1 * 2;
    
    return 1;
}

int main()
{
    return 0;
}
