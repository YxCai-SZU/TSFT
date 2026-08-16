#include <stdint.h>

/*@
    requires ((A) <= 100 && (P) <= 100);
    ensures \result <= ((A) * 3 + (P));
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    uint32_t total_pieces;
    uint32_t result;
    uint32_t temp_total_pieces;

    total_pieces = A * 3 + P;
    result = 0;
    temp_total_pieces = total_pieces;

    /*@
        loop invariant temp_total_pieces <= ((A) * 3 + (P));
        loop invariant result <= (((A) * 3 + (P)) - temp_total_pieces) / 2;
        loop invariant A <= 100 && P <= 100;
        loop invariant temp_total_pieces + 2 * result == ((A) * 3 + (P));
        loop assigns result, temp_total_pieces;
        loop variant temp_total_pieces;
    */
    while (temp_total_pieces >= 2)
    {
        //@ assert temp_total_pieces >= 2;
        result += 1;
        temp_total_pieces -= 2;
        //@ assert temp_total_pieces + 2 * result == ((A) * 3 + (P));
    }

    return result;
}

int main(void)
{
    return 0;
}
