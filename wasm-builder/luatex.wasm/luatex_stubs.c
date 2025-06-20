#include "lua.h"
#include "lauxlib.h"

// dummy stub modules for WebAssembly

int luaopen_md5(lua_State *L) {
    return luaL_error(L, "md5 module not supported in WebAssembly");
}

int luaopen_sha2(lua_State *L) {
    return luaL_error(L, "sha2 module not supported in WebAssembly");
}

int luaopen_ffi(lua_State *L) {
    return luaL_error(L, "ffi module not supported in WebAssembly");
}

int luaopen_zlib(lua_State *L) {
    return luaL_error(L, "zlib module not supported in WebAssembly");
}

int luaopen_gzip(lua_State *L) {
    return luaL_error(L, "gzip module not supported in WebAssembly");
}
