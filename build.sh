#!/bin/bash

set -e

export OPTIMIZE="-O3"

mkdir -p dist

echo "1/1 compiling tiny-exif"
(
  emcc \
    --bind \
    ${OPTIMIZE} \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s MODULARIZE=1 \
    -s ASSERTIONS=0 \
    -DNDEBUG \
    -s 'MALLOC="emmalloc"' \
    -s 'EXPORT_NAME="easyexif"' \
    -I node_modules/easyexif \
    -o dist/easyexif.js \
    -Wno-deprecated-register \
    -Wno-writable-strings \
    --closure 1 \
    --llvm-lto 1 \
    -x c++ -std=c++11 \
    src/easyexif.cpp
)

echo "DONE!"

echo "Run \`docker pull trzeci/emscripten\` to get latest docker image"
