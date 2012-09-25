--- unix/xserver/hw/xfree86/common/xf86Config.c.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/hw/xfree86/common/xf86Config.c	2012-05-27 11:24:21.000000000 +0900
@@ -937,7 +937,7 @@
     }
 #endif
 
-    xf86Info.aiglx = TRUE;
+    xf86Info.aiglx = FALSE;
     xf86Info.aiglxFrom = X_DEFAULT;
     if (xf86GetOptValBool(FlagOptions, FLAG_AIGLX, &value)) {
 	xf86Info.aiglx = value;
