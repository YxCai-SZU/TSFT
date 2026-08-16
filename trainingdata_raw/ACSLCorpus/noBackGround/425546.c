/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result <= a;
    ensures \result <= b;
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int i;
    unsigned int res;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    
    i = 1;
    res = 0;

    /*@
        loop invariant ((1 <= ((a)) && ((a)) <= 100 &&
        1 <= ((b)) && ((b)) <= 100) &&
        1 <= (i) && (i) <= (a) + 1 &&
        1 <= (i) && (b) + 1 &&
        (res) <= (a) &&
        (res) <= (b) &&
        (res) >= 0);
        loop assigns i, res;
        loop variant ((a) + (b) - (i));
    */
    while (i <= a && i <= b)
    {
        if (a % i == 0 && b % i == 0)
        {
            res = i;
        }
        i += 1;
    }

    //@ assert res <= a;
    //@ assert res <= b;
    //@ assert res >= 0;

    return res;
}

int main(void)
{
    return 0;
}
