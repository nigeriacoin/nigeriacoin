#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/nigeriacoin.png
ICON_DST=../../src/qt/res/icons/nigeriacoin.ico
convert ${ICON_SRC} -resize 16x16 nigeriacoin-16.png
convert ${ICON_SRC} -resize 32x32 nigeriacoin-32.png
convert ${ICON_SRC} -resize 48x48 nigeriacoin-48.png
convert nigeriacoin-16.png nigeriacoin-32.png nigeriacoin-48.png ${ICON_DST}

ICON_TESTNET_SRC=../../src/qt/res/icons/nigeriacoin_testnet.png
ICON_TESTNET_DST=../../src/qt/res/icons/nigeriacoin_testnet.ico
convert ${ICON_SRC} -resize 16x16 nigeriacoin_testnet-16.png
convert ${ICON_SRC} -resize 32x32 nigeriacoin_testnet-32.png
convert ${ICON_SRC} -resize 48x48 nigeriacoin_testnet-48.png
convert nigeriacoin_testnet-16.png nigeriacoin_testnet-32.png nigeriacoin_testnet-48.png ${ICON_DST}
