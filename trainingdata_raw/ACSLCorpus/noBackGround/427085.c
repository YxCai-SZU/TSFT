#include <stdint.h>

/*@
    requires side_length > 0;
    requires ((side_length) <= 4294967295 / (side_length));
    ensures \result == ((side_length) * (side_length));
    assigns \nothing;
*/
uint32_t square_area(uint32_t side_length)
{
    //@ assert ((side_length) <= 4294967295 / (side_length));
    return side_length * side_length;
}

/*@
    requires length > 0;
    requires width > 0;
    requires ((length) <= 4294967295 / (width));
    ensures \result == ((length) * (width));
    assigns \nothing;
*/
uint32_t rectangle_area(uint32_t length, uint32_t width)
{
    //@ assert ((length) <= 4294967295 / (width));
    return length * width;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
