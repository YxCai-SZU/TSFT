/*@
    requires (2 <= (A) && (A) <= 100 &&
        2 <= (B) && (B) <= 100);
    ensures \result == A * B - (A + B - 1);
*/
int func(int A, int B)
{
    // Variable declarations at scope top
    int ans;

    //@ assert 2 <= A;
    //@ assert A <= 100;
    //@ assert 2 <= B;
    //@ assert B <= 100;
    //@ assert A * B >= 2 * 2;
    //@ assert A * B <= 100 * 100;
    //@ assert A + B - 1 >= 2 + 2 - 1;
    //@ assert A + B - 1 <= 100 + 100 - 1;

    ans = A * B - (A + B - 1);
    return ans;
}
