#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) && (n) <= 100);
  requires (1 <= (m) && (m) <= 100);
  requires \valid(numbers + (0..m-1));
  requires \forall integer i; 0 <= i < m ==> (1 <= (numbers[i]) && (numbers[i]) <= 1000);
  ensures 0 <= \result <= m;
*/
unsigned int func(unsigned int n, unsigned int m, unsigned int* numbers) {
    unsigned int* v = NULL;
    unsigned int v_len = 0;
    unsigned int index = 0;
    
    /*@
      loop invariant 0 <= index <= m;
      loop invariant v_len <= index;
      loop invariant \forall integer k; 0 <= k < v_len ==> (1 <= (v[k]) && (v[k]) <= 1000);
      loop invariant (1 <= (n) && (n) <= 100);
      loop invariant (1 <= (m) && (m) <= 100);
      loop invariant \forall integer k; 0 <= k < m ==> (1 <= (numbers[k]) && (numbers[k]) <= 1000);
      loop assigns index, v_len, v[0..v_len-1];
      loop variant m - index;
    */
    while (index < m) {
        unsigned int a = numbers[index];
        if (a < 10) {
            //@ assert v_len < m;
            v[v_len] = a;
            v_len++;
        }
        index++;
        //@ assert v_len <= index;
    }
    unsigned int ans = v_len;
    return ans;
}
