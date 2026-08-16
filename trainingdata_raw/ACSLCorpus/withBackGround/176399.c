/*@
    predicate count_invariant(integer i, integer n, integer count) =
        1 <= i <= n + 1 && 0 <= count <= (i - 1) / 2;
        
    lemma count_non_negative:
        \forall integer i, n, count;
        count_invariant(i, n, count) ==> count >= 0;
*/

/*@
    requires 1 <= n <= 100000;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n)
{
    int count = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant 0 <= count <= (i - 1) / 2;
        loop invariant count_invariant(i, n, count);
        loop assigns i, count;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}

int main()
{
    int n = 10;
    int result = func(n);
    return 0;
}
