################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Climber/Climbdown.cpp \
../src/Commands/Climber/Climbstop.cpp \
../src/Commands/Climber/Climbup.cpp 

OBJS += \
./src/Commands/Climber/Climbdown.o \
./src/Commands/Climber/Climbstop.o \
./src/Commands/Climber/Climbup.o 

CPP_DEPS += \
./src/Commands/Climber/Climbdown.d \
./src/Commands/Climber/Climbstop.d \
./src/Commands/Climber/Climbup.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Climber/%.o: ../src/Commands/Climber/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Zeming\workspace\1818/src" -IC:\Users\Zeming/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -Og -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


