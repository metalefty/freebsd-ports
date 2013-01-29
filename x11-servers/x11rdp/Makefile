# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	x11rdp
PORTVERSION=	0.5.0.${X11RDPREVISION}
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	x11-servers
MASTER_SITES=	http://www.club.kyutech.ac.jp/~meta/distfiles/:x11rdp \
		http://key2.jp/~meta/distfiles/:x11rdp
DISTNAME=	${PORTNAME}_xorg71
DISTFILES=	${PORTNAME}_xorg71_r${X11RDPREVISION}.tar.gz:x11rdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	An X11 server for net/xrdp, net/xrdp-devel

PLIST_FILES=	bin/X11rdp

# SVN revision of x11rdp
X11RDPREVISION=299

#GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	yes
USE_GCC=	4.2+

GNUMAKE=${GMAKE}

post-extract:
	@${MKDIR} ${WRKSRC}/build

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/buildx.sh

do-build:
	@cd ${WRKSRC} && GNUMAKE=${GMAKE} ${SH} ${WRKSRC}/buildx.sh ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/X11rdp ${PREFIX}/bin/

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
