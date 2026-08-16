#include <stdbool.h>

/*@
  requires \valid(v + (0..2));
  requires (-100 <= (v[0]) && (v[0]) <= 100) && (-100 <= (v[1]) && (v[1]) <= 100) && (-100 <= (v[2]) && (v[2]) <= 100);
  ensures \result ==> ((v)[0] < (v)[1] && (v)[1] < (v)[2]);
  ensures !\result ==> (v[0] >= v[1] || v[1] >= v[2]);
*/
bool is_increasing(int *v) {
    //@ assert (-100 <= (v[0]) && (v[0]) <= 100);
    //@ assert (-100 <= (v[1]) && (v[1]) <= 100);
    //@ assert (-100 <= (v[2]) && (v[2]) <= 100);
    return v[0] < v[1] && v[1] < v[2];
}
