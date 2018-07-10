# $FreeBSD$

PORTNAME=	singular
PORTVERSION=	4.1.1	
CATEGORIES=	math
MASTER_SITES=	http://www.mathematik.uni-kl.de/ftp/pub/Math/Singular/SOURCES/4-1-1/
DISTNAME=	singular-4.1.1
EXTRACT_SUFX=	.tar,gz
DISTFILES=	singular-4.1.1.tar.gz

MAINTAINER=	oam_yamada@cc.nara-wu.ac.jp	
COMMENT=	A computer algebra system for polynomial computations

#USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

USES=	perl5
USE_PERL5=	build

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake:install
#NO_INSTALL_MANPAGES=	yes

LICENSE=	GPLv3RLE
LICENSE_FILE=	${WRKSRC}/COPYING

# GNU_CONFIGURE_PREFIX=	${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
