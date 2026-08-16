/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result >= 10;
    ensures \result <= 999;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    if (a == b)
    {
        result = a * 10 + c;
        //@ assert result >= 10;
        return result;
    }
    else if (a == c)
    {
        result = a * 10 + b;
        //@ assert result >= 10;
        return result;
    }
    else if (b == c)
    {
        //@ assert a + 10 <= 999;
        result = a + 10;
        //@ assert result >= 10;
        return result;
    }
    else
    {
        int temp1;
        int temp2;
        int max_val;
        int second_val;

        temp1 = (a > b) ? a : b;
        max_val = (temp1 > c) ? temp1 : c;

        if (a == max_val)
        {
            second_val = b;
        }
        else if (b == max_val)
        {
            second_val = a;
        }
        else
        {
            second_val = c;
        }

        result = max_val * 10 + second_val;
        //@ assert result >= 10;
        return result;
    }
}
