#include <stddef.h>
#include <stdint.h>

/*@
  requires ((len) > 0 && (len) < 0x80000000 &&
      \valid((test_tup) + (0 .. (len)-1)));
  ensures \result >= 0 && \result <= (int32_t)len;
  ensures \forall integer i; 0 <= i < len ==> (test_tup[i] == test_val ==> \result >= 1);
  ensures \forall integer i; 0 <= i < len ==> (test_tup[i] != test_val ==> \result >= 0);
*/
int32_t count_vector_element_equality(int32_t *test_tup, size_t len, int32_t test_val)
{
    int32_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (test_tup[j] == test_val ==> count >= 1) &&
            (test_tup[j] != test_val ==> count >= 0);
        loop invariant ((len) > 0 && (len) < 0x80000000 &&
      \valid((test_tup) + (0 .. (len)-1)));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((len) > 0 && (len) < 0x80000000 &&       \valid((test_tup) + (0 .. (len)-1)));
        
        if (test_tup[i] == test_val) {
            //@ assert test_tup[i] == test_val;
            count += 1;
        } else {
            //@ assert test_tup[i] != test_val;
        }
        
        i += 1;
    }
    
    //@ assert i == len;
    //@ assert count >= 0;
    //@ assert count <= len;
    return count;
}
