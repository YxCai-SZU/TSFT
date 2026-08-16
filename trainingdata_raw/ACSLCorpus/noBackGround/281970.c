#include <limits.h>

/*@
  requires (1 <= (a) <= (b) <= 1000 && 1 <= (k) <= 1000);
  ensures ((\result) >= 0 && (\result) <= 2);
  assigns \nothing;
*/
int min_arrows(int k, int a, int b) {
    int arrows = 0;
    int local_a = a;
    int local_b = b;
    
    //@ assert (1 <= (local_a) <= (local_b) <= 1000 && 1 <= (k) <= 1000);
    
    if (local_a > local_b) {
        int temp = local_a;
        local_a = local_b;
        local_b = temp;
    }
    //@ assert local_a <= local_b;
    
    if (local_b - local_a >= k) {
        arrows += 1;
        local_a = local_b;
    }
    //@ assert arrows >= 0 && arrows <= 1;
    
    if (local_a > 0 && local_a >= k) {
        arrows += 1;
    }
    //@ assert ((arrows) >= 0 && (arrows) <= 2);
    
    return arrows;
}
