var assert = require('assert');
var bridjs = require('./bridjs.js');

var libPath = process.cwd() + '/bridjs/' + bridjs.platformTag + '/bridjs.node';
var lib = bridjs.rawBindings.loadLibrary(libPath);
try {
  var symbols = bridjs.symbols(libPath);
  console.log('Found ' + symbols.length + ' symbols');
  assert(
    symbols.length > 10,
    "Didn't find expected symbols in " + libPath)
} finally {
  console.log(bridjs.rawBindings.freeLibrary(lib));
}

