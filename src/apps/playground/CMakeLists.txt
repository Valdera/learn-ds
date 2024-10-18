set(APP_NAME "playground")

# Define the source files for the static app
set(APP_SOURCES main.cpp)

set(APP_HEADERS)

# Specify include directories for the static app
set(APP_INCLUDES
    "./"
    include
    "${CMAKE_BINARY_DIR}/configured_files/include"
)

# Add the executable target with its source file
add_executable(${APP_NAME} main.cpp)

# Specify include directories for the static app
target_include_directories(${APP_NAME} PUBLIC ${APP_INCLUDES})

# Precompile headers for the static app
target_precompile_headers(${APP_NAME} PUBLIC <string>)

# Link the app with other required libraries for the application
target_link_libraries(${APP_NAME} PUBLIC
)

target_set_warnings(
    TARGET
    ${APP_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
  target_enable_lto(${APP_NAME} optimized)
endif()

if(${ENABLE_CLANG_TIDY})
  add_clang_tidy_to_target(${APP_NAME})
endif()
