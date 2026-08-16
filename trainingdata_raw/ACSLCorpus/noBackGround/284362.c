#include <stdbool.h>

/*@ requires (1 <= (n) && (n) <= 100);
    requires \valid(a+(0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) && ((a)[i]) <= 100));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
 */
int func(int n, int *a) {
    int answer = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant answer >= 0;
        loop invariant answer <= index;
        loop assigns answer, index;
        loop variant n - index;
     */
    while (index < n) {
        int num = a[index];
        
        //@ assert (1 <= (num) && (num) <= 100);
        
        if ((num & 1) == 1 && (index & 1) == 0) {
            answer += 1;
        }
        
        index += 1;
    }
    
    //@ assert answer >= 0;
    
    return answer;
}
