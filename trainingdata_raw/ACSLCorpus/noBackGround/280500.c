#include <stdbool.h>
#include <stddef.h>

/*@
  requires s != t;
  requires (1 <= (s) && (s) <= 20) && (1 <= (t) && (t) <= 20);
  requires \valid(v + (0..len-1));
  requires len <= 10;
  requires \forall integer i; 0 <= i < len ==> 
           ((1 <= ((v[i])) && ((v[i])) <= 20) && (v[i]) != (s) && (v[i]) != (t));
  ensures 0 <= \result <= len;
  assigns \nothing;
*/
int func(int s, int t, int* v, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant s != t;
      loop invariant (1 <= (s) && (s) <= 20) && (1 <= (t) && (t) <= 20);
      loop invariant len <= 10;
      loop invariant \forall integer k; 0 <= k < len ==> 
                    ((1 <= ((v[k])) && ((v[k])) <= 20) && (v[k]) != (s) && (v[k]) != (t));
      loop invariant \forall integer j; 0 <= j < i ==> 
                    ((((v[j]) > (s) && (v[j]) < (t)) || ((v[j]) < (s) && (v[j]) > (t))) ==> count >= 1) && 
                    (!(((v[j]) > (s) && (v[j]) < (t)) || ((v[j]) < (s) && (v[j]) > (t))) ==> count >= 0);
      loop invariant count <= len;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        //@ assert ((1 <= ((v[i])) && ((v[i])) <= 20) && (v[i]) != (s) && (v[i]) != (t));
        
        if ((v[i] > s && v[i] < t) || (v[i] < s && v[i] > t)) {
            //@ assert (((v[i]) > (s) && (v[i]) < (t)) || ((v[i]) < (s) && (v[i]) > (t)));
            count += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= count <= len;
    return count;
}
