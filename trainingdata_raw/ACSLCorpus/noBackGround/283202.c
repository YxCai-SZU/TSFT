#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(v+(0..n-1));
    requires ((n) >= 3 && (n) <= 200000 &&
      (n) % 2 == 1 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] <= (n) &&
      \forall integer i; 0 <= i < (n)-1 ==> (v)[i] != (v)[i+1]);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *v) {
    int cnt = 0;
    int i = 1;
    
    /*@ loop invariant (1 <= (i) <= (n)-1 &&
      (cnt) >= 0 &&
      (cnt) <= (i) &&
      (((n)) >= 3 && ((n)) <= 200000 &&
      ((n)) % 2 == 1 &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((v))[i] <= ((n)) &&
      \forall integer i; 0 <= i < ((n))-1 ==> ((v))[i] != ((v))[i+1]));
        loop invariant n-i >= 0;
        loop assigns cnt, i;
        loop variant n-i;
    */
    while (i < n - 1) {
        int v_i_minus_1 = v[i - 1];
        int v_i = v[i];
        int v_i_plus_1 = v[i + 1];
        
        //@ assert 0 <= i-1 < n && 0 <= i < n && 0 <= i+1 < n;
        
        if ((v_i_minus_1 < v_i && v_i < v_i_plus_1) || 
            (v_i_minus_1 > v_i && v_i > v_i_plus_1)) {
            cnt += 1;
        }
        
        //@ assert cnt >= 0;
        //@ assert cnt <= i+1;
        
        i += 1;
    }
    
    //@ assert 0 <= cnt <= n;
    return cnt;
}
