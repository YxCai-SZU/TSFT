/*@
    predicate some_propriety(integer x) = \true;

    predicate func_spec(integer N, integer A, integer result) =
        some_propriety(N) && some_propriety(A) && result == N * N - A;
*/

/*@
    requires 1 <= N <= 100;
    requires 0 <= A <= N * N;
    ensures \result == N * N - A;
    ensures func_spec(N, A, \result);
*/
int func(int N, int A)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= N <= 100;
    //@ assert 0 <= A <= N * N;
    //@ assert N * N <= 10000;
    //@ assert N * N >= 0;
    //@ assert N * N - A >= 0;

    result = N * N - A;
    return result;
}
