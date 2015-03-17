diff --git rdpup.c rdpup.c
index f25b390..b17a7da 100644
--- rdpup.c
+++ rdpup.c
@@ -34,7 +34,7 @@ CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 #define LLOGLN(_level, _args) \
     do { if (_level < LOG_LEVEL) { ErrorF _args ; ErrorF("\n"); } } while (0)
 
-static int g_use_shmem = 1; /* turns on or off */
+static int g_use_shmem = 0; /* turns on or off */
 static int g_shmemid = 0;
 static char *g_shmemptr = 0;
 static int g_shmem_lineBytes = 0;
