/*@
    requires -1000 <= A <= 1000;
    requires -1000 <= B <= 1000;
    ensures \result == A + B || \result == A - B || \result == A * B;
    ensures \result >= A + B;
    ensures \result >= A - B;
    ensures \result >= A * B;
*/
int func(int A, int B)
{
    int sum;
    int diff;
    int prod;
    int max_val;

    sum = A + B;
    diff = A - B;
    //@ assert -1000000 <= A * B <= 1000000;
    prod = A * B;

    //@ assert -1000 <= A <= 1000;
    //@ assert -1000 <= B <= 1000;

    max_val = sum;
    if (diff > max_val)
    {
        max_val = diff;
    }
    if (prod > max_val)
    {
        max_val = prod;
    }

    //@ assert max_val >= A + B;
    //@ assert max_val >= A - B;
    //@ assert max_val >= A * B;

    return max_val;
}
