/*@ requires 0 <= A && A <= 100 && 0 <= P && P <= 100;
    ensures \result <= (A * 3 + P) / 2;
 */
unsigned int func(unsigned int A, unsigned int P)
{
    unsigned int sum;
    unsigned int result;
    unsigned int count;

    sum = A * 3 + P;
    result = 0;
    count = 0;

    /*@ loop invariant (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
        loop invariant 0 <= sum && sum <= A * 3 + P;
        loop invariant result <= (A * 3 + P - sum) / 2;
        loop invariant count <= (A * 3 + P - sum) / 2;
        loop invariant result >= 0 && count >= 0;
        loop assigns sum, result, count;
    */
    while (sum >= 2)
    {
        //@ assert sum >= 2;
        sum -= 2;
        result += 1;
    }

    //@ assert result <= (A * 3 + P) / 2;
    return result;
}
