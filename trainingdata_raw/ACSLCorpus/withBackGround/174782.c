/*@
    predicate valid_range(integer n, integer m) =
        0 <= n && n <= 100 &&
        0 <= m && m <= 100 &&
        2 <= n + m;
*/

/*@
    logic integer compute_x(integer m) =
        m >= 13 ? 4 :
        m == 12 ? 3 :
        m >= 6 ? 2 :
        m >= 3 ? 1 :
        0;
*/

/*@
    lemma x_range_0_4:
        \forall integer m; 0 <= m <= 100 ==> 0 <= compute_x(m) <= 4;
*/

/*@
    requires valid_range(n, m);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int x;
    int result;

    //@ assert valid_range(n, m);
    
    if (m >= 13) {
        x = 4;
    } else if (m == 12) {
        x = 3;
    } else if (m >= 6) {
        x = 2;
    } else if (m >= 3) {
        x = 1;
    } else {
        x = 0;
    }
    
    //@ assert x == compute_x(m);
    //@ assert 0 <= x <= 4;
    
    if (n >= 13) {
        if (x == 4) {
            //@ assert x == 4;
            result = 1;
        } else {
            //@ assert x != 4;
            result = 0;
        }
    } else if (n == 12) {
        if (x == 3 || x == 4) {
            //@ assert x == 3 || x == 4;
            result = 1;
        } else {
            //@ assert x != 3 && x != 4;
            result = 0;
        }
    } else if (n >= 6) {
        if (x == 2 || x == 3 || x == 4) {
            //@ assert x == 2 || x == 3 || x == 4;
            result = 1;
        } else {
            //@ assert x != 2 && x != 3 && x != 4;
            result = 0;
        }
    } else if (n >= 3) {
        if (x == 1 || x == 2 || x == 3 || x == 4) {
            //@ assert x == 1 || x == 2 || x == 3 || x == 4;
            result = 1;
        } else {
            //@ assert x != 1 && x != 2 && x != 3 && x != 4;
            result = 0;
        }
    } else {
        if (x == 0 || x == 1 || x == 2 || x == 3 || x == 4) {
            //@ assert x == 0 || x == 1 || x == 2 || x == 3 || x == 4;
            result = 1;
        } else {
            //@ assert x != 0 && x != 1 && x != 2 && x != 3 && x != 4;
            result = 0;
        }
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
