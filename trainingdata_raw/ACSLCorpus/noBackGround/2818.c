/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * (n + 1) / 2;
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int x = 1;
    
    /*@
        loop invariant 1 <= x <= n + 1;
        loop invariant result >= 0;
        loop invariant result == (x - 1) * x / 2;
        loop assigns result, x;
        loop variant n - x + 1;
    */
    while (x <= n)
    {
        //@ assert 0 <= x * (x + 1) <= 100 * 101;
        //@ assert result + x >= 0;
        //@ assert result + x == x * (x + 1) / 2;
        
        result += x;
        x += 1;
    }
    
    //@ assert result == n * (n + 1) / 2;
    return result;
}

int main()
{
    return 0;
}
