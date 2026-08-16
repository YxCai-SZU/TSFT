#include <stdbool.h>

/*@
    requires x < 4294967295;
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
bool check_odd(unsigned int x) {
    unsigned int num;
    
    num = x;
    
    /*@
        loop invariant num <= x;
        loop invariant num % 2 == x % 2;
        loop assigns num;
        loop variant num;
    */
    while (num >= 2) {
        num -= 2;
    }
    
    //@ assert num == 0 || num == 1;
    return num == 1;
}

int main() {
    return 0;
}
