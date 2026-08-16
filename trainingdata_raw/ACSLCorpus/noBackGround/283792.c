#include <limits.h>

/*@
    requires (0 <= (side) <= 1290);
    requires ((side) * (side) * (side) <= INT_MAX);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int volume_cube(int side)
{
    int ret;
    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side <= 1290 * 1290 * 1290;
    ret = side * side * side;
    return ret;
}

/*@
    requires \true;
    ensures \result == 1 <==> ((value) > (threshold));
    ensures \result == 0 <==> !((value) > (threshold));
    assigns \nothing;
*/
int is_greater_than_threshold(int threshold, int value)
{
    int result;
    result = value > threshold;
    return result;
}

/*@
    requires \true;
    ensures \result == 1 <==> ((value) <= (threshold));
    ensures \result == 0 <==> !((value) <= (threshold));
    assigns \nothing;
*/
int is_within_threshold(int threshold, int value)
{
    int result;
    result = value <= threshold;
    return result;
}

void test_volume_cube(void)
{
    int side_length;
    int volume;
    side_length = 5;
    volume = volume_cube(side_length);
}

void test_threshold(void)
{
    int threshold_value;
    int is_greater;
    int is_within;
    threshold_value = 1000;
    is_greater = is_greater_than_threshold(threshold_value, 1200);
    is_within = is_within_threshold(threshold_value, 800);
}
