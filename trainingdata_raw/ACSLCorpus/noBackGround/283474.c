#include <stddef.h>

/*@
requires (2 <= (N) <= 100000 &&
     \valid((H) + (0 .. (N)-1)) &&
     \forall integer j; 0 <= j < (N) ==> 1 <= (H)[j] <= 10000);
assigns \nothing;
ensures 0 <= \result <= N;
*/
int func(size_t N, int *H) {
    int l = 0;
    int r = 0;
    size_t i = 1;
    
    /*@
    loop invariant (1 <= (i) <= (N) &&
     0 <= (l) <= (i)-1 &&
     0 <= (r) <= (i)-1 &&
     (2 <= ((N)) <= 100000 &&
     \valid(((H)) + (0 .. ((N))-1)) &&
     \forall integer j; 0 <= j < ((N)) ==> 1 <= ((H))[j] <= 10000));
    loop invariant i <= N;
    loop assigns i, l, r;
    loop variant N - i;
    */
    while (i < N) {
        int h = H[i];
        
        //@ assert 0 <= i-1 < N;
        //@ assert 1 <= h <= 10000;
        
        if (H[i-1] < h) {
            //@ assert l <= i-1;
            //@ assert r <= i-1;
            l = (l < r + 1) ? l + 1 : l;
            //@ assert 0 <= l <= i;
        } else {
            //@ assert l <= i-1;
            //@ assert r <= i-1;
            r = (r < l + 1) ? r + 1 : r;
            //@ assert 0 <= r <= i;
        }
        i++;
        //@ assert 1 <= i <= N;
    }
    
    int max_val = (l > r) ? l : r;
    //@ assert 0 <= max_val <= N;
    return max_val;
}
