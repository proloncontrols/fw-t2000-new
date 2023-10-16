################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/cfg.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/com.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/com_rs485.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/e2.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/flash.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/flash_mx25lm51245.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/flash_stm32h735.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/framework.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/modbus.c \
C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/ui.c 

OBJS += \
./Common/Src/cfg.o \
./Common/Src/com.o \
./Common/Src/com_rs485.o \
./Common/Src/e2.o \
./Common/Src/flash.o \
./Common/Src/flash_mx25lm51245.o \
./Common/Src/flash_stm32h735.o \
./Common/Src/framework.o \
./Common/Src/modbus.o \
./Common/Src/ui.o 

C_DEPS += \
./Common/Src/cfg.d \
./Common/Src/com.d \
./Common/Src/com_rs485.d \
./Common/Src/e2.d \
./Common/Src/flash.d \
./Common/Src/flash_mx25lm51245.d \
./Common/Src/flash_stm32h735.d \
./Common/Src/framework.d \
./Common/Src/modbus.d \
./Common/Src/ui.d 


# Each subdirectory must supply rules for building sources it contributes
Common/Src/cfg.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/cfg.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/com.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/com.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/com_rs485.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/com_rs485.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/e2.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/e2.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/flash.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/flash.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/flash_mx25lm51245.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/flash_mx25lm51245.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/flash_stm32h735.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/flash_stm32h735.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/framework.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/framework.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/modbus.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/modbus.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/ui.o: C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Src/ui.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-Src

clean-Common-2f-Src:
	-$(RM) ./Common/Src/cfg.cyclo ./Common/Src/cfg.d ./Common/Src/cfg.o ./Common/Src/cfg.su ./Common/Src/com.cyclo ./Common/Src/com.d ./Common/Src/com.o ./Common/Src/com.su ./Common/Src/com_rs485.cyclo ./Common/Src/com_rs485.d ./Common/Src/com_rs485.o ./Common/Src/com_rs485.su ./Common/Src/e2.cyclo ./Common/Src/e2.d ./Common/Src/e2.o ./Common/Src/e2.su ./Common/Src/flash.cyclo ./Common/Src/flash.d ./Common/Src/flash.o ./Common/Src/flash.su ./Common/Src/flash_mx25lm51245.cyclo ./Common/Src/flash_mx25lm51245.d ./Common/Src/flash_mx25lm51245.o ./Common/Src/flash_mx25lm51245.su ./Common/Src/flash_stm32h735.cyclo ./Common/Src/flash_stm32h735.d ./Common/Src/flash_stm32h735.o ./Common/Src/flash_stm32h735.su ./Common/Src/framework.cyclo ./Common/Src/framework.d ./Common/Src/framework.o ./Common/Src/framework.su ./Common/Src/modbus.cyclo ./Common/Src/modbus.d ./Common/Src/modbus.o ./Common/Src/modbus.su ./Common/Src/ui.cyclo ./Common/Src/ui.d ./Common/Src/ui.o ./Common/Src/ui.su

.PHONY: clean-Common-2f-Src

