#include <stdint.h>
#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert ((a) * (a)) <= 10000;
    return a * a;
}

/*@
    requires ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100));
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int64_t input_tuple(int64_t a, int64_t b)
{
    //@ assert ((1 <= ((a)) && ((a)) <= 100) && (1 <= ((b)) && ((b)) <= 100));
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}

/*@
    requires \valid(arr + (0..1));
    requires ((1 <= ((arr[0])) && ((arr[0])) <= 100) && (1 <= ((arr[1])) && ((arr[1])) <= 100));
    ensures \result == ((arr[0]) * (arr[1]));
    assigns \nothing;
*/
int64_t input_array(int64_t* arr)
{
    //@ assert ((1 <= ((arr[0])) && ((arr[0])) <= 100) && (1 <= ((arr[1])) && ((arr[1])) <= 100));
    //@ assert ((arr[0]) * (arr[1])) <= 10000;
    return arr[0] * arr[1];
}
