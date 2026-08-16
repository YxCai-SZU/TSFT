#include <stdbool.h>

/*@ requires 1 <= a <= 100 && 1 <= b <= 100;
    ensures \result <= a && \result <= b;
    ensures \result == 1 || (a % \result == 0 && b % \result == 0);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int ans;
    unsigned int i;
    
    ans = 1;
    i = 2;
    
    /*@ loop invariant 2 <= i <= a+1 && 2 <= i <= b+1;
        loop invariant ans <= a && ans <= b;
        loop invariant ans == 1 || (a % ans == 0 && b % ans == 0);
        loop invariant i > 1;
        loop assigns ans, i;
        loop variant (a + b + 2) - i;
    */
    while (i < 1 + a && i < 1 + b) {
        //@ assert i >= 2 && i <= a+1 && i <= b+1;
        if (a % i == 0 && b % i == 0) {
            ans = i;
        }
        i += 1;
    }
    
    //@ assert ans <= a && ans <= b;
    //@ assert ans == 1 || (a % ans == 0 && b % ans == 0);
    return ans;
}

int main() {
    return 0;
}
