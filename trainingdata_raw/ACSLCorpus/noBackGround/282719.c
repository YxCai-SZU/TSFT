/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
int func(int n)
{
    int count = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant count == (((i) + 1) / 2);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n)
    {
        if (i % 2 == 0)
        {
            //@ assert i % 2 == 0 ==> (((i + 1) + 1) / 2) == (((i) + 1) / 2) + 1;
            count += 1;
        }
        else
        {
            //@ assert i % 2 != 0 ==> (((i + 1) + 1) / 2) == (((i) + 1) / 2);
        }
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert count == (((n) + 1) / 2);
    return count;
}

int main()
{
    return 0;
}
