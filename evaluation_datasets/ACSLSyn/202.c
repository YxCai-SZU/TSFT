#include <limits.h>
#include <stddef.h>

/*@
    predicate valid_range(integer a) = 3 <= a && a <= 20;
*/

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;
*/

int func_int(int a, int b)
{
    int min_val;
    int result;

    min_val = (a < b) ? a : b;

    if (b < a + 1)
    {
        //@ assert b - 2 >= 0;
        return b - 2;
    }
    else if (a < b)
    {
        //@ assert b - a >= 0;
        return b - a;
    }
    else
    {
        //@ assert b + a - 1 >= 0 && b + a - 1 <= 39;
        return b + a - 1;
    }
}

size_t func_size_t(size_t a, size_t b, size_t c)
{
    size_t res = 0;

    if (b <= c && c <= a)
    {
        res = b + c;
        //@ assert res <= a + b + c;
    }
    else if (c <= b && b <= a)
    {
        res = c + b;
        //@ assert res <= a + b + c;
    }
    else if (a <= c && c <= b)
    {
        res = a + c;
        //@ assert res <= a + b + c;
    }
    else if (a <= b && b <= c)
    {
        res = a + b;
        //@ assert res <= a + b + c;
    }
    else if (b <= a && a <= c)
    {
        res = b + a;
        //@ assert res <= a + b + c;
    }
    else
    {
        res = b + c;
        //@ assert res <= a + b + c;
    }

    //@ assert res == a + b || res == a + c || res == b + c;
    res += 1;
    //@ assert res <= a + b + c;
    //@ assert res == a + b + 1 || res == a + c + 1 || res == b + c + 1;
    return res;
}


int validate_packet_size(int a, int b, size_t c, size_t d, size_t e)
{
    int stage1_result;
    size_t stage2_result;
    int final_result;

    stage1_result = func_int(a, b);

    stage2_result = func_size_t(c, d, e);

    if (stage1_result >= 0 && (size_t)stage1_result <= stage2_result)
    {
        final_result = 1;
        //@ assert final_result == 1;
    }
    else
    {
        final_result = 0;
        //@ assert final_result == 0;
    }

    //@ assert (final_result == 1) ==> ((size_t)stage1_result <= stage2_result);
    return final_result;
}
