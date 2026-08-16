#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100;
  requires a >= 1 && b <= 1000;
  requires a < b;
  requires (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= 1000);
  ensures \result >= 0 && \result <= n;
*/
unsigned int func(unsigned int n, unsigned int a, unsigned int b, unsigned int *p)
{
    unsigned int count = 0;
    unsigned int index = 0;
    
    //@ assert ((n) >= 1 && (n) <= 100 &&       (a) >= 1 && (b) <= 1000 &&       (a) < (b));
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant count >= 0;
        loop invariant count <= index;
        loop invariant \forall integer i; 0 <= i < index ==> p[i] >= 1 && p[i] <= 1000;
        loop invariant ((n) >= 1 && (n) <= 100 &&
      (a) >= 1 && (b) <= 1000 &&
      (a) < (b));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= 1000);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n)
    {
        unsigned int value = p[index];
        
        //@ assert value >= 1 && value <= 1000;
        
        if (value <= a) {
            count += 1;
        } else if (value <= b) {
            count += 1;
        } else {
            count += 1;
        }
        
        //@ assert count <= index + 1;
        
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
