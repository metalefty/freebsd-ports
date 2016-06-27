# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	xorg-driver-xrdp
PORTVERSION=	b20160302
CATEGORIES=	x11-drivers
DIST_SUBDIR=	xrdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X.Org xrdp driver

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/xorg/xorg-server.h:x11-servers/xorg-server \
		nasm:devel/nasm

USES=		libtool:build pkgconfig
USE_XORG=	glproto inputproto presentproto randrproto renderproto resourceproto scrnsaverproto xf86driproto
USE_AUTOTOOLS=	autoconf automake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xorgxrdp:xorgxrdp xrdp
GH_TAGNAME=	68412e5:xorgxrdp 703fedd
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-I${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/xrdp-${GH_TAGNAME}/xorgxrdp

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

post-extract:
	${CP} -a ${WRKSRC_xorgxrdp}/ ${WRKSRC}

post-patch:
.if ${PORT_OPTIONS:MDEBUG}
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|#define LOG_LEVEL [0-9]*|#define LOG_LEVEL 20|'
.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
