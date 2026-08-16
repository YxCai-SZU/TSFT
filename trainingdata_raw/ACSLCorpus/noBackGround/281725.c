#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures (x % 200 == 0 ==> \result == 1) && (x % 200 != 0 ==> \result == 0);
*/
int func(unsigned int x) {
    unsigned int n = 0;
    unsigned int temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= n <= x / 200;
        loop invariant temp_x == x - n * 200;
        loop assigns temp_x, n;
        loop variant temp_x;
    */
    while (temp_x >= 200) {
        //@ assert temp_x >= 200;
        temp_x -= 200;
        n += 1;
    }
    
    int ans = (x == n * 200) ? 1 : 0;
    //@ assert (x % 200 == 0) ==> (ans == 1);
    //@ assert (x % 200 != 0) ==> (ans == 0);
    return ans;
}

int main() {
    return 0;
}
