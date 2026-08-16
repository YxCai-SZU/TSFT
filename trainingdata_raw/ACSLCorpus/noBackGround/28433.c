#include <stddef.h>

/*@
    requires ((n) >= 3 && (n) <= 200000 &&
        \valid((ps) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 1 <= *((ps) + i) <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> *((ps) + i) != *((ps) + j)));
    ensures \result >= 0 && \result <= n-2;
*/
int func(size_t n, size_t *ps)
{
    int count = 0;
    size_t i = 2;
    
    /*@
        loop invariant 2 <= i <= n;
        loop invariant count >= 0;
        loop invariant count <= i-2;
        loop invariant ((n) >= 3 && (n) <= 200000 &&
        \valid((ps) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 1 <= *((ps) + i) <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> *((ps) + i) != *((ps) + j)));
        loop assigns i, count;
        loop variant n-i;
    */
    while (i < n) {
        //@ assert i >= 2 && i < n;
        
        //@ assert *(ps + (i-1)) >= 1 && *(ps + (i-1)) <= n;
        //@ assert *(ps + (i-2)) >= 1 && *(ps + (i-2)) <= n;
        //@ assert *(ps + i) >= 1 && *(ps + i) <= n;
        
        //@ assert *(ps + (i-1)) != *(ps + (i-2));
        //@ assert *(ps + i) != *(ps + (i-1));
        //@ assert *(ps + i) != *(ps + (i-2));
        
        if ((ps[i-1] < ps[i-2] && ps[i] < ps[i-1]) || 
            (ps[i-1] < ps[i] && ps[i-2] < ps[i-1])) {
            //@ assert ((*((ps) + ((i)-1)) < *((ps) + ((i)-2)) && *((ps) + (i)) < *((ps) + ((i)-1))) ||         (*((ps) + ((i)-1)) < *((ps) + (i)) && *((ps) + ((i)-2)) < *((ps) + ((i)-1))) ? 1 : 0) == 1;
            count += 1;
        } else {
            //@ assert ((*((ps) + ((i)-1)) < *((ps) + ((i)-2)) && *((ps) + (i)) < *((ps) + ((i)-1))) ||         (*((ps) + ((i)-1)) < *((ps) + (i)) && *((ps) + ((i)-2)) < *((ps) + ((i)-1))) ? 1 : 0) == 0;
        }
        
        //@ assert count >= 0 && count <= (i+1)-2;
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert count >= 0 && count <= n-2;
    return count;
}
