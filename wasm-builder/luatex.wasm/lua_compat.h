// lua_compat.h - Compatibility layer for older Lua extensions
#ifndef LUA_COMPAT_H
#define LUA_COMPAT_H

#include <lua.h>
#include <lauxlib.h>
#include <lua_compat.h>

// Compatibility function for luaL_openlib (removed in Lua 5.2+)
#ifndef LUA_COMPAT_OPENLIB
static void luaL_openlib(lua_State *L, const char *libname, const luaL_Reg *l, int nup) {
    if (libname) {
        luaL_newlib(L, l);
        lua_setglobal(L, libname);
    } else {
        luaL_setfuncs(L, l, nup);
    }
}
#endif

// Other compatibility definitions if needed
#ifndef LUA_COMPAT_MODULE
#define LUA_COMPAT_MODULE
#endif

#endif // LUA_COMPAT_H