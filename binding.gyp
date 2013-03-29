{
  "targets": [
    {
      'target_name': 'bridjs',
      'sources': [
        'src/dyncallback_v8.cc',
        'src/dynload_v8.cc',
        'src/dyncall_v8.cc',
        'src/dyncall_v8_utils.cc',
        'src/bridjs_module.cc',
        
        'dyncall/dyncall/dynload/dynload.c',
        'dyncall/dyncall/dynload/dynload_syms.c',
        
        'dyncall/dyncall/dyncall/dyncall_vector.c',
        'dyncall/dyncall/dyncall/dyncall_api.c',
        'dyncall/dyncall/dyncall/dyncall_call.S',
        'dyncall/dyncall/dyncall/dyncall_callvm.c',
        'dyncall/dyncall/dyncall/dyncall_callvm_base.c',
        'dyncall/dyncall/dyncall/dyncall_struct.c',
        
        'dyncall/dyncall/dyncallback/dyncall_thunk.c',
        'dyncall/dyncall/dyncallback/dyncall_alloc_wx.c',
        'dyncall/dyncall/dyncallback/dyncall_args.c',
        'dyncall/dyncall/dyncallback/dyncall_callback.c',
        'dyncall/dyncall/dyncallback/dyncall_callback_arch.S',
      ],
      'include_dirs': [
        'dyncall/dyncall/dyncall',
        'dyncall/dyncall/dynload',
        'dyncall/dyncall/dyncallback',
        '/usr/include',
        '/usr/include/sys',
      ],
      'link_settings': {
        'libraries': [
          '-ldl',
          '-lpthread',
          # '/Users/ochafik/Documents/Perso/BridJS/dyncall/lib/libdyncall_s.a',
          # '/Users/ochafik/Documents/Perso/BridJS/dyncall/lib/libdyncallback_s.a',
          # '/Users/ochafik/Documents/Perso/BridJS/dyncall/lib/libdynload_s.a',
        ],
        #'library_dirs': [
        #  '/Users/ochafik/Documents/Perso/BridJS/dyncall/lib/',
        #],
      },
    }
  ]
}
