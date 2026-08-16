#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(a_vec + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a_vec)[i] >= 1 && (a_vec)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *a_vec) {
    int ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ((ans) >= 0 && (ans) <= ((integer)index) && ((integer)index) <= (n));
        loop invariant ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a_vec)[i] >= 1 && (a_vec)[i] <= 100);
        loop invariant (\forall integer k; 0 <= k < ((integer)index) ==> ((a_vec)[k] % 2 == 0 ==> (ans) >= 1));
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int a = a_vec[index];
        
        //@ assert a >= 1 && a <= 100;
        
        if ((a & 1) == 0) {
            ans += 1;
        }
        
        //@ assert ((ans) >= 0 && (ans) <= ((integer)index + 1) && ((integer)index + 1) <= (n));
        //@ assert (\forall integer k; 0 <= k < ((integer)index + 1) ==> ((a_vec)[k] % 2 == 0 ==> (ans) >= 1));
        
        index += 1;
    }
    
    //@ assert ((ans) >= 0 && (ans) <= ((n)) && ((n)) <= (n));
    return ans;
}
