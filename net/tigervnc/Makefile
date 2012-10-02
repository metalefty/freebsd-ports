# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	tigervnc
PORTVERSION=	1.2.0
#PORTREVISION=	1
CATEGORIES=	net x11-servers
MASTER_SITES=	SF:1 \
		XORG/individual/xserver:2
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}/:1
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:1 \
		xorg-server-${XORG_VERSION}.tar.bz2:2

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	TigerVNC is a high-performance, platform-neutral implementation of VNC

USE_PKGCONFIG=	build

BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake \
		pkgconf:${PORTSDIR}/devel/pkgconf \
		${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:${PORTSDIR}/graphics/dri

CONFLICTS=	tridiavnc-[0-9]* \
		tightvnc-[0-9]* \
		vnc-[0-9]*

MAKE_JOBS_UNSAFE=	yes

USE_GMAKE=	yes
USE_GL=		gl
USE_AUTOTOOLS+=	autoconf:env automake:env libtool:env
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

USE_XORG+=	bigreqsproto compositeproto damageproto fixesproto fontsproto glproto \
		inputproto kbproto pixman randrproto renderproto resourceproto \
		scrnsaverproto videoproto xau xdmcp xext xkbfile xcmiscproto xextproto \
		xfont xproto xrandr xtrans xtst

WRKSRC=		${WRKDIR}/tigervnc-${PORTVERSION}/

MAN1+=		vncpasswd.1 \
		x0vncserver.1 \
		vncserver.1 \
		vncconfig.1 \
		Xserver.1 \
		Xvnc.1

OPTIONS_DEFINE=		GNUTLS NLS PAM VIEWER HPJPG
OPTIONS_DEFAULT=	VIEWER
GNUTLS_DESC=		GNUTLS support (broken)
PAM_DESC=		PAM authentication support
VIEWER_DESC=		Build vncviewer
HPJPG_DESC=		Build with High-Performance JPEG Support

.include <bsd.port.options.mk>

CMAKE_ARGS=	-G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${PREFIX} -DUSE_INCLUDED_ZLIB=1

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	tasn1:${PORTSDIR}/security/libtasn1 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error
CONFIGURE_ARGS+=	--enable-glx-tls
CMAKE_ARGS+=	-DENABLE_GNUTLS=1
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=0
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CMAKE_ARGS+=	-DENABLE_NLS=1
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=0
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CMAKE_ARGS+=	-DENABLE_PAM=1
.else
CMAKE_ARGS+=	-DENABLE_PAM=0
.endif

.if ${PORT_OPTIONS:MVIEWER}
CMAKE_ARGS+=	-DENABLE_VIEWER=1 -DFLTK_INCLUDE_DIR=${LOCALBASE}/include \
		-DFLTK_LIBRARIES="-L${LOCALBASE}/lib \
		-lfltk -lfltk_forms -lfltk_images"
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		fltk:${PORTSDIR}/x11-toolkits/fltk2
USE_XORG+=	xcursor xfixes xft xinerama
MAN1+=		vncviewer.1
PLIST_SUB+=	VIEWER=""
.else
PLIST_SUB+=	VIEWER="@comment "
.endif

.if ${PORT_OPTIONS:MHPJPG}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libturbojpeg.so:${PORTSDIR}/graphics/libjpeg-turbo
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg
.endif

MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/man/ \
		--docdir=${PREFIX}/share/doc/${PORTNAME}/ --with-pic --without-dtrace \
		--disable-static --disable-dri \
		--disable-xinerama --disable-xvfb --disable-xnest --disable-xorg \
		--disable-dmx --disable-xwin --disable-xephyr --disable-kdrive \
		--disable-config-dbus --disable-config-hal \
		--disable-dri2 --enable-install-libxf86config --enable-glx \
		--with-default-font-path="catalogue:${PREFIX}/share/fonts,built-ins" \
		--with-fontdir=${PREFIX}/share/fonts \
		--with-xkb-path=${PREFIX}/share/X11/xkb \
		--with-xkb-output=/var/lib/xkb \
		--with-xkb-bin-directory=${PREFIX}/bin \
		--with-serverconfig-path=${PREFIX}/lib/X11 \
		--with-dri-driver-path=${PREFIX}/lib/dri \
		--disable-selective-werror

.include <bsd.port.pre.mk>

.if defined(WITH_NEW_XORG)
BROKEN=		does not build with new xorg
XORG_VERSION=	1.10.6
.else
XORG_VERSION=	1.7.7
.endif
TIGERVNC_XORG_PATCH_VER=	17

.if defined(WITH_OPENSSL_PORT)
.warning detected OPENSSL_PORT, build with extra-patch
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-unix_xserver_configure.ac
.endif

post-extract:
	${CP} -R ${WRKDIR}/xorg-server-${XORG_VERSION}/*	${WRKSRC}/unix/xserver/

post-patch:
	@cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver${TIGERVNC_XORG_PATCH_VER}.patch

do-configure:
	@cd ${WRKSRC}			&& ${SETENV} ${CONFIGURE_ENV} cmake ${CMAKE_ARGS} .
	@cd ${WRKSRC}/unix/xserver/	&& ${SETENV} ${CONFIGURE_ENV} ${AUTORECONF} -fiv
	@cd ${WRKSRC}/unix/xserver/	&& ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

post-install:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install

.include <bsd.port.post.mk>
