/*@
    requires (1 <= (A) && (A) <= 20 && 1 <= (B) && (B) <= 20);
    ensures (A <= 9 && B <= 9 ==> \result == A * B) && (A > 9 || B > 9 ==> \result == -1);
    assigns \nothing;
*/
int func(int A, int B)
{
    int max_value;
    int result;
    
    max_value = (A > B) ? A : B;
    
    if (A > 9 || B > 9)
    {
        //@ assert A > 9 || B > 9;
        return -1;
    }
    else
    {
        //@ assert A <= 9 && B <= 9;
        //@ assert (1 <= (A) && (A) <= 9) && (1 <= (B) && (B) <= 9);
        //@ assert 1 <= A * B && A * B <= 81;
        return A * B;
    }
}
