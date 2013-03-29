var assert = require('assert');
var bridjs = require('./bridjs.js');

//assert.equal('world', bridjs.rawBindings.hello());
//console.log('bridjs.hello() =', bridjs.rawBindings.hello());

var libPath = '/usr/lib/libdtrace.dylib'
var lib = bridjs.rawBindings.loadLibrary(libPath);

console.log(bridjs.symbols(libPath));
console.log(lib);
console.log(bridjs.rawBindings.freeLibrary(lib));

