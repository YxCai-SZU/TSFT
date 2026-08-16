#include <stddef.h>
#include <stdint.h>

struct Vec_i64 {
    int64_t* ptr;
    size_t len;
};

/*@
  requires (3 <= (N) <= 20);
  requires ((p->len) == (N));
  requires \valid(p->ptr + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> (\valid(((p->ptr)) + (i)) && ((p->ptr))[(i)] >= 1 && ((p->ptr))[(i)] <= ((N))));
  requires (\forall integer i, j; 0 <= i < j < (N) ==> (p->ptr)[i] != (p->ptr)[j]);
  assigns \nothing;
  ensures 0 <= \result <= N-2;
*/
int32_t func(size_t N, const struct Vec_i64* p) {
    int32_t ans = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= N-1;
      loop invariant 0 <= ans <= i-1;
      loop invariant (3 <= (N) <= 20);
      loop invariant ((p->len) == (N));
      loop invariant \valid(p->ptr + (0 .. N-1));
      loop invariant (\forall integer i; 0 <= i < (N) ==> (\valid(((p->ptr)) + (i)) && ((p->ptr))[(i)] >= 1 && ((p->ptr))[(i)] <= ((N))));
      loop invariant (\forall integer i, j; 0 <= i < j < (N) ==> (p->ptr)[i] != (p->ptr)[j]);
      loop assigns ans, i;
      loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert i-1 < N && i+1 < N;
        if (p->ptr[i-1] < p->ptr[i] && p->ptr[i] < p->ptr[i+1]) {
            ans += 1;
        }
        if (p->ptr[i-1] > p->ptr[i] && p->ptr[i] > p->ptr[i+1]) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
