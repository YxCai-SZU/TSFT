/*@
    requires 1 <= a <= 100000;
    ensures \result == (a >= 2000 || a % 200 == 0);
    assigns \nothing;
*/
int func(int a)
{
    int result;
    int is_divisible;
    int count;
    int temp_a;

    if (a >= 2000)
    {
        //@ assert a >= 2000;
        return 1;
    }

    is_divisible = 0;
    count = 0;
    temp_a = a;

    /*@
        loop invariant 1 <= a <= 100000;
        loop invariant 0 <= temp_a <= a;
        loop invariant count <= a / 200;
        loop invariant temp_a == a - 200 * count;
        loop assigns temp_a, count;
        loop variant temp_a;
    */
    while (temp_a >= 200)
    {
        //@ assert temp_a >= 200;
        temp_a -= 200;
        count += 1;
    }

    if (temp_a == 0)
    {
        //@ assert temp_a == 0;
        is_divisible = 1;
    }

    result = is_divisible;
    //@ assert result == (a >= 2000 || a % 200 == 0);
    return result;
}
