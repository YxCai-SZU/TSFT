/*@
    predicate N_in_range(integer N) = 1 <= N && N <= 10;

    logic integer square(integer N) = N * N;
    logic integer cube(integer N) = N * N * N;
    logic integer result_value(integer N) = N + square(N) + cube(N);

    lemma square_bound: \forall integer N; N_in_range(N) ==> square(N) <= 100;
    lemma cube_bound: \forall integer N; N_in_range(N) ==> cube(N) <= 1000;
*/

/*@
    requires 1 <= N && N <= 10;
    ensures \result == N + (N * N) + (N * N * N);
    assigns \nothing;
*/
int func(int N)
{
    int N_2;
    int N_3;
    int ans;

    //@ assert N_in_range(N);
    //@ assert square(N) <= 100;
    //@ assert cube(N) <= 1000;

    N_2 = N * N;
    N_3 = N * N * N;
    ans = N + N_2 + N_3;

    //@ assert ans == result_value(N);
    return ans;
}
