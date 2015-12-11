# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=       xorg-driver-rdp
PORTVERSION=	b20150915
CATEGORIES=	x11-drivers
DIST_SUBDIR=	xrdp

MAINTAINER=     meta+ports@vmeta.jp
COMMENT=	RDP driver for Xorg

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/xorg/xorg-server.h:${PORTSDIR}/x11-servers/xorg-server \
		nasm:${PORTSDIR}/devel/nasm

USES=		libtool:build pkgconfig
USE_XORG=	glproto inputproto randrproto renderproto resourceproto scrnsaverproto xf86driproto
USE_AUTOTOOLS=	autoconf automake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xorgxrdp:xorgxrdp xrdp
GH_TAGNAME=	884b347:xorgxrdp f49e205
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-I${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/xrdp-${GH_TAGNAME}/xorgxrdp

post-extract:
	${CP} -a ${WRKSRC_xorgxrdp}/ ${WRKSRC}

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
