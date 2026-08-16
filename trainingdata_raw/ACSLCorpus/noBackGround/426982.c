#include <stdbool.h>

/*@
    requires \valid(v + (0..len-1));
    requires ((len) >= 1 && (len) <= 100 &&
        \forall integer i; 0 <= i < (len) ==> (v)[i] >= 1 && (v)[i] <= 100);
    ensures \result ==> (\forall integer i; 0 <= i < (len) ==> (((v)[i]) % 2 == 0));
    ensures !\result ==> (\exists integer i; 0 <= i < (len) && !(((v)[i]) % 2 == 0));
*/
bool func(int *v, int len) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant ((len) >= 1 && (len) <= 100 &&
        \forall integer i; 0 <= i < (len) ==> (v)[i] >= 1 && (v)[i] <= 100);
        loop invariant \forall integer k; 0 <= k < i ==> ((v[k]) % 2 == 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        //@ assert v[i] >= 1 && v[i] <= 100;
        
        if (v[i] % 2 != 0) {
            //@ assert !((v[i]) % 2 == 0);
            //@ assert (\exists integer i; 0 <= i < (len) && !(((v)[i]) % 2 == 0));
            return false;
        }
        
        //@ assert ((v[i]) % 2 == 0);
        i++;
    }
    
    //@ assert i == len;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (((v)[i]) % 2 == 0));
    return true;
}
