################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/CameraSubsystem.cpp \
../src/Subsystems/ClimberSubsystem.cpp \
../src/Subsystems/DriveBaseSubsystem.cpp \
../src/Subsystems/ElevatorSubsystem.cpp \
../src/Subsystems/HopperSubsystem.cpp \
../src/Subsystems/Pixy.cpp \
../src/Subsystems/VisionSubsystem.cpp 

OBJS += \
./src/Subsystems/CameraSubsystem.o \
./src/Subsystems/ClimberSubsystem.o \
./src/Subsystems/DriveBaseSubsystem.o \
./src/Subsystems/ElevatorSubsystem.o \
./src/Subsystems/HopperSubsystem.o \
./src/Subsystems/Pixy.o \
./src/Subsystems/VisionSubsystem.o 

CPP_DEPS += \
./src/Subsystems/CameraSubsystem.d \
./src/Subsystems/ClimberSubsystem.d \
./src/Subsystems/DriveBaseSubsystem.d \
./src/Subsystems/ElevatorSubsystem.d \
./src/Subsystems/HopperSubsystem.d \
./src/Subsystems/Pixy.d \
./src/Subsystems/VisionSubsystem.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Zeming\workspace\1818/src" -IC:\Users\Zeming/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -Og -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


