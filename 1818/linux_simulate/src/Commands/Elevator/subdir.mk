################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Elevator/ElevatorOff.cpp \
../src/Commands/Elevator/ElevatorOn.cpp 

OBJS += \
./src/Commands/Elevator/ElevatorOff.o \
./src/Commands/Elevator/ElevatorOn.o 

CPP_DEPS += \
./src/Commands/Elevator/ElevatorOff.d \
./src/Commands/Elevator/ElevatorOn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Elevator/%.o: ../src/Commands/Elevator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Zeming\workspace\1818/src" -IC:\Users\Zeming/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -Og -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


