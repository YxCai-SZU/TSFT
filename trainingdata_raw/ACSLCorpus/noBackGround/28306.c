/*@ requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == x / 500 * 1000 + x % 500 / 5 * 5;
*/
int func(unsigned int x)
{
    unsigned int div500;
    unsigned int temp_x;
    unsigned int div5;

    div500 = 0;
    temp_x = x;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant div500 <= ((x) / 500);
        loop invariant temp_x == x - div500 * 500;
        loop assigns temp_x, div500;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        div500 += 1;
    }

    div5 = 0;

    /*@
        loop invariant 0 <= temp_x <= ((x) % 500);
        loop invariant div5 <= ((x) % 500) / 5;
        loop invariant temp_x == ((x) % 500) - div5 * 5;
        loop assigns temp_x, div5;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        div5 += 1;
    }

    //@ assert div500 == x / 500;
    //@ assert div5 == x % 500 / 5;
    //@ assert temp_x == x % 500 % 5;
    return div500 * 1000 + div5 * 5;
}
