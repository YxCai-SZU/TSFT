#include <stdint.h>

/*@
    requires \valid(out);
    assigns *out;
    ensures *out == (x & y);
*/
void bitwise_and(uint64_t x, uint64_t y, uint64_t *out)
{
    *out = x & y;
}

/*@
    requires \valid(out);
    assigns *out;
    ensures *out == (x | y);
*/
void bitwise_or(uint64_t x, uint64_t y, uint64_t *out)
{
    *out = x | y;
}

/*@
    requires \valid(out);
    assigns *out;
    ensures *out == (x ^ y);
*/
void bitwise_xor(uint64_t x, uint64_t y, uint64_t *out)
{
    *out = x ^ y;
}

/*@
    requires x == y;
    ensures \true;
*/
void test_bitwise_operations(uint64_t x, uint64_t y)
{
    //@ assert (x & y) == (y & x);
    //@ assert (x | y) == (y | x);
    //@ assert (x ^ y) == (y ^ x);
}
