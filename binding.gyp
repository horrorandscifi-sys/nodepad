{
  "targets": [{
    "target_name": "server_engine",
    "sources": [ "src/native/engine.cpp" ],
    "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
    "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
    "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
  }]
}
