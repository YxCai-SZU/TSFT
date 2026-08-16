#include <limits.h>

/*@
    requires ((l) > 0 && (w) > 0 && (h) > 0);
    requires ((l) * (w) * (h) < INT_MAX);
    ensures \result == l * w * h;
    assigns \nothing;
*/
int volume_rectangular_prism(int l, int w, int h)
{
    //@ assert ((l) > 0 && (w) > 0 && (h) > 0);
    //@ assert ((l) * (w) * (h) < INT_MAX);
    //@ assert l * w < INT_MAX;
    //@ assert l * w * h < INT_MAX;
    return l * w * h;
}

/*@
    requires ((l) > 0 && (w) > 0 && (h) > 0);
    requires ((l) * (w) < INT_MAX &&
        (w) * (h) < INT_MAX &&
        (l) * (h) < INT_MAX &&
        2 * ((l) * (w) + (w) * (h) + (l) * (h)) < INT_MAX);
    ensures \result == 2 * (l * w + w * h + l * h);
    assigns \nothing;
*/
int surface_area_rectangular_prism(int l, int w, int h)
{
    //@ assert ((l) > 0 && (w) > 0 && (h) > 0);
    //@ assert ((l) * (w) < INT_MAX &&         (w) * (h) < INT_MAX &&         (l) * (h) < INT_MAX &&         2 * ((l) * (w) + (w) * (h) + (l) * (h)) < INT_MAX);
    //@ assert 2 * (l * w + w * h + l * h) < INT_MAX;
    return 2 * (l * w + w * h + l * h);
}
