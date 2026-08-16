/*@
requires (2 <= (x) && (x) <= 10 &&
    5 <= (y) && (y) <= 15 &&
    7 <= (z) && (z) <= 20);
ensures \result <= 45;
assigns \nothing;
*/
int calc_example_8(int x, int y, int z)
{
    //@ assert 2 + 5 + 7 <= x + y + z;
    //@ assert x + y + z <= 10 + 15 + 20;
    
    int sum = x + y + z;
    //@ assert sum <= 45;
    return sum;
}

int main()
{
    int x = 5;
    int y = 10;
    int z = 12;
    
    int result = calc_example_8(x, y, z);
    //@ assert result <= 45;
    
    return 0;
}
