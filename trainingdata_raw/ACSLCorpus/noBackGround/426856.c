#include <stddef.h>
#include <stdbool.h>

/*@
    requires (2 <= (N) <= 200000 &&
        \valid((numbers) + (0 .. (N)-1)) &&
        \forall integer j; 0 <= j < (N) ==> 1 <= (numbers)[j] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t N, const int *numbers) {
    // Variable declarations
    int ans = 100000;
    size_t i = 1;
    
    //@ assert (2 <= (N) <= 200000 &&         \valid((numbers) + (0 .. (N)-1)) &&         \forall integer j; 0 <= j < (N) ==> 1 <= (numbers)[j] <= 1000000000);
    //@ assert ans >= 0;
    
    /*@
        loop invariant 1 <= i <= N;
        loop invariant (2 <= (N) <= 200000 &&
        \valid((numbers) + (0 .. (N)-1)) &&
        \forall integer j; 0 <= j < (N) ==> 1 <= (numbers)[j] <= 1000000000);
        loop invariant ans >= 0;
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N) {
        // Calculate absolute values manually
        int diff1 = numbers[i-1] - 1;
        int diff2 = numbers[i] - 1;
        int num1 = diff1 < 0 ? -diff1 : diff1;
        int num2 = diff2 < 0 ? -diff2 : diff2;
        
        int x = num1 + num2;
        ans = ans < x ? ans : x;
        
        //@ assert ans >= 0;
        i += 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}

int main() {
    return 0;
}
