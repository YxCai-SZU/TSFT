#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires N >= 1 && N <= 100;
    requires \valid(a + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> 1 <= a[i] <= 100;
    assigns \nothing;
    ensures 0 <= \result <= N;
    ensures \forall integer i; 0 <= i < N ==> \result >= 1 ==> 1 <= a[i] <= 100;
*/
int func(size_t N, const int64_t a[]) {
    int count = 0;
    size_t num = 0;
    
    /*@
        loop invariant (0 <= (num) <= (N) &&
        0 <= (count) <= (num) &&
        (((N)) >= 1 && ((N)) <= 100 &&
        \valid(((a)) + (0 .. ((N))-1)) &&
        \forall integer i; 0 <= i < ((N)) ==> 1 <= ((a))[i] <= 100) &&
        \forall integer k; 0 <= k < (num) ==> 1 <= (a)[k] <= 100);
        loop assigns num, count;
        loop variant N - num;
    */
    while (num < N) {
        int64_t ai = a[num];
        bool is_divisible = true;
        int i = 2;
        
        /*@
            loop invariant (2 <= (i) <= 10 &&
        (((N)) >= 1 && ((N)) <= 100 &&
        \valid(((a)) + (0 .. ((N))-1)) &&
        \forall integer i; 0 <= i < ((N)) ==> 1 <= ((a))[i] <= 100));
            loop assigns i, is_divisible;
            loop variant 10 - i;
        */
        while (i < 10) {
            int64_t remainder = ai;
            
            /*@
                loop invariant ((N) >= 1 && (N) <= 100 &&
        \valid((a) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (a)[i] <= 100);
                loop assigns remainder;
                loop variant remainder;
            */
            while (remainder >= (int64_t)i) {
                remainder -= (int64_t)i;
            }
            
            if (remainder != 0) {
                is_divisible = false;
            }
            i += 1;
        }
        
        if (is_divisible) {
            count += 1;
        }
        num += 1;
    }
    return count;
}

int main() {
    return 0;
}
