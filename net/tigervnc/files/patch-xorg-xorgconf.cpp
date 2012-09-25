--- unix/xserver/hw/xfree86/xorgconf.cpp.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/hw/xfree86/xorgconf.cpp	2012-05-27 11:30:43.000000000 +0900
@@ -570,3 +570,11 @@
     InputDevice "Keyboard1" "CoreKeyboard"
 EndSection
 
+ 
+XCOMM  Two experimental extensions are available -- Composite and XEVIE.  Uncomment
+XCOMM  the section below to enable Composite.  Many extensions can also be disabled
+XCOMM  in this manner.
+
+XCOMM Section "Extensions"
+XCOMM 	Option "Composite" "Enable"
+XCOMM EndSection
