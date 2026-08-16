// Generated C + ACSL

#define SUCCESS 1
#define FAILURE 0
#define MAX_ROUTES 100

typedef struct {
    int routes[MAX_ROUTES];
    int routes_len;
} Router;

enum RouteType {
    Start,
    Login,
    Logout,
    ChangePassword
};

void RegisterRoute(Router* router, int path);
int ResolveRoute(Router* router, int path);
int HandleRequest(Router* router, int path);

/*@
    assigns \nothing;
*/
void Main(void)
{
  Router router = {{0}, 0};
  RegisterRoute(&router, Start);
  RegisterRoute(&router, Login);
  RegisterRoute(&router, Logout);
  RegisterRoute(&router, ChangePassword);
  int result = HandleRequest(&router, Login);
  /*@ assert (router.routes[1] == Login); */
  /*@ assert \exists integer i; 0 <= i < router.routes_len && router.routes[i] == Login; */
  /*@ assert (result == SUCCESS); */
}

/*@
    requires router->routes_len < MAX_ROUTES;
    requires \valid(router);
    requires \valid(router->routes + (0 .. MAX_ROUTES-1));
    requires 0 <= router->routes_len < MAX_ROUTES;
    assigns router->routes[router->routes_len], router->routes_len;
    ensures router->routes_len == \old(router->routes_len) + 1;
    ensures router->routes[router->routes_len - 1] == path;
    ensures router->routes[\old(router->routes_len)] == path;
    ensures \forall integer i; 0 <= i < \old(router->routes_len) ==> router->routes[i] == \old(router->routes[i]);
    ensures 0 < router->routes_len <= MAX_ROUTES;
*/
void RegisterRoute(Router* router, int path)
{
  /*@ assert router->routes_len >= 0 && router->routes_len < MAX_ROUTES; */
  /*@ assert \valid(&router->routes[router->routes_len]); */
  if (router->routes_len < MAX_ROUTES) {
    /*@ assert 0 <= router->routes_len < MAX_ROUTES; */
    int old_len = router->routes_len;
    /*@ assert old_len == router->routes_len; */
    router->routes[router->routes_len] = path;
    /*@ assert router->routes[old_len] == path; */
    router->routes_len++;
    /*@ assert router->routes_len == old_len + 1; */
    /*@ assert router->routes[old_len] == path; */
    /*@ assert router->routes[router->routes_len - 1] == path; */
  }
  /*@ assert router->routes_len >= 0 && router->routes_len <= MAX_ROUTES; */
}

/*@
    requires router->routes_len > 0;
    requires \valid_read(router);
    requires \valid_read(router->routes + (0 .. router->routes_len-1));
    assigns \nothing;
    ensures (\exists integer i; 0 <= i < router->routes_len && router->routes[i] == path) ==>
            (\result == SUCCESS);
    ensures (\forall integer i; 0 <= i < router->routes_len ==> router->routes[i] != path) ==>
            (\result == FAILURE);
    ensures \result == SUCCESS || \result == FAILURE;
*/
int ResolveRoute(Router* router, int path)
{
  int i = 0;
  int result = FAILURE;
  /*@ assert result >= 0 && result <= 2147483647; */
/*@
  loop invariant 0 <= i <= router->routes_len;
  loop invariant \forall integer k; 0 <= k < i ==> router->routes[k] != path;
  loop invariant result == SUCCESS ==>
    \exists integer j; 0 <= j < i && router->routes[j] == path;
  loop invariant result == FAILURE ==>
    \forall integer k; 0 <= k < i ==> router->routes[k] != path;
  loop invariant result == \at(result, LoopEntry) || result == SUCCESS;
  loop invariant result == SUCCESS || result == FAILURE;
  loop assigns i, result;
  loop variant router->routes_len - i;
*/
  while ((i < router->routes_len))
    {
      if ((router->routes[i] == path))
      {
        result = SUCCESS;
        /*@ assert result == SUCCESS; */
        /*@ assert router->routes[i] == path; */
        /*@ assert \exists integer j; 0 <= j < router->routes_len && router->routes[j] == path; */
        return result;
      }
      i = (i + 1);
    }
  /*@ assert i == router->routes_len; */
  /*@ assert \forall integer k; 0 <= k < router->routes_len ==> router->routes[k] != path; */
  return result;
}

/*@
    requires router->routes_len > 0;
    requires \valid_read(router);
    requires \valid_read(router->routes + (0 .. router->routes_len-1));
    assigns \nothing;
    ensures (\exists integer i; 0 <= i < router->routes_len && router->routes[i] == path) ==>
            \result == SUCCESS;
    ensures (\forall integer i; 0 <= i < router->routes_len ==> router->routes[i] != path) ==>
            \result == FAILURE;
    ensures \result == SUCCESS || \result == FAILURE;
*/
int HandleRequest(Router* router, int path)
{
  int result = ResolveRoute(router, path);
  /*@ assert result >= 0 && result <= 2147483647; */
  return result;
}