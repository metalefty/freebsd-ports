--- unix/xserver/hw/xfree86/os-support/bsd/i386_video.c.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/hw/xfree86/os-support/bsd/i386_video.c	2012-05-27 11:25:34.000000000 +0900
@@ -32,6 +32,7 @@
 #include "xf86Priv.h"
 
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 
 #ifdef HAS_MTRR_SUPPORT
