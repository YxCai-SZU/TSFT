// Generated C + ACSL

#include <stddef.h>

typedef struct Route {
    int routeInfo;
    int exists;
} Route;

typedef struct {
    Route******* data;
} RouteTable;

static RouteTable routes;

/*@
    requires vrfName != \null;
    requires vrfName_len > 0;
    requires \valid_read(vrfName + (0 .. vrfName_len-1));
    requires addressFamily != \null;
    requires addressFamily_len > 0;
    requires \valid_read(addressFamily + (0 .. addressFamily_len-1));
    requires ipVersion != \null;
    requires ipVersion_len > 0;
    requires \valid_read(ipVersion + (0 .. ipVersion_len-1));
    requires routePrefix != \null;
    requires routePrefix_len > 0;
    requires \valid_read(routePrefix + (0 .. routePrefix_len-1));
    assigns routes;
*/
void AddRoute(char* vrfName, int vrfName_len, char* addressFamily, int addressFamily_len, char* ipVersion, int ipVersion_len, char* routePrefix, int routePrefix_len, int routeInfo)
{
  if (routes.data == NULL)
  {
    /* unsupported assign syntax: routes := routes[vrfName := map[]] */
  }
  if (routes.data == NULL)
  {
    /* unsupported assign syntax: routes := routes[vrfName := routes[vrfName][addressFamily := map[]]] */
  }
  if (routes.data == NULL)
  {
    /* unsupported assign syntax: routes := routes[vrfName := routes[vrfName][addressFamily := routes[vrfName][addressFamily][ipVersion := map[]]]] */
  }
  if (routes.data == NULL)
  {
    /* unsupported assign syntax: routes := routes[vrfName := routes[vrfName][addressFamily := routes[vrfName][addressFamily][ipVersion := routes[vrfName][addressFamily][ipVersion][routePrefix := routeInfo]]]] */
  }
}

/*@
    requires vrfName != \null;
    requires vrfName_len > 0;
    requires \valid_read(vrfName + (0 .. vrfName_len-1));
    requires addressFamily != \null;
    requires addressFamily_len > 0;
    requires \valid_read(addressFamily + (0 .. addressFamily_len-1));
    requires ipVersion != \null;
    requires ipVersion_len > 0;
    requires \valid_read(ipVersion + (0 .. ipVersion_len-1));
    requires routePrefix != \null;
    requires routePrefix_len > 0;
    requires \valid_read(routePrefix + (0 .. routePrefix_len-1));
    assigns \nothing;
    ensures (\result == 1) || (\result == 0);
*/
int GetRoute(char* vrfName, int vrfName_len, char* addressFamily, int addressFamily_len, char* ipVersion, int ipVersion_len, char* routePrefix, int routePrefix_len)
{
  if (routes.data == NULL)
  {
    return 0;
  }
  return 1;
}