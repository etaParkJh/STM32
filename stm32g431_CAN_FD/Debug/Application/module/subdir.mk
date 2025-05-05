################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/module/dimming.c 

OBJS += \
./Application/module/dimming.o 

C_DEPS += \
./Application/module/dimming.d 


# Each subdirectory must supply rules for building sources it contributes
Application/module/%.o Application/module/%.su Application/module/%.cyclo: ../Application/module/%.c Application/module/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"D:/Personal/STM32/workspace/STM32/stm32g431_PWM/Application" -I"D:/Personal/STM32/workspace/STM32/stm32g431_PWM/Application/module" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-module

clean-Application-2f-module:
	-$(RM) ./Application/module/dimming.cyclo ./Application/module/dimming.d ./Application/module/dimming.o ./Application/module/dimming.su

.PHONY: clean-Application-2f-module

