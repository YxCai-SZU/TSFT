/*@
    requires m >= n;
    ensures \result >= 0;
    assigns \nothing;
*/
int calc_example_2(int n, int m)
{
    //@ assert ((m) >= (n) ==> (m) - (n) >= 0);
    //@ assert m - n >= 0;
    return m - n;
}

/*@
    requires n >= m;
    ensures \result <= 0;
    assigns \nothing;
*/
int calc_example_3(int n, int m)
{
    //@ assert ((n) >= (m) ==> (m) - (n) <= 0);
    //@ assert m - n <= 0;
    return m - n;
}

int main()
{
    int n;
    int m;
    int result1;
    int result2;
    
    n = 5;
    m = 8;
    result1 = calc_example_2(n, m);
    
    n = 8;
    m = 5;
    result2 = calc_example_3(n, m);
    
    return 0;
}
