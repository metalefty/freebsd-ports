diff --git sesman/chansrv/chansrv_fuse.h sesman/chansrv/chansrv_fuse.h
index 0013038..cee49ee 100644
--- sesman/chansrv/chansrv_fuse.h
+++ sesman/chansrv/chansrv_fuse.h
@@ -18,6 +18,7 @@
 
 #ifndef _CHANSRV_FUSE_H
 #define _CHANSRV_FUSE_H
+#include <sys/types.h>
 
 /* a file or dir entry in the xrdp file system */
 struct xrdp_inode
