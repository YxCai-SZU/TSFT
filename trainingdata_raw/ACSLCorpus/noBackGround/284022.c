/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 3 && \result <= 27;
*/
int sum_example(int a, int b, int c)
{
    int result;
    result = a + b + c;
    //@ assert result >= 3 && result <= 27;
    return result;
}

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 1 && \result <= 729;
*/
int product_example(int a, int b, int c)
{
    int result;
    result = a * b * c;
    //@ assert result >= 1 && result <= 729;
    return result;
}

int main()
{
    int x;
    int y;
    int z;
    int s;
    int p;
    
    x = 5;
    y = 3;
    z = 7;
    
    s = sum_example(x, y, z);
    p = product_example(x, y, z);
    
    return 0;
}
