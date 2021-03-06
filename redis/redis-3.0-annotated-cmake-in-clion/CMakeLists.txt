cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(redis-3.0-annotated-cmake VERSION 3.0)

set(CMAKE_BUILD_TYPE "Debug")


message(STATUS "Host is: ${CMAKE_HOST_SYSTEM}.  Build target is: ${CMAKE_SYSTEM}")
get_filename_component(REDIS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
message(STATUS "Project root directory is: ${REDIS_ROOT}")

set(CMAKE_LEGACY_CYGWIN_WIN32 0)

add_subdirectory(deps)
add_subdirectory(our-redis-implementation)

set(SRC_SERVER
        src/adlist.c src/ae.c src/anet.c src/dict.c src/redis.c src/sds.c src/zmalloc.c
        src/lzf_c.c src/lzf_d.c src/pqsort.c src/zipmap.c src/sha1.c src/ziplist.c
        src/release.c src/networking.c src/util.c src/object.c src/db.c
        src/replication.c src/rdb.c src/t_string.c src/t_list.c src/t_set.c
        src/t_zset.c src/t_hash.c src/config.c src/aof.c src/pubsub.c
        src/multi.c src/debug.c src/sort.c src/intset.c src/syncio.c
        src/cluster.c src/crc16.c src/endianconv.c src/slowlog.c src/scripting.c
        src/bio.c src/rio.c src/rand.c src/memtest.c src/crc64.c src/bitops.c
        src/sentinel.c src/notify.c src/setproctitle.c src/blocked.c src/hyperloglog.c
        )

set(SRC_CLI
        src/anet.c src/sds.c src/adlist.c src/redis-cli.c src/zmalloc.c src/release.c src/anet.c src/ae.c src/crc64.c
        )


set(EXECUTABLE_OUTPUT_PATH src)
link_directories(deps/linenoise/ deps/lua/src deps/hiredis)

add_executable(redis-server ${SRC_SERVER})
target_include_directories(redis-server
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )
target_link_libraries(redis-server
        PRIVATE pthread
        PRIVATE dl
        PRIVATE m
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )
add_executable(redis-example  src/test/sds_test.c)
target_include_directories(redis-example
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )
target_link_libraries(redis-example
        PRIVATE pthread
        PRIVATE dl
        PRIVATE m
        PRIVATE lua
        PRIVATE linenoise
        PRIVATE hiredis
        )


add_executable(redis-cli ${SRC_CLI})
target_include_directories(redis-cli
        PRIVATE ${REDIS_ROOT}/deps/linenoise
        PRIVATE ${REDIS_ROOT}/deps/hiredis
        PRIVATE ${REDIS_ROOT}/deps/lua/src
        )
target_link_libraries(redis-cli
        PRIVATE pthread
        PRIVATE m
        PRIVATE linenoise
        PRIVATE hiredis
        )
