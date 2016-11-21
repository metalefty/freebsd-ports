# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	xorgxrdp
PORTVERSION=	b20161121
CATEGORIES=	x11-drivers
DIST_SUBDIR=	xrdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X.Org driver enabling use through an RDP session with xrdp

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/xorg/xorg-server.h:x11-servers/xorg-server \
		nasm:devel/nasm

USES=		autoreconf libtool:build pkgconfig
USE_XORG=	glproto inputproto presentproto randrproto renderproto resourceproto scrnsaverproto xf86driproto
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xorgxrdp xrdp:xrdp
GH_TAGNAME=	52319ec 7cc1dd2:xrdp
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-I${LOCALBASE}/lib
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${WRKSRC_xrdp}/pkgconfig

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|@VERSION@|0.9.0|g' -e "s|@abs_top_srcdir|${WRKSRC_xrdp}|g" \
	${WRKSRC_xrdp}/pkgconfig/xrdp-uninstalled.pc.in >> ${WRKSRC_xrdp}/pkgconfig/xrdp-uninstalled.pc
.if ${PORT_OPTIONS:MDEBUG}
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|#define LOG_LEVEL [0-9]*|#define LOG_LEVEL 20|'
.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
