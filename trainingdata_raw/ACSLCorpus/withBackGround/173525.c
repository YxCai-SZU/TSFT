/*@
    predicate is_prime(integer n) =
        n > 1 && \forall integer k; 2 <= k < n ==> n % k != 0;
*/

/*@
    requires n > 0;
    ensures \result == 1 <==> is_prime(n);
    assigns \nothing;
*/
int is_prime(unsigned int n)
{
    unsigned int i;
    
    if (n <= 1)
    {
        return 0;
    }
    
    i = 2;
    /*@
        loop invariant 2 <= i;
        loop invariant i <= n + 1;
        loop invariant \forall integer k; 2 <= k < i ==> n % k != 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        if (n % i == 0)
        {
            return 0;
        }
        i = i + 1;
    }
    
    return 1;
}

int main(void)
{
    return 0;
}
