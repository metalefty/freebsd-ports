# New ports collection makefile for:	freerdp
# Date created:				04 July 2010
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD: ports/net/freerdp/Makefile,v 1.7 2012/06/01 05:22:50 dinoex Exp $
#

PORTNAME=	freerdp
PORTNAMESUFFIX=	devel
PORTVERSION=	1.0.1
CATEGORIES=	net comms ipv6
MASTER_SITES=	GH

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A free remote desktop protocol client

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
#USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	FreeRDP
GH_COMMIT=	8e62721
GH_TAGNAME=	${GH_COMMIT}
USE_CMAKE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	ALSA CUPS FFMPEG PULSE SSE2
OPTIONS_DEFAULT=	SSE2
CUPS_DESC=	Enable printer support via CUPS
FFMPEG_DESC=	ffmpeg
PULSE_DESC=	pulseaudio
SSE2_DESC=	Enable SSE2 optimization

.include <bsd.port.options.mk>

#.if !defined(WITHOUT_IPV6)
#CONFIGURE_ARGS+=--enable-ipv6
#.else
#CONFIGURE_ARGS+=--disable-ipv6
#.endif

#.if !defined(WITHOUT_ICONV)
#USE_ICONV=	yes
#CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}
#.else
#CONFIGURE_ARGS+=--disable-iconv
#.endif

.if defined(WITHOUT_X11)
CMAKE_ARGS+=	-DWITH_X11=OFF
.else
USE_XORG=	x11 xcursor xextproto xv xinerama xext xcursor
CMAKE_ARGS+=	-DWITH_X11=ON
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto
MAN1=		xfreerdp.1
PLIST_SUB+=	X11=""
.endif

.if ${PORT_OPTIONS:MALSA}
.else
CMAKE_ARGS+=	-DWITH_ALSA=OFF
.endif

.if ${PORT_OPTIONS:MFFMPEG}
.else
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
.endif

.if ${PORT_OPTIONS:MCUPS}
CMAKE_ARGS+=	-DWITH_CUPS=ON
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-base
.else
CMAKE_ARGS+=	-DWITH_CUPS=OFF
.endif

.if ${PORT_OPTIONS:MSSE2}
CMAKE_ARGS+=	-DWITH_SSE2=ON
.else
CMAKE_ARGS+=	-DWITH_SSE2=OFF
.endif

#.if !defined(WITHOUT_SOUND)
#CONFIGURE_ARGS+=--with-sound=alsa
#LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
#PLIST_SUB+=	SOUND=""
#.if !defined(WITHOUT_SAMPLERATE)
#LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
#.else
#CONFIGURE_ARGS+=--without-libsamplerate
#.endif
#.else
#CONFIGURE_ARGS+=--with-sound=no
#PLIST_SUB+=	SOUND="@comment "
#.endif

post-patch:
#.if defined(WITHOUT_X11)
#	@${REINPLACE_CMD} -e 's|man_MANS = |man_MANS1 = |g' ${WRKSRC}/doc/Makefile.in
#.endif
#	@${REINPLACE_CMD} -e 's|-ldl -lpthread|${PTHREAD_LIBS}|' \
#		${WRKSRC}/libfreerdpchanman/Makefile.in
#	@${REINPLACE_CMD} -e 's|-I$$(top_builddir)|-I$$(top_builddir)/include|' \
#		${WRKSRC}/libfreerdp/Makefile.in ${WRKSRC}/libfreerdpgdi/Makefile.in \
#		${WRKSRC}/libfreerdpkbd/Makefile.in ${WRKSRC}/X11/Makefile.in

.include <bsd.port.mk>
