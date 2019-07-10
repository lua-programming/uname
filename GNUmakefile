CC?=c89
BUILDDIR?=./src
BUILD?=$(BUILDDIR)/*.c
OBJ?=uname.so
ifndef LUA_VERSION
	LUA_VERSION=$(shell /usr/bin/env lua -e "print(({_VERSION:gsub('^%S+%s', '')})[1])")
endif
CFLAGS?=-lgd -fpic -shared -llua$(LUA_VERSION) -I/usr/include/lua$(LUA_VERSION) -Wall
install:
	$(info Compiling for Lua ${LUA_VERSION}...)
	@ $(CC) $(BUILD) -o $(OBJ) $(CFLAGS)
