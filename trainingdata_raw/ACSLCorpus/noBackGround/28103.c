/*@
requires 1 <= a && a <= 100;
requires 1 <= b && b <= 100;
requires 1 <= c && c <= 100;
ensures 3 <= \result && \result <= 300;
ensures \result <= 2 * a + 2 * b + 2 * c;
*/
int func(int a, int b, int c)
{
    // Variable declarations
    int sum;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    sum = a + b + c;
    
    //@ assert sum == a + b + c;
    
    // Main verification properties
    //@ assert 3 <= sum;
    //@ assert sum <= 300;
    //@ assert sum <= 2 * a + 2 * b + 2 * c;
    
    return sum;
}

int main()
{
    return 0;
}
