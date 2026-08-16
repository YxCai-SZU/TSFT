#include <stdint.h>

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
int main() {
    uint32_t a = 7;
    
    //@ assert (a & a) == a;
    //@ assert (a | a) == a;
    //@ assert (a ^ a) == 0;
    
    return 0;
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
void test_truncation(uint64_t a) {
    uint32_t truncated;
    truncated = (uint32_t)a;
    //@ assert truncated == (a & 0xffffffff);
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
void test_truncating_add(uint64_t a, uint64_t b) {
    uint64_t sum;
    sum = a + b;
    //@ assert sum == ((a + b) & 0xffffffffffffffff);
}
