/*@
    requires 0 <= n && n <= 100;
    requires 0 <= m && m <= 100;
    requires n != m;
    ensures \result == 1;
    assigns \nothing;
*/
int verify_distinct_squares(int n, int m) {
    //@ ghost int n_sq = n * n;
    //@ ghost int m_sq = m * m;

    //@ assert n_sq != m_sq;

    return 1;
}

int main() {
    return 0;
}
