/*@
    predicate valid_range(integer n) = 1 <= n && n <= 10;

    lemma square_range: \forall integer n; 1 <= n <= 10 ==> 1 <= n*n <= 100;
    lemma cube_range: \forall integer n; 1 <= n <= 10 ==> 1 <= n*n*n <= 1000;
    lemma double_range: \forall integer n; 1 <= n <= 10 ==> 2 <= 2*n <= 20;
    lemma sum_range: \forall integer n; 1 <= n <= 10 ==> n*n*n + 2*n <= 1020;
*/

/*@
    requires 1 <= n <= 10;
    ensures \result == n*n*n + 2*n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert 1 <= n && n <= 10;
    
    //@ assert 1 <= n*n && n*n <= 100;
    
    //@ assert 1 <= n*n*n && n*n*n <= 1000;
    
    //@ assert 2 <= 2*n && 2*n <= 20;
    
    //@ assert n*n*n + 2*n <= 1000 + 20;
    
    return n*n*n + 2*n;
}

int main()
{
    return 0;
}
