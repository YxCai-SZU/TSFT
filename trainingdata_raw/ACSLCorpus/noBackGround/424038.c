#include <stdbool.h>
#include <stddef.h>

/*@ requires ((N) >= 1 && (N) <= 100 &&
      \valid((a) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0 && \result <= N;
    assigns \nothing;
*/
int func(int N, int *a) {
    int sum = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (size_t)(N) &&
      (((N)) >= 1 && ((N)) <= 100 &&
      \valid(((a)) + (0 .. ((N))-1)) &&
      \forall integer i; 0 <= i < ((N)) ==> ((a))[i] >= 1 && ((a))[i] <= 100) &&
      (sum) >= 0 &&
      (sum) <= (int)(i) &&
      (i) <= (size_t)(N) &&
      (sum) <= (int)((i) + 1));
        loop invariant i <= (size_t)N;
        loop assigns sum, i;
        loop variant (size_t)N - i;
    */
    while (i < (size_t)N) {
        int num = a[i];
        //@ assert num >= 1 && num <= 100;
        
        if ((i & 1) == 0 && (num & 1) == 1) {
            sum += 1;
        }
        i += 1;
    }
    
    //@ assert sum >= 0;
    //@ assert sum <= N;
    return sum;
}
