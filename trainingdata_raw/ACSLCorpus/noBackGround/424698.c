#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 2 * 3);
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    int32_t result;
    //@ assert (1 <= (n) && (n) <= 100);
    result = n * 2 * 3;
    //@ assert result == ((n) * 2 * 3);
    return result;
}

/*@
    requires ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100));
    ensures \result == ((a) + (b));
    assigns \nothing;
*/
int32_t input_int_tuple(int32_t a, int32_t b)
{
    int32_t result;
    //@ assert ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100));
    result = a + b;
    //@ assert result == ((a) + (b));
    return result;
}

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 2 && (1 <= ((arr)[0]) && ((arr)[0]) <= 100) && (1 <= ((arr)[1]) && ((arr)[1]) <= 100));
    ensures \result == ((arr)[0] + (arr)[1]);
    assigns \nothing;
*/
int32_t input_int_list(int32_t *arr, int32_t len)
{
    int32_t result;
    //@ assert ((len) >= 2 && (1 <= ((arr)[0]) && ((arr)[0]) <= 100) && (1 <= ((arr)[1]) && ((arr)[1]) <= 100));
    //@ assert len >= 2;
    result = arr[0] + arr[1];
    //@ assert result == ((arr)[0] + (arr)[1]);
    return result;
}
