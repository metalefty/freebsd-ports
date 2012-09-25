--- unix/xserver/os/utils.c.orig	2012-05-27 10:54:18.000000000 +0900
+++ unix/xserver/os/utils.c	2012-05-27 11:20:35.000000000 +0900
@@ -315,7 +315,7 @@
     FatalError("Could not create lock file in %s\n", tmp);
   (void) sprintf(pid_str, "%10ld\n", (long)getpid());
   (void) write(lfd, pid_str, 11);
-  (void) chmod(tmp, 0444);
+  (void) fchmod(tmp, 0444);
   (void) close(lfd);
 
   /*
@@ -336,7 +336,7 @@
       /*
        * Read the pid from the existing file
        */
-      lfd = open(LockFile, O_RDONLY);
+      lfd = open(LockFile, O_RDONLY|O_NOFOLLOW);
       if (lfd < 0) {
         unlink(tmp);
         FatalError("Can't read lock file %s\n", LockFile);
