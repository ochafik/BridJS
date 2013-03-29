/*
Load with:

  var bridjs = require('./bridjs')
  var clib = bridjs.lib("c")
*/
function loadPlatformTaggedNativeLibrary(name) {
  //var subPath = name + '/' + process.platform + '_' + process.arch + '/' + name
  //return require('./dist/' + subPath)
  return require('./' + name + '/' + process.platform + '_' + process.arch + '/' + name)
}

var bridjs = loadPlatformTaggedNativeLibrary('bridjs')
var libs = {};

exports.symbols = function(libPath) {
  var symbols = new Array();
  var syms = bridjs.symsInit(libPath);
  try {
    var count = bridjs.symsCount(syms);
    for (var i = 0; i < count; i++) {
      var name = bridjs.symsName(syms, i);
      if (name)
        symbols.push(name);
    }
  } finally {
    bridjs.symsCleanup(syms);
  }
  return symbols;
};

exports.rawBindings = bridjs;
exports.lib = function(name) {
  var lib = libs[name];
  if (!lib) {
    // TODO path stuff
    console.log('TODO: load native library with dynload');
    
    var lib = bridjs.dcLoadLibrary(name);
    var syms = bridjs.dcSymsInit(name);
    
    var functions = {};
    
    lib = libs[name] = {
      close: function() {
        bridjs.dcCloseLibrary(lib);
        bridjs.dcCloseSyms(syms);
      },
      symbols: [ 'TODO' ],
      func: function(name, signature) {
        var f = functions[name];
        if (!f) {
          console.log('TODO: load native library with dynload');
          var pointer = bridjs.dcSymGet(syms, name);
          if (!pointer)
            pointer = bridjs.dcSymGet(syms, '_' + name);
          
          f = functions[name] = function() {
            console.log('TODO: dccall(' + arguments + ')');
          };
        }
        return f;
      }
    };
  }
  return lib;
};


