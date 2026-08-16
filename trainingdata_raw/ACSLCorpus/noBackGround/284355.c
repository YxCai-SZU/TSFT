#include <stdbool.h>
#include <limits.h>

/*@
    requires (2 <= (n) && (n) <= 100000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n) {
    int x = 1;
    int counter = 0;
    
    /*@
        loop invariant 1 <= x <= n + 1;
        loop invariant 0 <= counter <= x - 1;
        loop invariant (2 <= (n) && (n) <= 100000);
        loop assigns x, counter;
        loop variant n - x + 1;
    */
    while (x <= n) {
        bool is_divisible = false;
        int y = 1;
        
        /*@
            loop invariant 1 <= y <= n;
            loop invariant 0 <= counter <= x - 1;
            loop invariant (2 <= (n) && (n) <= 100000);
            loop assigns y, is_divisible;
            loop variant n - y;
        */
        while (y < n) {
            //@ assert y > 0;
            if (x == y * 3 || x == y * 5) {
                is_divisible = true;
                break;
            }
            y += 1;
        }
        
        if (!is_divisible) {
            counter += 1;
        }
        //@ assert x > 0;
        x += 1;
    }
    
    return counter;
}

int main() {
    return 0;
}
