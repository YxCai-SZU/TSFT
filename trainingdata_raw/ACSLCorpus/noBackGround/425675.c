/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures ((a + b) % 2 == 0) ==> \result == (a + b) / 2;
    ensures ((a + b) % 2 == 1) ==> \result == -1;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    int result;

    sum = a + b;

    if (sum % 2 == 0)
    {
        //@ assert ((sum) % 2 == 0);
        result = (int)(sum / 2);
    }
    else
    {
        //@ assert ((sum) % 2 == 1);
        result = -1;
    }

    return result;
}
