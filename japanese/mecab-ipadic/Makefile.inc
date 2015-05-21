# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	mecab-ipadic
DISTVERSION=	2.7.0-20070801
CATEGORIES=	japanese textproc
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	mecab

MAINTAINER=	yasu@utahime.org
COMMENT=	Japanese Morphological Dictionary for MeCab

LICENSE=	NAIST ICOT
LICENSE_COMB=	multi
LICENSE_NAME_NAIST=	NAIST
LICENSE_NAME_ICOT=	ICOT
LICENSE_FILE_NAIST=	${WRKSRC}/COPYING
LICENSE_FILE_ICOT=	${WRKSRC}/COPYING
LICENSE_PERMS_NAIST=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ICOT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ja-mecab>=0.94:${PORTSDIR}/japanese/mecab

USES=			perl5
USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-dicdir=${PREFIX}/lib/mecab/dic/ipadic
PLIST_FILES= \
	lib/mecab/dic/ipadic/char.bin \
	lib/mecab/dic/ipadic/dicrc \
	lib/mecab/dic/ipadic/left-id.def \
	lib/mecab/dic/ipadic/matrix.bin \
	lib/mecab/dic/ipadic/pos-id.def \
	lib/mecab/dic/ipadic/rewrite.def \
	lib/mecab/dic/ipadic/right-id.def \
	lib/mecab/dic/ipadic/sys.dic \
	lib/mecab/dic/ipadic/unk.dic

.if ${PKGNAMESUFFIX:S,-,,} == "eucjp"
CONFIGURE_ARGS+=	--with-charset=euc-jp
CONFLICTS=	ja-mecab-ipadic-utf8-[0-9]* ja-mecab-ipadic-sjis-[0-9]*
.elif ${PKGNAMESUFFIX:S,-,,} == "sjis"
CONFIGURE_ARGS+=	--with-charset=shift_jis
CONFLICTS=	ja-mecab-ipadic-eucjp-[0-9]* ja-mecab-ipadic-utf8-[0-9]*
.elif ${PKGNAMESUFFIX:S,-,,} == "utf8"
CONFIGURE_ARGS+=	--with-charset=utf-8
CONFLICTS=	ja-mecab-ipadic-eucjp-[0-9]* ja-mecab-ipadic-sjis-[0-9]*
.endif

.include <bsd.port.mk>
