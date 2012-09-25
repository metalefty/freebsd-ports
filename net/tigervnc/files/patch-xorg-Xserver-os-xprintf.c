--- unix/xserver/os/xprintf.c.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/os/xprintf.c	2012-05-27 11:27:35.000000000 +0900
@@ -39,7 +39,7 @@
 # ifdef __va_copy
 #  define va_copy __va_copy
 # else
-#  error "no working va_copy was found"
+#  define va_copy(dest, src) ((dest) = (src))
 # endif
 #endif
     
