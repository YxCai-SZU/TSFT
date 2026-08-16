/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result <= ((a) * 3 + (p));
*/
unsigned int func(unsigned int a, unsigned int p)
{
    unsigned int sum;
    unsigned int ans;
    unsigned int temp_sum;
    unsigned int count;

    //@ assert (0 <= (a) <= 100 && 0 <= (p) <= 100);
    sum = a * 3 + p;
    ans = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant count <= (sum - temp_sum) / 2;
        loop invariant sum == ((a) * 3 + (p));
        loop invariant (0 <= (a) <= 100 && 0 <= (p) <= 100);
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    ans = count;

    //@ assert ans <= ((a) * 3 + (p));
    return ans;
}
