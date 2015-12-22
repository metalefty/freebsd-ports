# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.9.0.b20151211
#PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	net
PKGNAMESUFFIX=	-head
DIST_SUBDIR?=	${PORTNAME}

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf:build libtool pkgconfig
USE_XORG=	x11 xfixes xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xrdp
GH_TAGNAME=	4e0d0f3

CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-jpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
#CONFLICTS=	xrdp-[0-9]*
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG FUSE FREERDP IPV6 OPUS
OPTIONS_DEFAULT=	OPUS
FREERDP_DESC=	Enable FreeRDP support
FUSE_DESC=	Drive redirection via FUSE
OPUS_DESC=	Enable Opus audio codec

IPV6_CONFIGURE_ENABLE=	ipv6
DEBUG_CONFIGURE_ENABLE=	xrdpdebug
FUSE_CONFIGURE_ENABLE=	fuse
FREERDP_BUILD_DEPENDS=	freerdp>=1.2.0:${PORTSDIR}/net/freerdp
FREERDP_CONFIGURE_ENABLE=	freerdp1
OPUS_CONFIGURE_ENABLE=	opus
OPUS_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus

.include <bsd.port.options.mk>

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-stage:
.for f in sesman.ini startwm.sh xrdp.ini xrdp_keyboard.ini
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.mk>
