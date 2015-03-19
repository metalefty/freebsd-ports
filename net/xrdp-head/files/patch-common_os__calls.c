diff --git common/os_calls.c common/os_calls.c
index 1d3a71b..33916e9 100644
--- common/os_calls.c
+++ common/os_calls.c
@@ -86,6 +86,10 @@ extern char **environ;
 #include <linux/unistd.h>
 #endif

+#if defined(BSD)
+#include <sys/ucred.h> /* to use struct xucred */
+#endif
+
 /* for solaris */
 #if !defined(PF_LOCAL)
 #define PF_LOCAL AF_UNIX
@@ -643,6 +647,29 @@ g_sck_get_peer_cred(int sck, int *pid, int *uid, int *gid)
         *gid = credentials.gid;
     }
     return 0;
+#elif defined(LOCAL_PEERCRED)
+    /* FreeBSD */
+    struct xucred xucred;
+    unsigned int xucred_length;
+    xucred_length = sizeof(xucred);
+
+    if (getsockopt(sck, SOL_SOCKET, LOCAL_PEERCRED, &xucred, &xucred_length))
+    {
+            return 1;
+    }
+    if (pid !=0)
+    {
+        /* pid is not defined on FreeBSD's ucred */
+        *pid = 0;
+    }
+    if (uid != 0)
+    {
+        *uid = xucred.cr_uid;
+    }
+    if (gid != 0) {
+        *gid = xucred.cr_gid;
+    }
+    return 0;
 #else
     return 1;
 #endif
