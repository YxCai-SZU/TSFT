#include <stdbool.h>
#include <stddef.h>

/*@ requires N >= 1 && N <= 100;
    requires \valid(A + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> A[i] >= 1 && A[i] <= 100;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= N;
*/
int func(size_t N, const int A[]) {
    int count = 0;
    size_t index = 0;
    int num = 0;
    
    /*@ loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= index;
        loop assigns count, index, num;
        loop variant N - index;
    */
    while (index < N) {
        num = A[index];
        
        if (num % 2 == 0) {
            int div_num = num;
            bool is_even = true;
            
            /*@ loop invariant div_num >= 0;
                loop invariant div_num <= num;
                loop assigns div_num, is_even;
                loop variant div_num;
            */
            while (div_num > 0) {
                if (div_num == 1) {
                    break;
                }
                div_num = div_num / 2;
            }
            
            if (div_num != 1) {
                is_even = false;
            }
            
            if (is_even) {
                count += 1;
            }
        }
        
        index += 1;
    }
    
    return count;
}

int main() {
    return 0;
}
