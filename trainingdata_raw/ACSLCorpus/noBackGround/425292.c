void test_map_insert_remove_extensionality(void)
{
    int m_keys[100];
    int m_size = 0;
    int key = 0;
    int value = 10;
    int i;

    //@ assert !(\exists integer i; 0 <= i < (m_size) && (&m_keys[0])[i] == (key));

    // Insert operation
    m_keys[m_size] = key;
    m_size = m_size + 1;

    //@ assert (\exists integer i; 0 <= i < (m_size) && (&m_keys[0])[i] == (key));
    //@ assert (!(\exists integer i; 0 <= i < ((m_size-1)) && ((&m_keys[0]))[i] == ((key))) &&         (\exists integer i; 0 <= i < ((m_size)) && ((&m_keys[0]))[i] == ((key))));

    // Remove operation
    /*@
        loop invariant 0 <= i <= m_size;
        loop invariant \forall integer j; 0 <= j < i ==> m_keys[j] != key;
        loop assigns i;
    */
    for (i = 0; i < m_size; i++)
    {
        if (m_keys[i] == key)
        {
            m_keys[i] = m_keys[m_size - 1];
            m_size = m_size - 1;
            break;
        }
    }

    //@ assert !(\exists integer i; 0 <= i < (m_size) && (&m_keys[0])[i] == (key));
    //@ assert ((\exists integer i; 0 <= i < ((m_size+1)) && ((&m_keys[0]))[i] == ((key))) &&         !(\exists integer i; 0 <= i < ((m_size)) && ((&m_keys[0]))[i] == ((key))));
}
