# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	mecab-ipadic
DISTVERSION=	2.7.0-20070801
CATEGORIES=	japanese textproc
PKGNAMEPREFIX=	ja-

MAINTAINER=	yasu@utahime.org
COMMENT=	The "meta-port" of MeCab IPA dictionary

USES=	metaport
OPTIONS_RADIO=	CHARSET
OPTIONS_RADIO_CHARSET=	EUCJP SHIFTJIS UTF8
OPTIONS_DEFAULT=	UTF8

EUCJP_DESC=	Use EUC-JP as dictionary charset.
SHIFTJIS_DESC=	Use SHIFT-JIS as dictionary charset.
UTF8_DESC=	Use UTF-8 as dictionary charset.
EUCJP_RUN_DEPENDS=	${LOCALBASE}/lib/mecab/dic/ipadic/char.bin:${.CURDIR}/../mecab-ipadic-eucjp
SHIFTJIS_RUN_DEPENDS=	${LOCALBASE}/lib/mecab/dic/ipadic/char.bin:${.CURDIR}/../mecab-ipadic-sjis
UTF8_RUN_DEPENDS=	${LOCALBASE}/lib/mecab/dic/ipadic/char.bin:${.CURDIR}/../mecab-ipadic-utf8

do-install:	# empty

.include <bsd.port.mk>
