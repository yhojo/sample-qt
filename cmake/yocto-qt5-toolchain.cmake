SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_C_COMPILER /opt/gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER /opt/gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)

SET(CMAKE_FIND_ROOT_PATH ~/yocto_varsomam33/rootfs/ /opt/qt5devtools/sysroots/cortexa8hf-vfp-neon-linux-gnueabi/)

#SET(CMAKE_MODULE_LINKER_FLAGS "-l ~/yocto_varsomam33/rootfs/lib")
#SET(CMAKE_SHARED_LINKER_FLAGS "-l ~/yocto_varsomam33/rootfs/lib")
#SET(CMAKE_EXE_LINKER_FLAGS "-l ~/yocto_varsomam33/rootfs/lib")

link_directories(~/yocto_varsomam33/rootfs/lib)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(OE_QMAKE_PATH_EXTERNAL_HOST_BINS /opt/qt5devtools/sysroots/x86_64-arago-linux/usr/bin/qt5)

SET(without-test TRUE)
#SET(MAKE_VERBOSE_MAKEFILE TRUE)
