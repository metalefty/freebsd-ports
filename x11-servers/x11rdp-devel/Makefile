# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	x11rdp
PORTVERSION=	0.9.0.b20160902
CATEGORIES=	x11-servers
MASTER_SITES=	https://xrdp.vmeta.jp/pub/xrdp/X11R7.6/:xorg \
		http://server1.xrdp.org/xrdp/X11R7.6/:xorg \
		GH:x11rdp
PKGNAMESUFFIX=	-devel
DISTFILES=	xorg-server-${X11RDP_XORG_VERSION}.tar.bz2:xorg \
		xrdp-${PORTVERSION}.tar.gz:x11rdp
DIST_SUBDIR=	xrdp

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	X11 server for xrdp (develop version)

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/dri
RUN_DEPENDS=	xorg-fonts>=0:x11-fonts/xorg-fonts \
		${LOCALBASE}/share/X11/xkb/rules/base:x11/xkeyboard-config

USES=		gmake perl5 pkgconfig ssl
USE_AUTOTOOLS+=	autoconf:env
USE_GL=		gl
USE_XORG=	damageproto fixesproto fontutil xcmiscproto xtrans bigreqsproto xproto randrproto \
		renderproto xextproto inputproto kbproto fontsproto videoproto compositeproto \
		recordproto scrnsaverproto resourceproto xineramaproto xkbfile xfont xau xdmcp \
		glproto x11 pixman xf86driproto dri2proto xorg-macros xdamage
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xrdp
GH_TAGNAME=	bc37e5a

CONFLICTS_INSTALL=	x11rdp-[0-9]*
PLIST_FILES=	bin/X11rdp
X11RDP_XORG_VERSION=	1.9.3
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}/xorg/X11R7.6/rdp
XORG_WRKSRC=	${WRKDIR}/xorg-server-${X11RDP_XORG_VERSION}
XORG_TMPBASE=	${WRKDIR}/xorg
MAKE_ENV+=	X11RDPBASE=${XORG_TMPBASE}
CONFIGURE_ARGS=	\
		--prefix=${XORG_TMPBASE} \
	       	--enable-static=xorg \
		--disable-dmx \
	       	--without-dtrace \
		--with-dri-driver-path=${LOCALBASE}/lib/dri \
		--with-sha1=libcrypto \
		--with-fontrootdir=${LOCALBASE}/share/fonts \
		--with-xkb-bin-directory=${LOCALBASE}/bin \
		--with-xkb-path=${LOCALBASE}/share/X11/xkb \
		--with-xkb-output=${XORG_TMPBASE}/share

post-extract:
	@${MKDIR} ${WRKSRC}/../build_dir
	@${LN} -s ${WRKDIR}/xorg-server-${X11RDP_XORG_VERSION} ${WRKSRC}/../build_dir

post-patch:
	@${REINPLACE_CMD} -e 's|LIBBASE = $$(X11RDPBASE)/lib|LIBBASE = ${LOCALBASE}/lib|' \
			  -e 's|-ldl ||' \
			  -e 's|-I../../include|-I${LOCALBASE}/include -I$$(XSRCBASE)/include|' \
			  -e 's|-I../../cfb||' \
			  -e 's|-I../../mfb|-I$$(XSRCBASE)/fb|' \
			  -e 's|-I../../mi|-I$$(XSRCBASE)/mi -I$$(XSRCBASE)/Xext|' \
			  -e 's|-I../../render|-I$$(XSRCBASE)/render|' \
			  -e 's|-I../../randr|-I$$(XSRCBASE)/randr|' \
			  -e 's|-I$$(INCBASE)/X11/fonts|-I${LOCALBASE}/include/X11/fonts|' \
			  -e 's|-I$$(INCBASE)/X11/extensions|-I${LOCALBASE}/include/X11/extensions|' \
			  -e 's|-I$$(INCBASE)/xorg|-I$$(INCBASE)/xorg -I${LOCALBASE}/include/xorg|' \
			  -e 's|-I$$(INCBASE)/pixman-1|-I${LOCALBASE}/include/pixman-1|' \
			  -e 's|-I$$(INCBASE)/X11|-I${LOCALBASE}/include/X11|' \
			  -e 's|-D_POSIX_C_SOURCE=199309L ||' \
			  -e 's|-D_POSIX_SOURCE ||' ${WRKSRC}/Makefile

# confiure xorg-server-1.9.3
post-configure:
	@cd ${XORG_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${AUTORECONF} -fiv
	@cd ${XORG_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ./configure ${CONFIGURE_ARGS}

# build & install xorg into working directory
pre-build:
	@cd ${XORG_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS}
	@cd ${XORG_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} install

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/X11rdp ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
