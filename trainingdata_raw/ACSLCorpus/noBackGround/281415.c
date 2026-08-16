#include <stdbool.h>

/*@
    requires a < 0x80000000 && b < 0x80000000 && c < 0x80000000 && d < 0x80000000 && e < 0x80000000;
    requires k < 0x80000000;
    ensures \result == true <==> (((a) + (k) >= (b)) ||
        ((b) + (k) >= (a)) ||
        ((c) + (k) >= (d)) ||
        ((d) + (k) >= (c)) ||
        ((e) + (k) >= (a)) ||
        ((a) + (k) >= (e)) ||
        ((e) + (k) >= (b)) ||
        ((b) + (k) >= (e)) ||
        ((e) + (k) >= (c)) ||
        ((c) + (k) >= (e)) ||
        ((e) + (k) >= (d)) ||
        ((d) + (k) >= (e)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    bool result;
    //@ ghost unsigned int a_val = a, b_val = b, c_val = c, d_val = d, e_val = e, k_val = k;

    // Declare all variables at the top
    unsigned int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12;

    tmp1 = a + k;
    if (tmp1 >= b)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp2 = b + k;
    if (tmp2 >= a)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp3 = c + k;
    if (tmp3 >= d)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp4 = d + k;
    if (tmp4 >= c)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp5 = e + k;
    if (tmp5 >= a)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp6 = a + k;
    if (tmp6 >= e)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp7 = e + k;
    if (tmp7 >= b)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp8 = b + k;
    if (tmp8 >= e)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp9 = e + k;
    if (tmp9 >= c)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp10 = c + k;
    if (tmp10 >= e)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp11 = e + k;
    if (tmp11 >= d)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    tmp12 = d + k;
    if (tmp12 >= e)
    {
        result = true;
        //@ assert (((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
        return result;
    }

    //@ assert !(((a_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (a_val)) ||         ((c_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (c_val)) ||         ((e_val) + (k_val) >= (a_val)) ||         ((a_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (b_val)) ||         ((b_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (c_val)) ||         ((c_val) + (k_val) >= (e_val)) ||         ((e_val) + (k_val) >= (d_val)) ||         ((d_val) + (k_val) >= (e_val)));
    result = false;
    return result;
}
