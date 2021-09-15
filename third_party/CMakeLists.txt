include(FetchContent)

# --------------------------------------------------------------------

# set(FETCHCONTENT_FULLY_DISCONNECTED ON)
# set(FETCHCONTENT_QUIET OFF)

# --------------------------------------------------------------------

message(STATUS "FetchContent: cereal")

FetchContent_Declare(
        cereal
        GIT_REPOSITORY https://github.com/USCiLab/cereal.git
        GIT_TAG master
)
# FetchContent_MakeAvailable(cereal)
FetchContent_Populate("cereal")
set(cereal_INCLUDE_DIR "${cereal_SOURCE_DIR}/include" PARENT_SCOPE)

# --------------------------------------------------------------------

message(STATUS "FetchContent: ctti")

FetchContent_Declare(
        ctti
        GIT_REPOSITORY https://github.com/Manu343726/ctti
        GIT_TAG master
)
FetchContent_MakeAvailable(ctti)
