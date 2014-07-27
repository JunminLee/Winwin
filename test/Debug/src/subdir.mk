################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/FaceDetectionForm.cpp \
../src/FaceRecognizer.cpp \
../src/FaceRecognizerEntry.cpp \
../src/Info.cpp \
../src/InfoCompare.cpp \
../src/testApp.cpp \
../src/testEntry.cpp \
../src/testFormFactory.cpp \
../src/testFrame.cpp \
../src/testMainForm.cpp \
../src/testPanelFactory.cpp 

OBJS += \
./src/AppResourceId.o \
./src/FaceDetectionForm.o \
./src/FaceRecognizer.o \
./src/FaceRecognizerEntry.o \
./src/Info.o \
./src/InfoCompare.o \
./src/testApp.o \
./src/testEntry.o \
./src/testFormFactory.o \
./src/testFrame.o \
./src/testMainForm.o \
./src/testPanelFactory.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/FaceDetectionForm.d \
./src/FaceRecognizer.d \
./src/FaceRecognizerEntry.d \
./src/Info.d \
./src/InfoCompare.d \
./src/testApp.d \
./src/testEntry.d \
./src/testFormFactory.d \
./src/testFrame.d \
./src/testMainForm.d \
./src/testPanelFactory.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_DEBUG -I"D:\Tizen-Git\Winwin\test\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target i386-tizen-linux-gnueabi -gcc-toolchain "D:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Wno-gnu -fPIE --sysroot="D:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native" -I"D:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/libxml2" -I"D:\tizen-sdk\library" -I"D:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include" -I"D:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


