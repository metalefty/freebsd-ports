# New ports collection makefile for:	tigervnc
# Date created:				2012-05-27
# Whom:					bompopo <bompopo@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tigervnc
PORTVERSION=	1.2.0
#PORTREVISION=	1
CATEGORIES=	net x11-servers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}:1 \
		${MASTER_SITE_XORG}:2
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}/:1 \
		releases/individual/xserver:2
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:1 \
		xorg-server-${XORG_VERSION}.tar.bz2:2

MAINTAINER=	bompopo@gmail.com
COMMENT=	TigerVNC is a high-performance, platform-neutral implementation of VNC

USE_PKGCONFIG=	build

BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake \
		pkgconf:${PORTSDIR}/devel/pkgconf \
		${LOCALBASE}/lib/libturbojpeg.so:${PORTSDIR}/graphics/libjpeg-turbo \
		${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:${PORTSDIR}/graphics/dri

CONFLICTS=	tridiavnc-[0-9]* \
		tightvnc-[0-9]* \
		vnc-[0-9]*

OPTIONS=	GNUTLS "GNUTLS support" off \
		NLS "native language support" off \
		OPENSSL_PORT "Use ports openssl" off \
		PAM "PAM authentication support" off \
		VIEWER "build vncviewer" off

.include <bsd.port.options.mk>

CMAKE_ARGS=	-G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${PREFIX} -DUSE_INCLUDED_ZLIB=1

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	tasn:${PORTSDIR}/security/libtasn1 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error
CONFIGURE_ARGS+=	--enable-glx-tls
CMAKE_ARGS+=	-DENABLE_GNUTLS=1
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=0
.endif

.if defined(WITH_NLS) && !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CMAKE_ARGS+=	-DENABLE_NLS=1
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=0
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_OPENSSL_PORT)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-unix_xserver_configure.ac
.endif

.if defined(WITH_PAM)
CMAKE_ARGS+=	-DENABLE_PAM=1
.else
CMAKE_ARGS+=	-DENABLE_PAM=0
.endif

.if !defined(WITHOUT_VIEWER)
CMAKE_ARGS+=	-DENABLE_VIEWER=1 -DFLTK_INCLUDE_DIR=${LOCALBASE}/include -DFLTK_LIBRARIES="-L${LOCALBASE}/lib -lfltk -lfltk_forms -lfltk_images"
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		fltk:${PORTSDIR}/x11-toolkits/fltk
USE_XORG+=	xcursor xfixes xft xinerama
MAN1+=		vncviewer.1
PLIST_SUB+=	VIEWER=""
.else
PLIST_SUB+=	VIEWER="@comment "
.endif

MAKE_JOBS_UNSAFE=	yes

USE_GMAKE=	yes
USE_GL=		gl
USE_AUTOTOOLS+=	autoconf:env \
		automake:env \
		libtool:env
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/man/ --docdir=${PREFIX}/share/doc/${PORTNAME}/ --with-pic --without-dtrace --disable-static --disable-dri \
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

XORG_VERSION=	1.7.7
TIGERVNC_XORG_PATCH_VER=	17

USE_XORG+=	bigreqsproto compositeproto damageproto fixesproto fontsproto glproto \
		inputproto kbproto pixman randrproto renderproto resourceproto \
		scrnsaverproto videoproto xau xdmcp xkbfile xcmiscproto xextproto \
		xfont xproto xtrans

WRKSRC=		${WRKDIR}/tigervnc-${PORTVERSION}/

MAN1+=		vncpasswd.1 \
		x0vncserver.1 \
		vncserver.1 \
		vncconfig.1 \
		Xserver.1 \
		Xvnc.1

.include <bsd.port.pre.mk>

post-extract:
	${CP} -R ${WRKDIR}/xorg-server-${XORG_VERSION}/*	${WRKSRC}/unix/xserver

post-patch:
	@cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver${TIGERVNC_XORG_PATCH_VER}.patch

do-configure:
	@cd ${WRKSRC}			&& ${SETENV} ${CONFIGURE_ENV} cmake ${CMAKE_ARGS} .
	@cd ${WRKSRC}/unix/xserver/	&& ${SETENV} ${CONFIGURE_ENV} ${AUTORECONF} -fiv
	@cd ${WRKSRC}/unix/xserver/	&& ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

post-install:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install

.include <bsd.port.post.mk>
