################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HULTRA_program.c \
../src/MDIO_program.c \
../src/MRCC_program.c \
../src/MTIMER2_program.c \
../src/MTIMER3_program.c \
../src/main.c 

OBJS += \
./src/HULTRA_program.o \
./src/MDIO_program.o \
./src/MRCC_program.o \
./src/MTIMER2_program.o \
./src/MTIMER3_program.o \
./src/main.o 

C_DEPS += \
./src/HULTRA_program.d \
./src/MDIO_program.d \
./src/MRCC_program.d \
./src/MTIMER2_program.d \
./src/MTIMER3_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


