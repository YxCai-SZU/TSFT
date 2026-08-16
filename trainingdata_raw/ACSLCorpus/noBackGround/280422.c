#include <stdint.h>

/*@ requires 0 <= x < 0x10;
    ensures \result == x * x;
    assigns \nothing;
 */
uint8_t square_number(uint8_t x)
{
    //@ assert x < 0x10;
    //@ assert x * x < 0x100;
    return x * x;
}

/*@ assigns \nothing; */
void print_square(uint8_t i)
{
    //@ assert \true;
    // Placeholder for external print implementation
}

/*@ assigns \nothing; */
int main()
{
    uint8_t n;
    
    //@ assert 5 < 0x10;
    n = square_number(5);
    //@ assert n == 25;
    print_square(n);
    
    return 0;
}
