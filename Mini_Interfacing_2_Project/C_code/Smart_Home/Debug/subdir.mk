################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../LCD.c \
../LDR.c \
../LED.c \
../LM35.c \
../Main_Application.c \
../PWM.c \
../buzzer.c \
../flame.c \
../gpio.c \
../motor.c 

OBJS += \
./ADC.o \
./LCD.o \
./LDR.o \
./LED.o \
./LM35.o \
./Main_Application.o \
./PWM.o \
./buzzer.o \
./flame.o \
./gpio.o \
./motor.o 

C_DEPS += \
./ADC.d \
./LCD.d \
./LDR.d \
./LED.d \
./LM35.d \
./Main_Application.d \
./PWM.d \
./buzzer.d \
./flame.d \
./gpio.d \
./motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


