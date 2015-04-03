# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PKGNAMEPREFIX=	ja-uim-

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Mozc engine for uim
DATADIR=	${PREFIX}/share/uim

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
FILESDIR=	${.CURDIR}/files
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

BUILD_MOZC_LIST=	uim_mozc

.include "${MASTERDIR}/Makefile"
