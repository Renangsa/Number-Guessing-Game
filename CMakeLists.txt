# Copyright (c) Maia

cmake_minimum_required(VERSION 3.27)

project(
  jogo
  VERSION 0.0.1
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(COMPILE_COMMANDS_SRC "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
set(COMPILE_COMMANDS_DST "${CMAKE_SOURCE_DIR}/compile_commands.json")
file(
  COPY_FILE
  "${COMPILE_COMMANDS_SRC}"
  "${COMPILE_COMMANDS_DST}"
)


add_executable(joguim)

target_sources(
  joguim
    PRIVATE
      "main.cpp"
) 

