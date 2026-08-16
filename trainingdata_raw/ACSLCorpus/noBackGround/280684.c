/*@
    requires (1 <= (A) && (A) <= 50 &&
        1 <= (B) && (B) <= 50 &&
        1 <= (C) && (C) <= 50 &&
        1 <= (K) && (K) <= 50);
    ensures \result <= A;
    ensures \result >= -C;
*/
int func(int A, int B, int C, int K)
{
    int ans = 0;
    int A_val = A;
    int B_val = B;
    int C_val = C;
    int k = K;

    if (k >= A_val)
    {
        ans += A_val;
        k -= A_val;
    }
    else
    {
        ans += k;
        k = 0;
    }

    if (k >= B_val)
    {
        k -= B_val;
    }
    else
    {
        k = 0;
    }

    if (k >= C_val)
    {
        ans -= C_val;
        k -= C_val;
    }
    else
    {
        ans -= k;
        k = 0;
    }

    //@ assert ans <= A;
    //@ assert ans >= -C;
    return ans;
}
