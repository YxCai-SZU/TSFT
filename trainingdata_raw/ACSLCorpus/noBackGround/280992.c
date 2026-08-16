/*@
    requires x < y;
    ensures x + 1 <= y + 2;
*/
void complex_relations(int x, int y)
{
    //@ assert x < y;
    //@ assert x + 1 <= y + 2;
    //@ assert y + 1 >= x + 1;
    //@ assert y + 2 >= x + 1;
}

int main() {
    return 0;
}
