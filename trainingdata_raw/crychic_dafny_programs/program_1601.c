// Generated C + ACSL

int zoom;
int center;
int* cameras;
int cameras_len;
int userLocation;

/*@
    requires 0 <= zoom < 19;
    assigns zoom;
    ensures zoom == \old(zoom) + 1;
    ensures 0 < zoom <= 19;
    ensures center == \old(center);
    ensures cameras == \old(cameras);
    ensures userLocation == \old(userLocation);
*/
void ZoomIn(void)
{
  zoom = (zoom + 1);
  /*@ assert zoom >= 0 && zoom <= 2147483647; */
}

/*@
    requires zoom > 0;
    requires zoom <= 19;
    assigns zoom;
    ensures zoom == \old(zoom) - 1;
    ensures 0 <= zoom < 19;
    ensures center == \old(center);
    ensures cameras == \old(cameras);
    ensures userLocation == \old(userLocation);
*/
void ZoomOut(void)
{
  zoom = (zoom - 1);
  /*@ assert zoom >= 0 && zoom <= 2147483647; */
}

/*@
    requires loc > 0;
    requires loc <= 2147483647;
    assigns userLocation;
    ensures userLocation == loc;
    ensures userLocation > 0;
*/
void SetUserLocation(int loc)
{
  userLocation = loc;
  /*@ assert userLocation >= 0 && userLocation <= 2147483647; */
}

/*@
    requires cameraData != \null;
    requires cameraData_len >= 0;
    requires \valid(cameraData + (0 .. cameraData_len-1));
    requires \forall integer i; 0 <= i < cameraData_len ==> cameraData[i] != 0;
    assigns cameras, cameras_len;
*/
void SetCameraMarkers(int* cameraData, int cameraData_len)
{
  cameras = cameraData;
  cameras_len = cameraData_len;
}

/*@
    requires userLocation > 0;
    requires userLocation <= 2147483647;
    assigns center, zoom;
    ensures center == userLocation;
    ensures center > 0;
    ensures zoom == 16;
    ensures cameras == \old(cameras);
    ensures userLocation == \old(userLocation);
*/
void FlyToUser(void)
{
  center = userLocation;
  /*@ assert center >= 0 && center <= 2147483647; */
  zoom = 16;
  /*@ assert zoom >= 0 && zoom <= 2147483647; */
}