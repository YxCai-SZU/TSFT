/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 9;
    
    logic integer cube(integer n) = n * n * n;
    
    lemma square_bound: \forall integer n; 1 <= n <= 9 ==> n * n <= 81;
    lemma cube_bound: \forall integer n; 1 <= n <= 9 ==> n * n * n <= 729;
*/

/*@
    requires 1 <= N <= 9;
    ensures \result == N * N * N;
    assigns \nothing;
*/
int func(int N)
{
    // Variable declarations at scope top
    int res;
    
    //@ assert is_valid_range(N);
    
    //@ assert N * N <= 81;
    
    //@ assert N * N * N <= 729;
    
    res = N * N * N;
    
    //@ assert res == cube(N);
    
    return res;
}

int main()
{
    return 0;
}
