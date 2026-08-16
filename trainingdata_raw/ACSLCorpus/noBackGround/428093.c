#include <stdint.h>

/*@ requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
 */
int32_t volume_cube(int32_t side)
{
    //@ assert side * side >= 0 && side * side <= 1290 * 1290;
    //@ assert side * side * side >= 0 && side * side * side <= 1290 * 1290 * 1290;
    return side * side * side;
}

int main(void)
{
    return 0;
}
