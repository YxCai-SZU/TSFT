#include <stdint.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] <= 1000000000);
  ensures \result >= 0;
*/
int64_t func(size_t n, uint64_t *a)
{
    uint64_t search;
    size_t index;
    int64_t count;
    
    search = 1;
    index = 0;
    count = 0;
    
    //@ assert (0 <= (index) && (index) <= (n) &&       1 <= (search) && (search) <= 1000000001 &&       0 <= (count) && (count) <= (int64_t)(index) &&       ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (a)[i] <= 1000000000) &&       (((n)) > 0 && ((n)) <= 200000 &&       \valid(((a)) + (0 .. ((n))-1)) &&       \forall integer i; 0 <= i < ((n)) ==> ((a))[i] <= 1000000000) &&       (count) >= 0);
    
    /*@ loop invariant (0 <= (index) && (index) <= (n) &&
      1 <= (search) && (search) <= 1000000001 &&
      0 <= (count) && (count) <= (int64_t)(index) &&
      ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (a)[i] <= 1000000000) &&
      (((n)) > 0 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] <= 1000000000) &&
      (count) >= 0);
        loop assigns index, search, count;
        loop variant n - index;
    */
    while (index < n) {
        uint64_t i;
        
        i = a[index];
        
        if (i < search) {
            //@ assert i < search;
            count = count + 1;
            //@ assert count >= 0;
        } else if (i == search) {
            //@ assert i == search;
            search = i + 1;
            //@ assert 1 <= search && search <= 1000000001;
        }
        
        index = index + 1;
        //@ assert index <= n;
        //@ assert count <= (int64_t)index;
    }
    
    //@ assert count >= 0;
    return count;
}
