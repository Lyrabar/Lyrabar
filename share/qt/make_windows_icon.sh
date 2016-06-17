#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/lyrabar.png
ICON_DST=../../src/qt/res/icons/lyrabar.ico
convert ${ICON_SRC} -resize 16x16 lyrabar-16.png
convert ${ICON_SRC} -resize 32x32 lyrabar-32.png
convert ${ICON_SRC} -resize 48x48 lyrabar-48.png
convert lyrabar-16.png lyrabar-32.png lyrabar-48.png ${ICON_DST}
