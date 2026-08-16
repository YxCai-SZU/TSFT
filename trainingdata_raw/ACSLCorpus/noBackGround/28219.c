#include <stdbool.h>

/*@
  requires ((3) == 3 &&
      \valid((v) + (0 .. 2)) &&
      (v)[0] >= -100 && (v)[0] <= 100 &&
      (v)[1] >= -100 && (v)[1] <= 100 &&
      (v)[2] >= -100 && (v)[2] <= 100);
  ensures \result == 1 <==> ((v)[0] <= (v)[2] && (v)[2] <= (v)[1]);
*/
bool func(int *v)
{
    //@ assert ((3) == 3 &&       \valid((v) + (0 .. 2)) &&       (v)[0] >= -100 && (v)[0] <= 100 &&       (v)[1] >= -100 && (v)[1] <= 100 &&       (v)[2] >= -100 && (v)[2] <= 100);
    
    bool result;
    if (v[0] <= v[2] && v[2] <= v[1]) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == 1 <==> ((v)[0] <= (v)[2] && (v)[2] <= (v)[1]);
    return result;
}
