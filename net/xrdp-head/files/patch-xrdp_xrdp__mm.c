diff --git xrdp/xrdp_mm.c xrdp/xrdp_mm.c
index cd4006f..0dcc35e 100644
--- xrdp/xrdp_mm.c
+++ xrdp/xrdp_mm.c
@@ -23,7 +23,11 @@
 #include "log.h"
 #ifdef ACCESS
 #ifndef USE_NOPAM
+#ifndef __FreeBSD__
 #include "security/_pam_types.h"
+#else
+#include <security/pam_constants.h>
+#endif
 #endif
 #endif
 
@@ -1257,8 +1261,10 @@ getPAMError(const int pamError, char *text, int text_bytes)
             return "Failure setting user credentials";
         case PAM_NO_MODULE_DATA:
             return "No module specific data is present";
+#ifndef __FreeBSD__
         case PAM_BAD_ITEM:
             return "Bad item passed to pam_*_item()";
+#endif
         case PAM_CONV_ERR:
             return "Conversation error";
         case PAM_AUTHTOK_ERR:
@@ -1275,10 +1281,12 @@ getPAMError(const int pamError, char *text, int text_bytes)
             return "Module is unknown";
         case PAM_AUTHTOK_EXPIRED:
             return "Authentication token expired";
+#ifndef __FreeBSD__
         case PAM_CONV_AGAIN:
             return "Conversation is waiting for event";
         case PAM_INCOMPLETE:
             return "Application needs to call libpam again";
+#endif
         case 32 + 1:
             return "Error connecting to PAM";
         case 32 + 3:
@@ -1309,7 +1317,9 @@ getPAMAdditionalErrorInfo(const int pamError, struct xrdp_mm *self)
         case PAM_CRED_UNAVAIL:
         case PAM_CRED_ERR:
         case PAM_NO_MODULE_DATA:
-        case PAM_BAD_ITEM:
+#ifndef __FreeBSD__
+	case PAM_BAD_ITEM:
+#endif
         case PAM_CONV_ERR:
         case PAM_AUTHTOK_ERR:
         case PAM_AUTHTOK_LOCK_BUSY:
@@ -1317,10 +1327,12 @@ getPAMAdditionalErrorInfo(const int pamError, struct xrdp_mm *self)
         case PAM_TRY_AGAIN:
         case PAM_IGNORE:
         case PAM_MODULE_UNKNOWN:
+#ifndef __FreeBSD__
         case PAM_CONV_AGAIN:
         case PAM_INCOMPLETE:
         case _PAM_RETURN_VALUES + 1:
         case _PAM_RETURN_VALUES + 3:
+#endif
             return NULL;
         case PAM_MAXTRIES:
         case PAM_NEW_AUTHTOK_REQD:
