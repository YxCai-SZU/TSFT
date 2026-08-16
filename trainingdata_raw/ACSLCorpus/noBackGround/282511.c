#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == -1 || \result >= 0;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max;
    bool is_possible = false;
    unsigned int a_rem = a;
    unsigned int b_rem = b;
    unsigned int c_rem = c;
    int num_operations = 0;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a >= b) {
        if (a >= c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b >= c) {
            max = b;
        } else {
            max = c;
        }
    }
    
    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) : (c));
    //@ assert (1 <= (max) <= 100);
    
    if (a_rem >= max) {
        is_possible = true;
    } else if (b_rem >= max) {
        is_possible = true;
    } else if (c_rem >= max) {
        is_possible = true;
    }
    
    if (is_possible) {
        /*@
            loop invariant 0 <= num_operations <= 10;
            loop invariant a_rem >= 0 && b_rem >= 0 && c_rem >= 0;
            loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
            loop assigns a_rem, num_operations;
        */
        while (a_rem >= max && num_operations < 10) {
            a_rem -= max;
            num_operations += 1;
        }
        
        /*@
            loop invariant 0 <= num_operations <= 10;
            loop invariant a_rem >= 0 && b_rem >= 0 && c_rem >= 0;
            loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
            loop assigns b_rem, num_operations;
        */
        while (b_rem >= max && num_operations < 10) {
            b_rem -= max;
            num_operations += 1;
        }
        
        /*@
            loop invariant 0 <= num_operations <= 10;
            loop invariant a_rem >= 0 && b_rem >= 0 && c_rem >= 0;
            loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
            loop assigns c_rem, num_operations;
        */
        while (c_rem >= max && num_operations < 10) {
            c_rem -= max;
            num_operations += 1;
        }
        
        if (a_rem == 0 && b_rem == 0 && c_rem == 0) {
            //@ assert num_operations >= 0;
            return num_operations;
        } else {
            //@ assert a_rem != 0 || b_rem != 0 || c_rem != 0;
            return -1;
        }
    } else {
        //@ assert a_rem != 0 || b_rem != 0 || c_rem != 0;
        return -1;
    }
}
