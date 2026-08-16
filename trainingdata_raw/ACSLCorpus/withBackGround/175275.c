/*@
    predicate valid_params(integer N, integer M) =
        2 <= N && N <= 100 &&
        2 <= M && M <= 100;

    logic integer compute_result(integer N, integer M) =
        (N - 1) * (M - 1);

    lemma bounds_lemma:
        \forall integer N, integer M;
        valid_params(N, M) ==>
        (N - 1) >= 1 && (N - 1) <= 99 &&
        (M - 1) >= 1 && (M - 1) <= 99;

    lemma multiplication_bounds:
        \forall integer N, integer M;
        valid_params(N, M) ==>
        compute_result(N, M) >= 1 &&
        compute_result(N, M) <= 9801;
*/

/*@
    requires \valid(result);
    requires 2 <= N && N <= 100;
    requires 2 <= M && M <= 100;
    assigns *result;
    ensures *result == (N - 1) * (M - 1);
    ensures 1 <= *result && *result <= 9801;
*/
void func(int N, int M, int *result)
{
    // Variable declarations at scope top
    int n_minus_one;
    int m_minus_one;
    int computation;

    // Precondition verification
    //@ assert N > 1;
    n_minus_one = N - 1;
    
    //@ assert M > 1;
    m_minus_one = M - 1;
    
    //@ assert n_minus_one >= 1 && n_minus_one <= 99;
    //@ assert m_minus_one >= 1 && m_minus_one <= 99;
    
    // Multiplication bounds verification
    //@ assert n_minus_one * m_minus_one >= 1;
    //@ assert n_minus_one * m_minus_one <= 9801;
    
    computation = n_minus_one * m_minus_one;
    
    // Final bounds check
    //@ assert computation >= 1 && computation <= 9801;
    
    *result = computation;
}

int main()
{
    int res;
    func(2, 2, &res);
    return 0;
}
