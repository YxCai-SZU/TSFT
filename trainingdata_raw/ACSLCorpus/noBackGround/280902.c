#include <stdint.h>

/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
int main(void) {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t a;
    uint32_t b;
    uint32_t c;

    //@ assert ((2) <= 8 && (3) <= 8 ==> (2) * (3) <= 1000);
    //@ assert ((2) <= 100 && (3) <= 100 ==> (2) * (3) == (3) * (2));
    //@ assert ((2) <= 100 && (3) <= 100 && (4) <= 100 ==> (2) * ((3) * (4)) == ((2) * (3)) * (4));
    //@ assert ((2) <= 100 && (3) <= 100 && (4) <= 100 ==> (2) * ((3) + (4)) == (2) * (3) + (2) * (4));
    //@ assert ((2) <= 10 && (10) <= 10 ==> (2) * (10) <= 100);
    
    return 0;
}
