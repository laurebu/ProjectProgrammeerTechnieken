################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/buttonDriver.c \
../source/hardwareInit.c \
../source/inputControl.c \
../source/joystickDriver.c \
../source/lcdControl.c \
../source/lcdDriver.c \
../source/ledControl.c \
../source/ledDriver.c \
../source/main.c \
../source/speakerControl.c \
../source/speakerDriver.c 

OBJS += \
./source/buttonDriver.o \
./source/hardwareInit.o \
./source/inputControl.o \
./source/joystickDriver.o \
./source/lcdControl.o \
./source/lcdDriver.o \
./source/ledControl.o \
./source/ledDriver.o \
./source/main.o \
./source/speakerControl.o \
./source/speakerDriver.o 

C_DEPS += \
./source/buttonDriver.d \
./source/hardwareInit.d \
./source/inputControl.d \
./source/joystickDriver.d \
./source/lcdControl.d \
./source/lcdDriver.d \
./source/ledControl.d \
./source/ledDriver.d \
./source/main.d \
./source/speakerControl.d \
./source/speakerDriver.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../component/lists -I../component/uart -I../utilities -I../board/boards -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


