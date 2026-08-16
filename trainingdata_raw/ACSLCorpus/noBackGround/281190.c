#include <stdbool.h>

/*@ requires (1 <= (n) <= 20);
    requires \valid(a+(0..n-1)) && \valid(b+(0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 50) && (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] <= 50);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int* a, int* b) {
    int answer = 0;
    int index = 0;
    
    /*@ loop invariant ((1 <= ((n)) <= 20) &&
      0 <= (index) <= (n) &&
      (answer) >= 0 &&
      (\forall integer i; 0 <= i < ((index)) ==> 1 <= ((a))[i] <= 50) &&
      (\forall integer i; 0 <= i < ((index)) ==> 1 <= ((b))[i] <= 50) &&
      (answer) <= (index) * 49);
        loop invariant index <= n;
        loop assigns answer, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert (1 <= (n) <= 20);
        int a_val = a[index];
        int b_val = b[index];
        //@ assert 1 <= a_val <= 50 && 1 <= b_val <= 50;
        
        int diff = (a_val > b_val) ? (a_val - b_val) : (b_val - a_val);
        //@ assert diff >= 0;
        
        answer += diff;
        //@ assert answer >= 0;
        index++;
        //@ assert ((1 <= ((n)) <= 20) &&       0 <= (index) <= (n) &&       (answer) >= 0 &&       (\forall integer i; 0 <= i < ((index)) ==> 1 <= ((a))[i] <= 50) &&       (\forall integer i; 0 <= i < ((index)) ==> 1 <= ((b))[i] <= 50) &&       (answer) <= (index) * 49);
    }
    
    //@ assert answer >= 0;
    return answer;
}
