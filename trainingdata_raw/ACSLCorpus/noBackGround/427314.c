/*@
    requires n == 10;
    ensures \result <= 30;
*/
int calc_example_6(int n)
{
    int result;
    /*@ assert n == 10; */
    result = n * 2;
    /*@ assert result == n * 2; */
    result = result + 5;
    /*@ assert result == n * 2 + 5; */
    /*@ assert result <= 30; */
    return result;
}

/*@
    requires n == 10;
    ensures \result <= 30;
*/
int calc_example_7(int n)
{
    int result;
    /*@ assert n == 10; */
    result = n * 3;
    /*@ assert result == n * 3; */
    /*@ assert result <= 30; */
    return result;
}

int main()
{
    int n;
    int res1;
    int res2;
    
    n = 10;
    res1 = calc_example_6(n);
    res2 = calc_example_7(n);
    
    return 0;
}
