# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	identity_smtp
PORTVERSION=	20160603
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Roundcube plugin to setup different SMTP settings per identity

LICENSE=	MIT

RUN_DEPENDS=	roundcube>=1.0:mail/roundcube
BUILD_DEPENDS=	roundcube>=1.0:mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	elm
GH_PROJECT=	Roundcube-SMTP-per-Identity-Plugin
GH_TAGNAME=	b700011

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
