#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
    ensures \result == (k * 500 >= x);
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    unsigned int five_hundreds_num = 0;
    unsigned int i = 0;
    
    //@ assert (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
    //@ assert five_hundreds_num == 500 * i;
    //@ assert i <= k;
    
    /*@
        loop invariant 1 <= k && k <= 100;
        loop invariant 1 <= x && x <= 100000;
        loop invariant five_hundreds_num == 500 * i;
        loop invariant i <= k;
        loop assigns five_hundreds_num, i;
    */
    while (i < k) {
        five_hundreds_num += 500;
        i += 1;
        
        //@ assert five_hundreds_num == 500 * i;
    }
    
    //@ assert five_hundreds_num == 500 * k;
    
    if (five_hundreds_num >= x) {
        //@ assert k * 500 >= x;
        return true;
    } else {
        //@ assert k * 500 < x;
        return false;
    }
}
