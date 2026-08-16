#include <stdbool.h>
#include <stddef.h>

/*@ requires 
      length >= 0 && 
      length < 0x80000000 &&
      \valid(list1 + (0 .. length-1));
    ensures 
      ((\result) >= 0 && (\result) <= (length));
*/
int count_occurrences(int *list1, int length, int value)
{
    int i = 0;
    int count = 0;
    
    /*@ loop invariant 0 <= i <= length;
        loop invariant ((count) >= 0 && (count) <= (i));
        loop assigns i, count;
        loop variant length - i;
    */
    while (i < length) {
        //@ assert ((count) >= 0 && (count) <= (i));
        
        if (list1[i] == value) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert ((count) >= 0 && (count) <= (length));
    return count;
}
