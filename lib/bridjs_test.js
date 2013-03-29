var assert = require('assert');
var bridjs = require('./bridjs.js');

//assert.equal('world', bridjs.rawBindings.hello());
//console.log('bridjs.hello() =', bridjs.rawBindings.hello());

//var libPath = '/usr/lib/libc.dylib';
var libPath = '/Users/ochafik/Documents/Perso/nativelibs4java/libraries/BridJ/src/main/resources/org/bridj/lib/darwin_universal/libbridj.dylib';
//var libPath = '/Users/ochafik/Documents/Perso/BridJS/lib/bridjs/darwin_x64/bridjs.node';
var lib = bridjs.rawBindings.loadLibrary(libPath);

console.log(bridjs.symbols(libPath));
console.log(lib);
console.log(bridjs.rawBindings.freeLibrary(lib));

