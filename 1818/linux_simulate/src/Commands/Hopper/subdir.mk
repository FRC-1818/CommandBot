################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Hopper/Hopperdown.cpp \
../src/Commands/Hopper/Hopperstop.cpp \
../src/Commands/Hopper/Hopperup.cpp 

OBJS += \
./src/Commands/Hopper/Hopperdown.o \
./src/Commands/Hopper/Hopperstop.o \
./src/Commands/Hopper/Hopperup.o 

CPP_DEPS += \
./src/Commands/Hopper/Hopperdown.d \
./src/Commands/Hopper/Hopperstop.d \
./src/Commands/Hopper/Hopperup.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Hopper/%.o: ../src/Commands/Hopper/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Zeming\workspace\1818/src" -IC:\Users\Zeming/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -Og -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


