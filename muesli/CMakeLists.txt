set(LIB_TARGET muesli)

# --------------------------------------------------------------------

# Library target

add_library(muesli
        detail/map.hpp
        detail/type_name.hpp
        archives.hpp
        bytes.hpp
        serializable.hpp
        serialize.hpp
        tuple.hpp
        build.cpp)

get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
target_include_directories(${LIB_TARGET} PUBLIC ${LIB_INCLUDE_PATH})

# --------------------------------------------------------------------

# Dependencies

target_link_libraries(${LIB_TARGET} PUBLIC ctti)
target_include_directories(${LIB_TARGET} PUBLIC ${cereal_INCLUDE_DIR})

# --------------------------------------------------------------------

# Set archive format

message(STATUS "Muesli archive format: ${MUESLI_ARCHIVE}")

target_compile_definitions(${LIB_TARGET} PUBLIC MUESLI_ARCHIVE_${MUESLI_ARCHIVE}=1)
