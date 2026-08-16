#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(v+(0..4));
  requires (\forall integer i; 0 <= i < (5) ==> (v)[i] <= (123));
  requires (\forall integer i; 0 <= i < (5)-1 ==> (v)[i] < (v)[i+1]);
  requires k <= 123;
  ensures \result == (v[4] - v[0] <= k);
*/
bool func(unsigned int *v, unsigned int k)
{
    unsigned int array[5];
    unsigned int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> array[j] == v[j];
        loop assigns i, array[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        array[i] = v[i];
        i++;
    }
    
    unsigned int first = array[0];
    unsigned int last = array[4];
    
    //@ assert first == v[0];
    //@ assert last == v[4];
    
    return last - first <= k;
}
