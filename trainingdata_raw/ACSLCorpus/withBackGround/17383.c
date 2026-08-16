/*@
predicate valid_params(integer n, integer m, integer x, integer y) =
    1 <= n && n <= 100 &&
    1 <= m && m <= 100 &&
    1 <= x && x <= n &&
    1 <= y && y <= m &&
    x < y && m > 0 && n > 0;

logic integer black_win_condition(integer n, integer m, integer x, integer y) =
    (x + 1 < y) && (n - x < m - y + 1) ? 1 : 0;
*/

/*@
requires valid_params(n, m, x, y);
ensures \result == ((x + 1 < y) && (n - x < m - y + 1) ? 1 : 0);
assigns \nothing;
*/
int func(int n, int m, int x, int y) {
    int result;
    
    //@ assert valid_params(n, m, x, y);
    
    if (x + 1 < y && n - x < m - y + 1) {
        //@ assert black_win_condition(n, m, x, y) == 1;
        result = 1;
    } else {
        //@ assert black_win_condition(n, m, x, y) == 0;
        result = 0;
    }
    
    return result;
}
