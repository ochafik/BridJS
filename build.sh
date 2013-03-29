#!/bin/bash

MODULE_NAME=bridjs

function require {
  PGM="$1"
  if ! which "$PGM" > /dev/null ; then
    echo "Program '$PGM' not found"
    if [[ -n "$2" ]]; then
      echo "$2"
      exit 1
    fi
  fi
}

require node "Install it from:
  http://nodejs.org/"
require python
require make
require jar
require svn
require node-gyp "Install it with:
  sudo npm install -g node-gyp"

PLATFORM_TAG=`node -e "console.log(process.platform + '_' + process.arch)"`

set -e

cd $(dirname $0)

ROOT=$PWD
PLATFORM_ROOT=./lib/$MODULE_NAME/$PLATFORM_TAG
PLATFORMS_FILE=./lib/$MODULE_NAME/platforms

if [[ ! -d dyncall ]]; then
  svn co https://dyncall.org/svn/dyncall/trunk dyncall
  if [[ -f dyncall.diff ]]; then
    patch -i dyncall.diff -N -p0 || ( rm -fR dyncall ; echo "Patch failed, deleted dyncall" ; exit 1 )
  fi
else
  cd dyncall
  svn diff > ../dyncall.diff
  cd ..
fi
[[ -d build ]] || mkdir build
[[ -d $PLATFORM_ROOT ]] || mkdir -p $PLATFORM_ROOT
[[ -f $PLATFORMS_FILE ]] || touch $PLATFORMS_FILE

OLD_PLATFORMS=`cat $PLATFORMS_FILE`
PLATFORMS=`echo "$OLD_PLATFORMS
$PLATFORM_TAG" | sort | uniq | grep .`
echo "$PLATFORMS" > $PLATFORMS_FILE

if [[ "$DEBUG" == "1" ]]; then
  NODE_GYP_ARGS="--debug"
  BUILD_DIR=build/Debug
else
  NODE_GYP_ARGS=""
  BUILD_DIR=build/Release
fi

[[ -f build/Makefile ]] || node-gyp configure $NODE_GYP_ARGS
node-gyp build $NODE_GYP_ARGS

MODULE_PATH=$PLATFORM_ROOT/$MODULE_NAME
mv -f $BUILD_DIR/$MODULE_NAME.node $MODULE_PATH.node

node -e "require('$MODULE_PATH')"

cd $ROOT/lib
  
for TEST in $ROOT/lib/*_test.js ; do
  echo "Testing $TEST"
  node $TEST
done

#node -e "require('./dist/$MODULE_NAME/' + process.platform + '_' + process.arch + '/$MODULE_NAME')"

jar -cfM ../build/$MODULE_NAME.zip $MODULE_NAME.js $MODULE_NAME

unzip -l ../build/$MODULE_NAME.zip
