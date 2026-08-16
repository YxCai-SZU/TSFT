#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max;
    unsigned int tmp_a;
    unsigned int tmp_b;
    unsigned int tmp_c;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a > b)
    {
        if (a > c)
        {
            max = a;
        }
        else
        {
            max = c;
        }
    }
    else
    {
        if (b > c)
        {
            max = b;
        }
        else
        {
            max = c;
        }
    }

    //@ assert max == (((a) > (b)) ? (((a) > (c)) ? (a) : (c)) : (((b) > (c)) ? (b) : (c)));
    //@ assert (1 <= (max) <= 100);

    if (a == max)
    {
        tmp_a = b;
        tmp_b = c;
        tmp_c = a;
    }
    else if (b == max)
    {
        tmp_a = c;
        tmp_b = a;
        tmp_c = b;
    }
    else
    {
        tmp_a = a;
        tmp_b = b;
        tmp_c = c;
    }

    //@ assert (1 <= (tmp_a) <= 100);
    //@ assert (1 <= (tmp_b) <= 100);
    //@ assert (1 <= (tmp_c) <= 100);
    //@ assert tmp_a + tmp_b == tmp_c <==> (a + b == c || b + c == a || c + a == b);

    return tmp_a + tmp_b == tmp_c;
}
