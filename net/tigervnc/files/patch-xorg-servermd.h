--- unix/xserver/include/servermd.h.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/include/servermd.h	2012-05-27 11:28:37.000000000 +0900
@@ -133,7 +133,7 @@
     defined(__sparc__) || defined(__mc68000__)
 
 #if defined(__sparc) || defined(__sparc__)
-# if !defined(sparc)
+# if !defined(sparc) && !defined(__FreeBSD__)
 #  define sparc 1
 # endif
 #endif
