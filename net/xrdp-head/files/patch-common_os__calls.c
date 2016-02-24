--- common/os_calls.c.orig	2016-02-15 08:59:39 UTC
+++ common/os_calls.c
@@ -683,8 +683,18 @@ g_tcp_connect(int sck, const char *addre
     */
     p.ai_socktype = SOCK_STREAM;
     p.ai_protocol = IPPROTO_TCP;
-    p.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED;
     p.ai_family = AF_INET6;
+#if __FreeBSD__ && !(AI_MASK & AI_V4MAPPED)
+    /**
+     * In FreeBSD, AI_V4MAPPED is supported since Dec 25, 2016.
+     * https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198092
+     *
+     * Do not use AI_V4MAPPED if it is not supported.
+     */
+    p.ai_flags = AI_ADDRCONFIG;
+#else
+    p.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED;
+#endif
     if (g_strcmp(address, "127.0.0.1") == 0)
     {
         res = getaddrinfo("::1", port, &p, &h);
