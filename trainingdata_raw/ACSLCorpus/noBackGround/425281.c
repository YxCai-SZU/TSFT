void main() {
    // Empty main as per original Rust code
}

/*@
    requires m_6 == m_7;
    requires m_7 <= m_8;
    requires m_8 <= m_9;
    requires m_9 == m_a;
    requires m_6 <= 10;
    requires m_7 <= 10;
    requires m_8 <= 10;
    requires m_9 <= 10;
    requires m_a <= 10;
    ensures m_6 <= m_a;
*/
void example_assertion(int m_6, int m_7, int m_8, int m_9, int m_a) {
    //@ assert m_6 == m_7;
    //@ assert m_7 <= m_8;
    //@ assert m_8 <= m_9;
    //@ assert m_9 == m_a;
    //@ assert m_6 <= m_a;
}
