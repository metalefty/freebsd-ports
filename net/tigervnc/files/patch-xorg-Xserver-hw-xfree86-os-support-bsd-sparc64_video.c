--- unix/xserver/hw/xfree86/os-support/bsd/sparc64_video.c.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/hw/xfree86/os-support/bsd/sparc64_video.c	2012-05-27 11:26:35.000000000 +0900
@@ -52,6 +52,10 @@
 	pVidMem->mapMem = sparc64MapVidMem;
 	pVidMem->unmapMem = sparc64UnmapVidMem;
 	pVidMem->initialised = TRUE;
+
+#if defined(__FreeBSD__)
+	pci_system_init_dev_mem(xf86Info.screenFd);
+#endif
 }
 
 static pointer
