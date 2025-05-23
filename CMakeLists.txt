# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(botoes_iot_nuvem C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

file(GLOB_RECURSE MAIN "src/botoes_iot_nuvem.c")

file(GLOB_RECURSE UTILS "src/utils/**/*c")

file(GLOB_RECURSE SERVIDOR_NUVEM "src/utils/servidor_nuvem/*c")



# Add executable. Default name is the project name, version 0.1

add_executable(botoes_iot_nuvem 
        ${MAIN}
        ${UTILS}        
        ${SERVIDOR_NUVEM} 
        ${CONEXAO}   
        ${BOTOES}  
)

pico_set_program_name(botoes_iot_nuvem "botoes_iot_nuvem")
pico_set_program_version(botoes_iot_nuvem "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(botoes_iot_nuvem 0)
pico_enable_stdio_usb(botoes_iot_nuvem 1)

# Add the standard library to the build
target_link_libraries(botoes_iot_nuvem
        pico_stdlib
        hardware_adc
        hardware_gpio
        hardware_i2c
        pico_cyw43_arch_lwip_threadsafe_background      
        )

# Add the standard include files to the build
target_include_directories(botoes_iot_nuvem PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/src/utils
        ${CMAKE_CURRENT_LIST_DIR}/src/utils/botoes
        ${CMAKE_CURRENT_LIST_DIR}/src/utils/servidor_nuvem
        ${CMAKE_CURRENT_LIST_DIR}/src/utils/wifi
)

pico_add_extra_outputs(botoes_iot_nuvem)

