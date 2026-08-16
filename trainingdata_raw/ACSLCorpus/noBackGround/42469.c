#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
  ensures \result >= 0 && \result <= len;
*/
unsigned int func(int *a, unsigned int len)
{
    unsigned int count = 0;
    unsigned int i = 0;
    
    //@ assert ((len) >= 1 && (len) <= 200000 &&     \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant ((count) >= 0 && (count) <= (i) && (i) <= (len));
        loop invariant ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        bool divisible = false;
        unsigned int j = 0;
        
        /*@ loop invariant 0 <= j <= len;
            loop invariant ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
            loop assigns j, divisible;
            loop variant len - j;
        */
        while (j < len) {
            if (i != j) {
                int ai = a[i];
                int aj = a[j];
                int remainder = ai;
                
                //@ assert aj >= 1 && aj <= 1000000;
                
                /*@ loop invariant remainder >= 0;
                    loop invariant aj >= 1 && aj <= 1000000;
                    loop assigns remainder;
                    loop variant remainder;
                */
                while (remainder >= aj) {
                    remainder -= aj;
                }
                
                if (remainder == 0) {
                    divisible = true;
                }
            }
            j++;
        }
        
        if (!divisible) {
            count++;
        }
        i++;
    }
    
    //@ assert ((count) >= 0 && (count) <= (i) && (i) <= (len));
    return count;
}
