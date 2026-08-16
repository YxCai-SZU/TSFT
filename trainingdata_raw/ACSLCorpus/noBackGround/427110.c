/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0);
    ensures \result == a * (b * c) && \result == (a * b) * c;
*/
int nonlinear_arithmetic_example_7(int a, int b, int c)
{
    //@ assert ((a) > 0) && ((b) > 0) && ((c) > 0);
    int result = a * (b * c);
    //@ assert result == a * (b * c);
    //@ assert result == (a * b) * c;
    return result;
}

/*@
    requires ((x) > 0) && ((y) > 0) && ((z) > 0);
    ensures \result == x * (y * z) && \result == (x * y) * z;
*/
int lemma_mul_is_associative_symmetric(int x, int y, int z)
{
    //@ assert ((x) > 0) && ((y) > 0) && ((z) > 0);
    int result = x * (y * z);
    //@ assert result == x * (y * z);
    //@ assert result == (x * y) * z;
    return result;
}

int main()
{
    int a;
    int b;
    int c;
    int x;
    int y;
    int z;
    
    return 0;
}
