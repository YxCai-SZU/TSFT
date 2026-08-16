/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures ((\result) == ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a)));
*/
int func(int a, int b, int c)
{
    int result = 0;
    int temp;

    temp = a + b;
    if (temp == c)
    {
        result = 1;
    }
    else
    {
        temp = a + c;
        if (temp == b)
        {
            result = 1;
        }
        else
        {
            temp = b + c;
            if (temp == a)
            {
                result = 1;
            }
        }
    }

    //@ assert ((result) == ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a)));
    return result;
}
