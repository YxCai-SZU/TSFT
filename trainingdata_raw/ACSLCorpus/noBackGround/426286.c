/*@
    requires ((x) <= 100 && (y) <= 100);
    ensures ((\result) == ((x) > (y) ? (x) : (y)));
    assigns \nothing;
*/
unsigned int find_max(unsigned int x, unsigned int y)
{
    unsigned int res;
    //@ assert x <= 100 && y <= 100;
    
    if (x > y) {
        res = x;
    } else {
        res = y;
    }
    
    //@ assert res == (x > y ? x : y);
    return res;
}

/*@
    requires ((x) <= 100 && (y) <= 100);
    ensures ((\result) == ((x) > (y) ? (x) : (y)));
    assigns \nothing;
*/
unsigned int higher_order_find(unsigned int x, unsigned int y)
{
    unsigned int res;
    //@ assert x <= 100 && y <= 100;
    
    res = find_max(x, y);
    
    //@ assert ((res) == ((x) > (y) ? (x) : (y)));
    return res;
}

int main()
{
    unsigned int result;
    
    result = higher_order_find(8, 10);
    //@ assert result == 10;
    
    return 0;
}
