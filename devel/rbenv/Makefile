# $FreeBSD$

PORTNAME=	rbenv
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel ruby

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Manage multiple versions of ruby

LICENSE=	MIT

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	rbenv

NO_BUILD=	yes

REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e "s|\$${root}/completions|${DATADIR}/completions|g" ${WRKSRC}/libexec/rbenv-init

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-local-exec ${STAGEDIR}${PREFIX}/bin
	( ${INSTALL_SCRIPT} ${WRKSRC}/libexec/* ${STAGEDIR}${PREFIX}/libexec/ )
	@${LN} -sf ${PREFIX}/libexec/rbenv ${STAGEDIR}${PREFIX}/bin/rbenv
	@${MKDIR} ${STAGEDIR}${DATADIR}/completions
	( cd ${WRKSRC}/completions && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/completions )
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rbenv.d
	( cd ${WRKSRC}/rbenv.d && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/etc/rbenv.d )

.include <bsd.port.mk>
