/*@
    requires (0 <= (A) <= 100 && 0 <= (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
*/
int func(int A, int P)
{
    int sum;
    int result;
    int count;

    //@ assert (0 <= (A) <= 100 && 0 <= (P) <= 100);
    sum = A * 3 + P;
    //@ assert sum == ((A) * 3 + (P));
    result = 0;
    count = 0;

    /*@
        loop invariant 0 <= sum - 2 * count <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop assigns count;
        loop variant sum - 2 * count;
    */
    while (sum - 2 * count >= 2)
    {
        //@ assert sum - 2 * count >= 2;
        count += 1;
    }

    result = count;
    //@ assert result == count;
    return result;
}
