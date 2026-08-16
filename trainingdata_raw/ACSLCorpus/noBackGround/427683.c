/*@
    requires (0 <= (side) <= 1000);
    ensures \result == side * side * side;
    assigns \nothing;
*/
int cube_volume(int side)
{
    //@ assert side * side <= 1000000;
    //@ assert side * side * side <= 1000000000;
    return side * side * side;
}

int main()
{
    return 0;
}
