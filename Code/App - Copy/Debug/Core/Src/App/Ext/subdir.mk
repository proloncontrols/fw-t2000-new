################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/App/Ext/app.c \
../Core/Src/App/Ext/env.c \
../Core/Src/App/Ext/env_scd4x.c \
../Core/Src/App/Ext/env_sht4x.c 

C_DEPS += \
./Core/Src/App/Ext/app.d \
./Core/Src/App/Ext/env.d \
./Core/Src/App/Ext/env_scd4x.d \
./Core/Src/App/Ext/env_sht4x.d 

OBJS += \
./Core/Src/App/Ext/app.o \
./Core/Src/App/Ext/env.o \
./Core/Src/App/Ext/env_scd4x.o \
./Core/Src/App/Ext/env_sht4x.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/App/Ext/%.o Core/Src/App/Ext/%.su Core/Src/App/Ext/%.cyclo: ../Core/Src/App/Ext/%.c Core/Src/App/Ext/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H735xx -DPROJECT_APP -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/STM32H735G-DK" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/Common" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/ft5336" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/mx25lm51245g" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/s70kl1281" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Core/Inc/App" -I"C:/Repos/Firmware/Projects/fw-t2000-001/Lib/Inc" -I"C:/Repos/Firmware/Projects/fw-t2000-001/Common/Inc" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Core/Inc/App/Ext" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-App-2f-Ext

clean-Core-2f-Src-2f-App-2f-Ext:
	-$(RM) ./Core/Src/App/Ext/app.cyclo ./Core/Src/App/Ext/app.d ./Core/Src/App/Ext/app.o ./Core/Src/App/Ext/app.su ./Core/Src/App/Ext/env.cyclo ./Core/Src/App/Ext/env.d ./Core/Src/App/Ext/env.o ./Core/Src/App/Ext/env.su ./Core/Src/App/Ext/env_scd4x.cyclo ./Core/Src/App/Ext/env_scd4x.d ./Core/Src/App/Ext/env_scd4x.o ./Core/Src/App/Ext/env_scd4x.su ./Core/Src/App/Ext/env_sht4x.cyclo ./Core/Src/App/Ext/env_sht4x.d ./Core/Src/App/Ext/env_sht4x.o ./Core/Src/App/Ext/env_sht4x.su

.PHONY: clean-Core-2f-Src-2f-App-2f-Ext

