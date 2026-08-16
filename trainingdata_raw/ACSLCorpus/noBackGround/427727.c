#include <stdbool.h>

/*@
  requires \valid(v + (0..2));
  requires 1 <= v[0] <= 9;
  requires 1 <= v[1] <= 9;
  requires 1 <= v[2] <= 9;
  ensures \result == ( (v[0] < v[1] && v[1] < v[2]) ||
                      (v[0] > v[1] && v[1] > v[2]) );
*/
bool func(unsigned int v[3])
{
    //@ assert v[0] >= 1 && v[0] <= 9;
    //@ assert v[1] >= 1 && v[1] <= 9;
    //@ assert v[2] >= 1 && v[2] <= 9;
    
    if ((v[0] < v[1] && v[1] < v[2]) || (v[0] > v[1] && v[1] > v[2])) {
        //@ assert ((((v[0])) < ((v[1])) && ((v[1])) < ((v[2]))) || (((v[0])) > ((v[1])) && ((v[1])) > ((v[2]))));
        return true;
    } else {
        //@ assert !((((v[0])) < ((v[1])) && ((v[1])) < ((v[2]))) || (((v[0])) > ((v[1])) && ((v[1])) > ((v[2]))));
        return false;
    }
}
