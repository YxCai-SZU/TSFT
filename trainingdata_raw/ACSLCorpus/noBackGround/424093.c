#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((((l)) / 3) * (((l)) / 3) * (((l)) / 3) - (((l)) / 3) * (((l)) / 3) + (((l)) / 3) + 1);
    ensures \result >= 1;
*/
int64_t func(int64_t l) {
    int64_t l_3 = 0;
    int64_t temp_l = l;
    
    /*@
        loop invariant 0 <= l_3 <= ((l) / 3);
        loop invariant temp_l == l - 3 * l_3;
        loop invariant temp_l >= 0;
        loop assigns l_3, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3) {
        l_3 += 1;
        temp_l -= 3;
    }

    //@ assert l_3 >= 0 && l_3 <= 333;
    //@ assert l_3 * l_3 >= 0 && l_3 * l_3 <= 333 * 333;
    //@ assert l_3 * l_3 * l_3 >= 0 && l_3 * l_3 * l_3 <= 333 * 333 * 333;
    //@ assert l_3 * l_3 * l_3 - l_3 * l_3 + l_3 + 1 >= 1;

    return l_3 * l_3 * l_3 - l_3 * l_3 + l_3 + 1;
}

int main() {
    return 0;
}
