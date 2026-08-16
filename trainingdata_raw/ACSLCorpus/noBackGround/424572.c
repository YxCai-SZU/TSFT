#include <stdbool.h>

struct Rectangle {
    unsigned int width;
    unsigned int height;
};

/*@
  requires \valid(r);
  requires r->width > 0;
  requires r->height > 0;
  ensures \result == (r->width == r->height);
  assigns \nothing;
*/
bool func(struct Rectangle *r)
{
    bool result;
    //@ assert r->width > 0;
    
    if (r->width == r->height) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (r->width == r->height);
    return result;
}

/*@
  requires \valid(r);
  requires r->width > 0;
  requires r->height > 0;
  ensures \result == (r->height > r->width);
  assigns \nothing;
*/
bool func2(struct Rectangle *r)
{
    bool result;
    //@ assert r->height > 0;
    
    if (r->height > r->width) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (r->height > r->width);
    return result;
}

/*@
  requires \valid(r);
  requires r->width > 0;
  requires r->height > 0;
  requires r->width < 10;
  requires r->height > 10;
  ensures \result == true;
  assigns \nothing;
*/
bool func3(struct Rectangle *r)
{
    bool result;
    //@ assert r->width < 10;
    
    result = true;
    
    //@ assert result == true;
    return result;
}

/*@
  requires \valid(r);
  requires r->width > 0;
  requires r->height > 0;
  requires r->width % 2 != 0;
  requires r->height % 2 != 0;
  ensures \result == true;
  assigns \nothing;
*/
bool func4(struct Rectangle *r)
{
    bool result;
    //@ assert r->width % 2 != 0;
    
    result = true;
    
    //@ assert result == true;
    return result;
}

int main()
{
    struct Rectangle r;
    r.width = 4;
    r.height = 4;
    
    //@ assert (((&r)->width == (&r)->height) ==> ((&r)->width > 0));
    return 0;
}
