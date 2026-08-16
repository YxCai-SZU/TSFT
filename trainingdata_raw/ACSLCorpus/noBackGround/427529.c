/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (b));
    ensures \result == ((a) * 3 + (b)) / 2;
*/
int func(int a, int b)
{
    int res;
    int tmp;
    int count;

    res = a * 3 + b;
    tmp = 0;
    count = 0;

    /*@
        loop invariant ((1 <= ((a)) && ((a)) <= 100 &&
        1 <= ((b)) && ((b)) <= 100) &&
        (res) >= 0 &&
        (res) <= (((a)) * 3 + ((b))) &&
        (tmp) >= 0 &&
        (tmp) == (count) &&
        (count) <= ((((a)) * 3 + ((b))) - (res)) / 2 &&
        (res) == (((a)) * 3 + ((b))) - 2 * (count));
        loop assigns res, tmp, count;
    */
    while (res >= 2)
    {
        //@ assert res >= 2;
        res -= 2;
        //@ assert res >= 0;
        tmp += 1;
        //@ assert tmp == count + 1;
        count += 1;
        //@ assert count == tmp;
    }

    //@ assert res < 2;
    //@ assert tmp == ((a) * 3 + (b)) / 2;
    return tmp;
}
