--- common/trans.c.orig	2016-01-22 01:59:48 UTC
+++ common/trans.c
@@ -249,18 +249,6 @@ trans_send_waiting(struct trans *self, i
                     }
                 }
             }
-            else if (block)
-            {
-                /* check for term here */
-                if (self->is_term != 0)
-                {
-                    if (self->is_term())
-                    {
-                        /* term */
-                        return 1;
-                    }
-                }
-            }
         }
         else
         {
@@ -424,7 +412,6 @@ trans_check_wait_objs(struct trans *self
 
     return rv;
 }
-
 /*****************************************************************************/
 int APP_CC
 trans_force_read_s(struct trans *self, struct stream *in_s, int size)
@@ -435,6 +422,7 @@ trans_force_read_s(struct trans *self, s
     {
         return 1;
     }
+
     while (size > 0)
     {
         /* make sure stream has room */
@@ -442,47 +430,47 @@ trans_force_read_s(struct trans *self, s
         {
             return 1;
         }
-        if (self->trans_can_recv(self, self->sck, 100))
+
+        rcvd = self->trans_recv(self, in_s->end, size);
+
+        if (rcvd == -1)
         {
-            rcvd = self->trans_recv(self, in_s->end, size);
-            if (rcvd == -1)
+            if (g_tcp_last_error_would_block(self->sck))
             {
-                if (g_tcp_last_error_would_block(self->sck))
-                {
-                }
-                else
+                if (!g_sck_can_recv(self->sck, 100))
                 {
-                    /* error */
-                    self->status = TRANS_STATUS_DOWN;
-                    return 1;
+                    /* check for term here */
+                    if (self->is_term != 0)
+                    {
+                        if (self->is_term())
+                        {
+                            /* term */
+                            self->status = TRANS_STATUS_DOWN;
+                            return 1;
+                        }
+                    }
                 }
             }
-            else if (rcvd == 0)
+            else
             {
                 /* error */
                 self->status = TRANS_STATUS_DOWN;
                 return 1;
             }
-            else
-            {
-                in_s->end += rcvd;
-                size -= rcvd;
-            }
+        }
+        else if (rcvd == 0)
+        {
+            /* error */
+            self->status = TRANS_STATUS_DOWN;
+            return 1;
         }
         else
         {
-            /* check for term here */
-            if (self->is_term != 0)
-            {
-                if (self->is_term())
-                {
-                    /* term */
-                    self->status = TRANS_STATUS_DOWN;
-                    return 1;
-                }
-            }
+            in_s->end += rcvd;
+            size -= rcvd;
         }
     }
+
     return 0;
 }
 
@@ -505,55 +493,57 @@ trans_force_write_s(struct trans *self, 
     {
         return 1;
     }
+
     size = (int) (out_s->end - out_s->data);
     total = 0;
+
     if (trans_send_waiting(self, 1) != 0)
     {
         self->status = TRANS_STATUS_DOWN;
         return 1;
     }
+
     while (total < size)
     {
-        if (g_tcp_can_send(self->sck, 100))
+        sent = self->trans_send(self, out_s->data + total, size - total);
+
+        if (sent == -1)
         {
-            sent = self->trans_send(self, out_s->data + total, size - total);
-            if (sent == -1)
+            if (g_tcp_last_error_would_block(self->sck))
             {
-                if (g_tcp_last_error_would_block(self->sck))
-                {
-                }
-                else
+                if (!g_tcp_can_send(self->sck, 100))
                 {
-                    /* error */
-                    self->status = TRANS_STATUS_DOWN;
-                    return 1;
+                    /* check for term here */
+                    if (self->is_term != 0)
+                    {
+                        if (self->is_term())
+                        {
+                            /* term */
+                            self->status = TRANS_STATUS_DOWN;
+                            return 1;
+                        }
+                    }
                 }
             }
-            else if (sent == 0)
+            else
             {
                 /* error */
                 self->status = TRANS_STATUS_DOWN;
                 return 1;
             }
-            else
-            {
-                total = total + sent;
-            }
+        }
+        else if (sent == 0)
+        {
+            /* error */
+            self->status = TRANS_STATUS_DOWN;
+            return 1;
         }
         else
         {
-            /* check for term here */
-            if (self->is_term != 0)
-            {
-                if (self->is_term())
-                {
-                    /* term */
-                    self->status = TRANS_STATUS_DOWN;
-                    return 1;
-                }
-            }
+            total = total + sent;
         }
     }
+
     return 0;
 }
 
@@ -883,7 +873,6 @@ trans_get_out_s(struct trans *self, int 
 
     return rv;
 }
-
 /*****************************************************************************/
 /* returns error */
 int APP_CC
@@ -909,7 +898,6 @@ trans_set_tls_mode(struct trans *self, c
 
     return 0;
 }
-
 /*****************************************************************************/
 /* returns error */
 int APP_CC
