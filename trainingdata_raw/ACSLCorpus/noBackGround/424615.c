/*@
    requires 1 <= A <= 9;
    requires 1 <= B <= 9;
    requires 1 <= C <= 9;
    ensures \result == A * B * C;
    assigns \nothing;
*/
long func(long A, long B, long C)
{
    long ans;

    //@ assert 1 <= A <= 9;
    //@ assert 1 <= B <= 9;
    //@ assert 1 <= C <= 9;
    //@ assert A * B <= 81;
    //@ assert A * B * C <= 729;

    ans = A * B * C;
    return ans;
}
