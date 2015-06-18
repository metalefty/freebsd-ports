# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.9.0.b20150618
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
GH_ACCOUNT=	metalefty
GH_PROJECT=	xrdp
GH_TAGNAME=	0f8f03e

CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-jpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
#CONFLICTS=	xrdp-[0-9]*
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
# xrdp v0.7 is not compatible with current net/freerdp (1.0.2)
#BUILD_DEPENDS+=	freerdp>=1.0.2:${PORTSDIR}/net/freerdp
#CONFIGURE_ARGS+=	--enable-freerdp1
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG FUSE IPV6
OPTIONS_DEFAULT=
FUSE_DESC=	Drive redirection via FUSE

IPV6_CONFIGURE_ENABLE=	ipv6
DEBUG_CONFIGURE_ENABLE=	xrdpdebug
FUSE_CONFIGURE_ENABLE=	fuse


.include <bsd.port.options.mk>

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-stage:
.for f in sesman.ini startwm.sh xrdp.ini xrdp_keyboard.ini
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.mk>
