# $FreeBSD$

PORTNAME=	singular
PORTVERSION=	4.1.1
CATEGORIES=	math
MASTER_SITES=	http://www.mathematik.uni-kl.de/ftp/pub/Math/Singular/SOURCES/4-1-1/

MAINTAINER=	oam_yamada@cc.nara-wu.ac.jp
COMMENT=	Computer algebra system for polynomial computations

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

USES=		gmake libtool ncurses perl5 shebangfix
USE_PERL5=	build
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/libexec/${PORTNAME}/MOD
SHEBANG_FILES=	libsingular-config.in libpolys/libpolys-config.in Singular/surfex

# not a shebang but "/bin/bash" is hardcoded in some files
post-patch:
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" ${WRKSRC}/emacs/.emacs-general

.include <bsd.port.mk>
