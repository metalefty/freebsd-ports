--- unix/xserver/include/eventstr.h.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/include/eventstr.h	2012-05-27 11:17:38.000000000 +0900
@@ -91,9 +91,9 @@
         uint32_t button;  /**< Button number */
         uint32_t key;     /**< Key code */
     } detail;
-    uint16_t root_x;      /**< Pos relative to root window in integral data */
+    int16_t root_x;      /**< Pos relative to root window in integral data */
     float root_x_frac;    /**< Pos relative to root window in frac part */
-    uint16_t root_y;      /**< Pos relative to root window in integral part */
+    int16_t root_y;      /**< Pos relative to root window in integral part */
     float root_y_frac;    /**< Pos relative to root window in frac part */
     uint8_t    buttons[(MAX_BUTTONS + 7)/8]; /**< Button mask */
     struct {
