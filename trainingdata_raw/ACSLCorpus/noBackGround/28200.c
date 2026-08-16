#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] && (l)[j] <= 100);
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int x, unsigned int *l) {
    unsigned int d = 0;
    unsigned int count = 1;
    unsigned int i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        (d) <= (i) * 100 &&
        (count) >= 1 && (count) <= (i) + 1 &&
        ((i) > 0 ==> (d) <= (x) + 100));
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int next_d = d + l[i];
        
        if (next_d > x) {
            break;
        }
        
        d = next_d;
        count += 1;
        i += 1;
        
        //@ assert d <= i * 100;
    }
    
    //@ assert count >= 0 && count <= n + 1;
    return count;
}

int main() {
    return 0;
}
