#include <stdbool.h>

/*@
  requires \true;
  ensures \result <==> (a && b) || (!a && c);
  assigns \nothing;
*/
bool func(bool a, bool b, bool c) {
    bool a_and_b;
    bool not_a_and_c;
    bool res;
    
    //@ assert a && b <==> a && b;
    
    a_and_b = a && b;
    not_a_and_c = (!a) && c;
    res = a_and_b || not_a_and_c;
    
    return res;
}
