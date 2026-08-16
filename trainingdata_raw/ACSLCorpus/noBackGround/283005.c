/*@ requires
        (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures
        \result <= ((a) * 3 + (p)) &&
        \result >= 0;
*/
int func(unsigned long long a, unsigned long long p)
{
    // Variable declarations at scope top
    unsigned long long sum;
    unsigned long long ret;
    unsigned long long count;

    sum = a * 3 + p;
    ret = sum;
    count = 0;

    /*@ loop invariant
            0 <= ret && ret <= sum;
        loop invariant
            0 <= count && count <= sum / 2;
        loop invariant
            sum == a * 3 + p;
        loop invariant
            sum - 2 * count == ret;
        loop invariant
            (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns
            ret, count;
    */
    while (ret >= 2)
    {
        //@ assert ret >= 2;
        ret -= 2;
        count += 1;
        //@ assert sum - 2 * count == ret;
    }

    //@ assert count <= ((a) * 3 + (p));
    //@ assert count >= 0;
    return count;
}
