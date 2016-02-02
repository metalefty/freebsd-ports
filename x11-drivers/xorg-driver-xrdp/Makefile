# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	xorg-driver-xrdp
PORTVERSION=	b20160202
CATEGORIES=	x11-drivers
DIST_SUBDIR=	xrdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X.Org xrdp driver

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/xorg/xorg-server.h:${PORTSDIR}/x11-servers/xorg-server \
		nasm:${PORTSDIR}/devel/nasm

USES=		libtool:build pkgconfig
USE_XORG=	glproto inputproto presentproto randrproto renderproto resourceproto scrnsaverproto xf86driproto
USE_AUTOTOOLS=	autoconf automake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xorgxrdp:xorgxrdp xrdp
GH_TAGNAME=	a7de845:xorgxrdp a25e5e9
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-I${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/xrdp-${GH_TAGNAME}/xorgxrdp

post-extract:
	${CP} -a ${WRKSRC_xorgxrdp}/ ${WRKSRC}

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
