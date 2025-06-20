PROJECT_NAME	:=	neoluatex.js

CC          	= 	emcc
CXX          	= 	em++
CFLAGS       	= 	-O3 \
					-s USE_ZLIB=1 -s USE_LIBPNG=1 \
					-s USE_FREETYPE=1 -s USE_HARFBUZZ=1 \
					-Wno-parentheses-equality -Wno-pointer-sign \
					-Wno-implicit-function-declaration \
					-fno-rtti -fno-exceptions \
					-DWEBASSEMBLY_BUILD \
					-DLUATEX_BUILD \
					-DKPATHSEA_EMULATED \
					-DLUA_COMPAT_OPENLIB \
					-I. \
					-I./luatex/source/texk/web2c \
					-I./luatex/source/texk/web2c/luatexdir \
					-I./luatex/source/texk/web2c/luatexdir/tex \
					-I./luatex/source/texk/web2c/luatexdir/lua \
					-I./luatex/source/texk/web2c/luatexdir/pdf \
					-I./luatex/source/texk/web2c/luatexdir/font \
					-I./luatex/source/texk/web2c/luatexdir/image \
					-I./luatex/source/texk/web2c/luatexdir/lang \
					-I./luatex/source/texk/web2c/luatexdir/utils \
					-I./luatex/source/libs/lua53/src \
					-I./luatex/source/libs/lua53/include \
					-I. \
					-I./kpathsea \
					-I./luatex/source/texk/kpathsea \
					-I./luatex/source/texk/web2c/kpathsea \
					-I./luatex/source/libs/freetype2/freetype-src/include \
					-O2 -fno-lto -fno-inline -fvisibility=default

CXX_LINK     	= 	$(CXX) $(CFLAGS) -o $@

# Logging settings
LOG_DIR         = logs
BUILD_LOG       = $(LOG_DIR)/build.log
ERROR_LOG       = $(LOG_DIR)/errors.log
PROGRESS_LOG    = $(LOG_DIR)/progress.log

# Use wildcards to collect all C sources from web2c tree
WEB2C_SOURCES   = 	$(wildcard luatex/source/texk/web2c/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/tex/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/lua/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/pdf/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/font/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/image/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/lang/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/utils/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/luapeg/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/luafilesystem/src/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/luamd5/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/luasocket/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/luazlib/*.c) \
					$(wildcard luatex/source/texk/web2c/luatexdir/luaffi/*.c)

# Filter out any files that might conflict or aren't needed
EXCLUDE_SOURCES = 	luatex/source/texk/web2c/luatexdir/luatex-web2c.c \
					luatex/source/texk/web2c/luatexdir/luatex-pool.c \
					$(wildcard luatex/source/texk/web2c/*test*.c) \
					$(wildcard luatex/source/texk/web2c/*main*.c)

# Remove excluded files from the source list
FILTERED_WEB2C_SOURCES = $(filter-out $(EXCLUDE_SOURCES),$(WEB2C_SOURCES))

# Lua 5.3 sources
LUA_SOURCES     = 	luatex/source/libs/lua53/lapi.c \
					luatex/source/libs/lua53/lcode.c \
					luatex/source/libs/lua53/lctype.c \
					luatex/source/libs/lua53/ldebug.c \
					luatex/source/libs/lua53/ldo.c \
					luatex/source/libs/lua53/ldump.c \
					luatex/source/libs/lua53/lfunc.c \
					luatex/source/libs/lua53/lgc.c \
					luatex/source/libs/lua53/llex.c \
					luatex/source/libs/lua53/lmem.c \
					luatex/source/libs/lua53/lobject.c \
					luatex/source/libs/lua53/lopcodes.c \
					luatex/source/libs/lua53/lparser.c \
					luatex/source/libs/lua53/lstate.c \
					luatex/source/libs/lua53/lstring.c \
					luatex/source/libs/lua53/ltable.c \
					luatex/source/libs/lua53/ltm.c \
					luatex/source/libs/lua53/lundump.c \
					luatex/source/libs/lua53/lvm.c \
					luatex/source/libs/lua53/lzio.c \
					luatex/source/libs/lua53/lauxlib.c \
					luatex/source/libs/lua53/lbaselib.c \
					luatex/source/libs/lua53/lbitlib.c \
					luatex/source/libs/lua53/lcorolib.c \
					luatex/source/libs/lua53/ldblib.c \
					luatex/source/libs/lua53/liolib.c \
					luatex/source/libs/lua53/lmathlib.c \
					luatex/source/libs/lua53/loslib.c \
					luatex/source/libs/lua53/lstrlib.c \
					luatex/source/libs/lua53/ltablib.c \
					luatex/source/libs/lua53/lutf8lib.c \
					luatex/source/libs/lua53/loadlib.c \
					luatex/source/libs/lua53/linit.c

# Support sources
SUPPORT_SOURCES = 	main.c \
					kpseemu.c \
					texfile.c \
					xmemory.c \
					luatex/source/libs/freetype2/freetype-src/src/base/md5.c

BUILD_DIR    	=	build

WEB2C_OBJECTS   = 	$(FILTERED_WEB2C_SOURCES:%.c=$(BUILD_DIR)/%.o)
LUA_OBJECTS     = 	$(LUA_SOURCES:%.c=$(BUILD_DIR)/%.o)
SUPPORT_OBJECTS = 	$(SUPPORT_SOURCES:%.c=$(BUILD_DIR)/%.o)

# Progress tracking
TOTAL_OBJECTS = $(words $(WEB2C_OBJECTS) $(LUA_OBJECTS) $(SUPPORT_OBJECTS))
CURRENT_COUNT = 0

_default:
	@$(MAKE) all --no-print-directory -j

all: setup-logs $(PROJECT_NAME)

# Setup logging directories
setup-logs:
	@mkdir -p $(LOG_DIR)
	@echo "=== Build started at $$(date) ===" > $(BUILD_LOG)
	@echo "=== Build started at $$(date) ===" > $(PROGRESS_LOG)
	@echo "Total files to compile: $(TOTAL_OBJECTS)" | tee -a $(BUILD_LOG) $(PROGRESS_LOG)

# Show what sources we're building (for debugging)
show-sources:
	@echo "Web2C sources ($(words $(FILTERED_WEB2C_SOURCES)) files):"
	@echo "$(FILTERED_WEB2C_SOURCES)" | tr ' ' '\n' | sort
	@echo ""
	@echo "Excluded sources:"
	@echo "$(EXCLUDE_SOURCES)" | tr ' ' '\n' | sort

$(PROJECT_NAME): $(WEB2C_OBJECTS) $(LUA_OBJECTS) $(SUPPORT_OBJECTS)
	@echo "=== Linking $(PROJECT_NAME) ===" | tee -a $(BUILD_LOG)
	@$(CXX_LINK) $^ \
	    luatex/source/texk/kpathsea/libkpathsea.a \
	    --js-library library.js --pre-js pre.js \
	-s EXPORTED_FUNCTIONS='["_main", "_kpse_program_basename", "_compileLuaLaTeX", "_compileLuaFormat"]' \
	-s EXPORTED_RUNTIME_METHODS=["cwrap"] \
	-s NO_EXIT_RUNTIME=1 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s TOTAL_MEMORY=134217728 \
	-s ERROR_ON_UNDEFINED_SYMBOLS=0 \
	-s WARN_ON_UNDEFINED_SYMBOLS=1 2>&1 | tee -a $(BUILD_LOG) && \
	{ echo -e "\033[32m[DONE]\033[0m $(PROJECT_NAME)" | tee -a $(BUILD_LOG) $(PROGRESS_LOG); \
	  echo "=== Build completed successfully at $$(date) ===" | tee -a $(BUILD_LOG) $(PROGRESS_LOG); } || \
	{ echo -e "\033[31m[ERROR]\033[0m $(PROJECT_NAME)" | tee -a $(BUILD_LOG) $(ERROR_LOG); \
	  echo "=== Build failed at $$(date) ===" | tee -a $(BUILD_LOG) $(ERROR_LOG); }

# Generic rule for all web2c objects with progress tracking
$(WEB2C_OBJECTS): $(BUILD_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_COUNT := $(shell echo $$(($(CURRENT_COUNT) + 1))))
	@echo "[$(CURRENT_COUNT)/$(TOTAL_OBJECTS)] Compiling $<" | tee -a $(PROGRESS_LOG)
	@$(CC) -c $(CFLAGS) $< -o $@ 2>&1 | tee -a $(BUILD_LOG) && \
	echo -e "\033[32m[OK]\033[0m $@" | tee -a $(PROGRESS_LOG) || \
	{ echo -e "\033[31m[ERROR]\033[0m $@" | tee -a $(BUILD_LOG) $(ERROR_LOG); exit 1; }

$(LUA_OBJECTS): $(BUILD_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_COUNT := $(shell echo $$(($(CURRENT_COUNT) + 1))))
	@echo "[$(CURRENT_COUNT)/$(TOTAL_OBJECTS)] Compiling $<" | tee -a $(PROGRESS_LOG)
	@$(CC) -c $(CFLAGS) $< -o $@ 2>&1 | tee -a $(BUILD_LOG) && \
	echo -e "\033[32m[OK]\033[0m $@" | tee -a $(PROGRESS_LOG) || \
	{ echo -e "\033[31m[ERROR]\033[0m $@" | tee -a $(BUILD_LOG) $(ERROR_LOG); exit 1; }

$(SUPPORT_OBJECTS): $(BUILD_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_COUNT := $(shell echo $$(($(CURRENT_COUNT) + 1))))
	@echo "[$(CURRENT_COUNT)/$(TOTAL_OBJECTS)] Compiling $<" | tee -a $(PROGRESS_LOG)
	@$(CC) -c $(CFLAGS) -I. $< -o $@ 2>&1 | tee -a $(BUILD_LOG) && \
	echo -e "\033[32m[OK]\033[0m $@" | tee -a $(PROGRESS_LOG) || \
	{ echo -e "\033[31m[ERROR]\033[0m $@" | tee -a $(BUILD_LOG) $(ERROR_LOG); exit 1; }

# Logged build variants
build-with-log:
	@echo "Building with full logging..."
	@$(MAKE) all 2>&1 | tee $(BUILD_LOG)

build-verbose:
	@echo "Building with verbose output..."
	@$(MAKE) VERBOSE=1 all 2>&1 | tee $(LOG_DIR)/verbose_build.log

build-quiet:
	@echo "Building quietly (errors only)..."
	@$(MAKE) all 2>&1 | grep -E "(error|Error|ERROR|warning|Warning|WARNING)" | tee $(ERROR_LOG) || true

# View logs
show-progress:
	@tail -f $(PROGRESS_LOG)

show-errors:
	@if [ -f $(ERROR_LOG) ]; then cat $(ERROR_LOG); else echo "No errors logged yet."; fi

show-build-log:
	@if [ -f $(BUILD_LOG) ]; then less $(BUILD_LOG); else echo "No build log found."; fi

# Log summary
log-summary:
	@echo "=== Build Log Summary ==="
	@echo "Build log: $(BUILD_LOG)"
	@echo "Progress log: $(PROGRESS_LOG)"
	@echo "Error log: $(ERROR_LOG)"
	@echo ""
	@echo "Log file sizes:"
	@ls -lh $(LOG_DIR)/ 2>/dev/null || echo "No logs found"
	@echo ""
	@echo "Recent errors:"
	@tail -10 $(ERROR_LOG) 2>/dev/null || echo "No errors found"

clean:
	@rm -rf $(BUILD_DIR)
	@echo -e "\033[32m[CLEANED]\033[0m $(PROJECT_NAME)"

clean-logs:
	@rm -rf $(LOG_DIR)
	@echo -e "\033[32m[CLEANED LOGS]\033[0m"

fclean: clean clean-logs
	@rm -f $(PROJECT_NAME)
	@echo -e "\033[32m[FCLEAN]\033[0m $(PROJECT_NAME)"

re: fclean _default

.PHONY: all clean fclean re show-sources setup-logs build-with-log build-verbose build-quiet show-progress show-errors show-build-log log-summary clean-logs
.SILENT: all clean fclean re