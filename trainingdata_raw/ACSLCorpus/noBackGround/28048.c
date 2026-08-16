#include <stdbool.h>
#include <stdint.h>

/*@
    requires ((a) < 0x80000000 && (b) < 0x80000000 && (c) < 0x80000000 && (d) < 0x80000000 && (e) < 0x80000000 && (k) < 0x80000000) && ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t k)
{
    //@ assert ((a) < 0x80000000 && (b) < 0x80000000 && (c) < 0x80000000 && (d) < 0x80000000 && (e) < 0x80000000 && (k) < 0x80000000);
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    uint32_t v[5];
    uint32_t i;
    bool ans;
    
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    
    i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < 5 ==> v[j] == v[j];
        loop invariant ((a) < 0x80000000 && (b) < 0x80000000 && (c) < 0x80000000 && (d) < 0x80000000 && (e) < 0x80000000 && (k) < 0x80000000);
        loop invariant ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert i < 5;
        i = i + 1;
        //@ assert i <= 5;
    }
    
    //@ assert i == 5;
    //@ assert ((a) < 0x80000000 && (b) < 0x80000000 && (c) < 0x80000000 && (d) < 0x80000000 && (e) < 0x80000000 && (k) < 0x80000000);
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    if (e - a <= k) {
        ans = true;
        //@ assert ans == true;
        //@ assert e - a <= k;
    } else {
        ans = false;
        //@ assert ans == false;
        //@ assert !(e - a <= k);
    }
    
    //@ assert ans == (e - a <= k);
    return ans;
}
