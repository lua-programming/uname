#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#define GLOBAL_VARIABLE "uname"
static int cfuname(lua_State* L) {
    struct utsname unameData;
    uname(&unameData);
    int options = lua_gettop(L);
    if (options>0) {
        int i;
        int o=0;
        for (i=1; i<=options; i++) {
            const char *arg = luaL_checkstring(L, i);
            if (!strcasecmp(arg, "sysname")) lua_pushstring(L, unameData.sysname);
            else if (!strcasecmp(arg, "nodename")) lua_pushstring(L, unameData.nodename);
            else if (!strcasecmp(arg, "release")) lua_pushstring(L, unameData.release);
            else if (!strcasecmp(arg, "version")) lua_pushstring(L, unameData.version);
            else if (!strcasecmp(arg, "machine")) lua_pushstring(L, unameData.machine);
            else lua_pushnil(L);
            o++;
        }
        return o;
    }
    lua_createtable(L, 0, 5);
    /* sysname */
    lua_pushstring(L, "sysname");
    lua_pushstring(L, unameData.sysname);
    lua_settable(L, -3);
    /* nodename */
    lua_pushstring(L, "nodename");
    lua_pushstring(L, unameData.nodename);
    lua_settable(L, -3);
    /* release */
    lua_pushstring(L, "release");
    lua_pushstring(L, unameData.release);
    lua_settable(L, -3);
    /* version */
    lua_pushstring(L, "version");
    lua_pushstring(L, unameData.version);
    lua_settable(L, -3);
    /* machine */
    lua_pushstring(L, "machine");
    lua_pushstring(L, unameData.machine);
    lua_settable(L, -3);
    return 1;
}
int luaopen_uname(lua_State* L) {
    lua_pushcfunction(L, cfuname);
    lua_setglobal(L, GLOBAL_VARIABLE);
    return 1;
}
