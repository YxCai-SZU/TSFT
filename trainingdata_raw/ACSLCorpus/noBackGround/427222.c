/*@
    requires (-100 <= (A) && (A) <= 100) && (-100 <= (B) && (B) <= 100) && (-100 <= (C) && (C) <= 100) && (-100 <= (D) && (D) <= 100);
    ensures \result == A + C || \result == A + D || \result == B + C || \result == B + D;
    assigns \nothing;
*/
long func(long A, long B, long C, long D)
{
    long ans;
    long tmp1;
    long tmp2;
    long tmp3;

    ans = A + C;
    //@ assert ans == A + C;
    tmp1 = A + D;
    //@ assert tmp1 == A + D;
    ans = (ans < tmp1) ? tmp1 : ans;
    //@ assert ans == A + C || ans == A + D;
    tmp2 = B + C;
    //@ assert tmp2 == B + C;
    ans = (ans < tmp2) ? tmp2 : ans;
    //@ assert ans == A + C || ans == A + D || ans == B + C;
    tmp3 = B + D;
    //@ assert tmp3 == B + D;
    ans = (ans < tmp3) ? tmp3 : ans;
    //@ assert ans == A + C || ans == A + D || ans == B + C || ans == B + D;
    return ans;
}
