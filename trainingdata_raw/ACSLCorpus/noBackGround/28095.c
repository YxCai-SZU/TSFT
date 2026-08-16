/*@
    requires \valid_read(A+(0..len-1));
    requires 0 <= len < 0x80000000;
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) / 2 ==> (A)[i] == (A)[(len) - 1 - i]);
 */
_Bool check_palindrome(int *A, int len)
{
    int i;
    i = 0;
    /*@
        loop invariant 0 <= i <= len / 2;
        loop invariant \forall integer j; 0 <= j < i ==> A[j] == A[len - 1 - j];
        loop assigns i;
        loop variant (len / 2) - i;
     */
    while (i < len / 2)
    {
        //@ assert 0 <= i < len / 2;
        if (A[i] != A[len - 1 - i])
        {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
