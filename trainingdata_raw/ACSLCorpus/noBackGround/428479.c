#include <stdbool.h>

/*@
  requires \valid(v + (0..1));
  requires ((1 <= (v[0])) && ((v[0]) < (v[1])) && ((v[1]) <= 100000));
  ensures \result == true <==> (((v[1]) - (v[0]) == 1) || ((v[1]) - (v[0]) == 2) || ((v[1]) - (v[0]) == 3) || ((v[1]) - (v[0]) == 4) || ((v[1]) - (v[0]) == 5));
*/
bool func(int v[2]) {
    int n;
    int m;
    bool res;

    //@ assert v[0] < v[1];
    n = v[0];
    m = v[1];
    //@ assert m - n >= 1;
    res = (m - n == 1) || (m - n == 2) || (m - n == 3) || (m - n == 4) || (m - n == 5);
    return res;
}
