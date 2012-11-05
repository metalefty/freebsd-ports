# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	x11rdp
PORTVERSION=	${XORG_VERSION}
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	x11-servers
MASTER_SITES=	http://server1.xrdp.org/xrdp/:x11rdp \
		XORG/individual/xserver:xorg
#MASTER_SITE_SUBDIR=
#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
DISTNAME=	${PORTNAME}_xorg71
#EXTRACT_SUFX=
DISTFILES=	${PORTNAME}_xorg71.tar.gz:x11rdp \
		xorg-server-${XORG_VERSION}.tar.bz2:xorg
#DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=

#MASTERDIR=	${PORTSDIR}/x11-servers/xorg-server

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X11RDP

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_XORG+=	bigreqsproto compositeproto damageproto fixesproto fontsproto \
		inputproto kbproto randrproto renderproto resourceproto scrnsaverproto \
		xcmiscproto xextproto xineramaproto xproto xtrans 

WRKSRC=	${WRKDIR}/xorg-server-${XORG_VERSION}/

.if defined(WITH_NEW_XORG)
XORG_VERSION=1.10.6
BROKEN=	does not build with new xorg
.else
XORG_VERSION=1.7.7
.endif

# import from x11-servers/xorg-server
WITH_OPENSSL_BASE=yes
.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# # and configure will fail trying to find it. Setting both of those variables to
# # a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=  SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

post-extract:
	${CP} -R ${WRKDIR}/${DISTNAME}/xorg-server-X11R7.1-1.1.0/hw/rdp ${WRKDIR}/xorg-server-${XORG_VERSION}/hw/


.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
