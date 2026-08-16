#include <stdbool.h>

/*@ requires ((((a)) > 0) && (((b)) > 0) && (((c)) > 0) && (((d)) > 0) && (((e)) > 0) &&
        (((a)) < 124) && (((b)) < 124) && (((c)) < 124) && (((d)) < 124) && (((e)) < 124) &&
        (((k)) >= 0 && ((k)) <= 123) &&
        (((a)) < ((b)) && ((b)) < ((c)) && ((c)) < ((d)) && ((d)) < ((e))));
    ensures \result == true || \result == false;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int p = 0;
    int i = 0;

    /*@ loop invariant 0 <= i <= 5;
        loop invariant ((((a)) > 0) && (((b)) > 0) && (((c)) > 0) && (((d)) > 0) && (((e)) > 0) &&
        (((a)) < 124) && (((b)) < 124) && (((c)) < 124) && (((d)) < 124) && (((e)) < 124) &&
        (((k)) >= 0 && ((k)) <= 123) &&
        (((a)) < ((b)) && ((b)) < ((c)) && ((c)) < ((d)) && ((d)) < ((e))));
        loop invariant p >= 0;
        loop assigns p, i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i && i < 5;
        
        p = (i == 0) ? a : 
            (i == 1) ? b : 
            (i == 2) ? c : 
            (i == 3) ? d : e;
        
        //@ assert p == ((i) == 0 ? (a) :         (i) == 1 ? (b) :         (i) == 2 ? (c) :         (i) == 3 ? (d) :         (e));
        
        if (i == 0) {
            if (a + k < p) {
                //@ assert a + k < p;
            }
        } else if (i == 1) {
            if (b + k < p) {
                //@ assert b + k < p;
            }
        } else if (i == 2) {
            if (c + k < p) {
                //@ assert c + k < p;
            }
        } else if (i == 3) {
            if (d + k < p) {
                //@ assert d + k < p;
            }
        } else if (i == 4) {
            if (e + k < p) {
                //@ assert e + k < p;
            }
        }
        
        i += 1;
        //@ assert i <= 5;
    }
    
    //@ assert i == 5;
    return true;
}
