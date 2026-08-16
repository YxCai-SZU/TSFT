#include <stdbool.h>

/*@
  requires \valid(s + (0..2));
  requires (1 <= (s[0]) <= 100) && (1 <= (s[1]) <= 100) && (1 <= (s[2]) <= 100);
  ensures \result == (s[0] < s[1] && s[1] < s[2]);
  assigns \nothing;
*/
bool func(int s[3]) {
    int a;
    int b;
    int c;
    
    a = s[0];
    b = s[1];
    c = s[2];
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    return a < b && b < c;
}
