# Install script for directory: C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Project")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/gcc-arm-none-eabi/bin/arm-none-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/pico_extras/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/pico-sdk/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/blink/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/hello_world/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/adc/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/clocks/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/cmake/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/divider/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/dma/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/flash/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/gpio/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/i2c/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/interp/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/multicore/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/picoboard/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/pico_w/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/pio/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/pwm/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/reset/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/rtc/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/spi/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/system/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/timer/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/uart/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/usb/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/watchdog/cmake_install.cmake")
  include("C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/pico-lora-master/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/jensh/Documents/Pico-v1.5.1/IOT_Velutamonitor_windesheim/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
