# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.9.0.b20150313
#PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	GH
PKGNAMESUFFIX=	-head
DIST_SUBDIR?=	${PORTNAME}

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	APACHE20

USES=		autoreconf:build libtool pkgconfig
USE_XORG=	x11 xfixes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_GITHUB=	yes
GH_ACCOUNT=	metalefty
GH_PROJECT=	xrdp
GH_COMMIT=	1f77acc
GH_TAGNAME=	${GH_COMMIT}

CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-jpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFLICTS=	xrdp-[0-9]*
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
# xrdp v0.7 is not compatible with current net/freerdp (1.0.2)
#BUILD_DEPENDS+=	freerdp>=1.0.2:${PORTSDIR}/net/freerdp
#CONFIGURE_ARGS+=	--enable-freerdp1
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG SOUND FUSE
OPTIONS_DEFAULT=	TIGERVNC
OPTIONS_RADIO=	XVNC
OPTIONS_RADIO_XVNC=	REALVNC TIGERVNC TIGHTVNC TRIDIAVNC
REALVNC_DESC=	Use RealVNC
TIGERVNC_DESC=	Use TigerVNC (recommended)
TIGHTVNC_DESC=	Use TightVNC
TRIDIAVNC_DESC=	Use TridiaVNC
SOUND_DESC=	Enable sound support via pulseaudio (experimental)
FUSE_DESC=	Drive redirection via FUSE

.include <bsd.port.options.mk>

# Which Xserver to use
.if ${PORT_OPTIONS:MREALVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/vnc
.endif
.if ${PORT_OPTIONS:MTIGERVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tigervnc
.endif
.if ${PORT_OPTIONS:MTIGHTVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tightvnc
.endif
.if ${PORT_OPTIONS:MTRIDIAVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tridiavnc
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-xrdpdebug
CFLAGS+=	-DXRDP_DEBUG
.endif

.if ${PORT_OPTIONS:MSOUND}
#BUILD_DEPENDS+=	${LOCALBASE}/include/pulse/simple.h:${PORTSDIR}/audio/pulseaudio \
#		${LOCALBASE}/include/pulse/error.h:${PORTSDIR}/audio/pulseaudio
#CONFIGURE_ARGS+=	--enable-simplesound
.endif

.if ${PORT_OPTIONS:MFUSE}
BROKEN=	FUSE is not working for now.
CPPFLAGS+=	-I${LOCALBASE}/include/fuse -DFUSE_USE_VERSION=26
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/fuse
BUILD_DEPENDS+=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs
CONFIGURE_ARGS+=	--enable-fuse
.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-stage:
.for f in sesman.ini startwm.sh xrdp.ini xrdp_keyboard.ini
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.mk>
