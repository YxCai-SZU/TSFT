#include <stdint.h>

/*@
    requires (((x) & 3) == ((y) & 3) &&
    ((x) | 3) == ((y) | 3) &&
    ((x) ^ 3) == ((y) ^ 3));
    ensures \true;
    assigns \nothing;
*/
void assert_de_morgan(uint32_t x, uint32_t y)
{
    //@ assert (x & 3) == (y & 3);
}

/*@
    requires (((x) & 0xff) < 0x100 &&
    ((x) | 0xff) >= 0);
    ensures \true;
    assigns \nothing;
*/
void assert_de_morgan_truncation(uint64_t x)
{
    //@ assert (x & 0xff) < 0x100;
}

/*@
    requires (((a) & (b)) == ((b) & (a)) &&
    ((a) | (b)) == ((b) | (a)) &&
    ((a) ^ (b)) == ((b) ^ (a)));
    ensures \true;
    assigns \nothing;
*/
void assert_bitwidth_independence(uint32_t a, uint32_t b)
{
    //@ assert (a & b) == (b & a);
}

/*@
    assigns \nothing;
*/
int main()
{
    uint32_t x = 0;
    uint32_t y = 0;
    uint64_t z = 0;
    uint32_t a = 0;
    uint32_t b = 0;
    
    //@ assert (((x) & 3) == ((y) & 3) &&     ((x) | 3) == ((y) | 3) &&     ((x) ^ 3) == ((y) ^ 3));
    //@ assert (((z) & 0xff) < 0x100 &&     ((z) | 0xff) >= 0);
    //@ assert (((a) & (b)) == ((b) & (a)) &&     ((a) | (b)) == ((b) | (a)) &&     ((a) ^ (b)) == ((b) ^ (a)));
    
    return 0;
}
