/*@
    predicate bounds(integer A, integer P) =
        0 <= A <= 100 && 0 <= P <= 100;
        
    logic integer total_sum(integer A, integer P) = A * 3 + P;
*/

/*@
    requires bounds(A, P);
    ensures \result >= 0;
    ensures \result <= total_sum(A, P);
    assigns \nothing;
*/
int func(int A, int P)
{
    int sum;
    int ret;
    int count;
    
    sum = A * 3 + P;
    ret = 0;
    count = sum;
    
    /*@
        loop invariant 0 <= count <= total_sum(A, P);
        loop invariant ret >= 0;
        loop invariant ret <= (total_sum(A, P) - count) / 2;
        loop invariant count + 2 * ret == total_sum(A, P);
        loop invariant bounds(A, P);
        loop assigns count, ret;
        loop variant count;
    */
    while (count >= 2)
    {
        //@ assert ret <= total_sum(A, P);
        ret += 1;
        count -= 2;
    }
    
    //@ assert ret <= total_sum(A, P);
    return ret;
}
