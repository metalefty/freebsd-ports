# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.9.0.b20161004
PORTEPOCH=	1
CATEGORIES=	net
PKGNAMESUFFIX=	-head
DIST_SUBDIR?=	${PORTNAME}

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

# pulseaudio's built source is required for audio redirection
BUILD_DEPENDS=	${NONEXISTENT}:audio/pulseaudio:build

USES=		autoreconf:build jpeg libtool pkgconfig ssl
USE_XORG=	ice sm x11 xfixes xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xrdp librfxcodec:librfxcodec
GH_TAGNAME=	b24f8d8 3f137a6:librfxcodec

CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-jpeg --enable-rfxcodec
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFLICTS=	xrdp-[0-9]*
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-install pkg-message
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

OPTIONS_DEFINE=	DEBUG FUSE IPV6 MP3LAME OPUS
OPTIONS_DEFAULT=	OPUS MP3LAME
FUSE_DESC=	Enable drive redirection via FUSE (experimental)
MP3LAME_DESC=	Enable MP3 Lame for audio redirection
OPUS_DESC=	Enable Opus for audio redirection

IPV6_CONFIGURE_ENABLE=	ipv6
DEBUG_CONFIGURE_ENABLE=	xrdpdebug
FUSE_CONFIGURE_ENABLE=	fuse
MP3LAME_CONFIGURE_ENABLE=	mp3lame
MP3LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
OPUS_CONFIGURE_ENABLE=	opus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus

# don't forget to increase PORTREVISION after pulseaudio update
PULSE_VERSION=	8.0
PULSE_WRKSRC=	${MAKE} -C ${PORTSDIR}/audio/pulseaudio -VWRKSRC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFUSE}
USES+=	fuse
.endif

post-extract:
	# librfxcodec is provided as git submodule
	@${CP} -r ${WRKSRC_librfxcodec}/ ${WRKSRC}/librfxcodec/

post-patch:
	@${REINPLACE_CMD} \
		-e "s|^security_layer=rdp|security_layer=tls|" \
		-e "s|^autorun=xrdp1|autorun=Session manager|" \
		${WRKSRC}/xrdp/xrdp.ini
	@${REINPLACE_CMD} \
		-e "s|^PULSE_SCRIPT=/etc/xrdp/pulse/default.pa|PULSE_SCRIPT=${PREFIX}/etc/xrdp/pulse/default.pa|" \
		${WRKSRC}/sesman/sesman.ini
	@${REINPLACE_CMD} \
		-e "s|^PULSE_DIR = .*|PULSE_DIR = `${PULSE_WRKSRC}`|" \
		-e "s|-Wall -O2|-Wall -O2 -I${LOCALBASE}/include|" \
		${WRKSRC}/sesman/chansrv/pulse/Makefile

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

pre-build:
	# librfxcodec should be built before xrdp
	@cd ${WRKSRC}/librfxcodec/ && ${MAKE_CMD}

post-build:
	# build pulseaudio module
	@${CP} -r "`${PULSE_WRKSRC}`" ${WRKDIR}
	@cd ${WRKSRC} && ${MAKE_CMD} -C sesman/chansrv/pulse

post-install:
	# install pulseaudio module
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pulse-${PULSE_VERSION}/modules/
.for f in module-xrdp-sink.so module-xrdp-source.so
	${INSTALL_LIB} -m 0755 ${WRKSRC}/sesman/chansrv/pulse/$f \
		${STAGEDIR}${PREFIX}/lib/pulse-${PULSE_VERSION}/modules/
.endfor

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/rsakeys.ini
.for f in sesman.ini startwm.sh xrdp.ini xrdp_keyboard.ini
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.mk>
