################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.c \
../Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.c \
../Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.c \
../Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.c 

C_DEPS += \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.d \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.d \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.d \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.d 

OBJS += \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.o \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.o \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.o \
./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H735G-DK/%.o Drivers/BSP/STM32H735G-DK/%.su Drivers/BSP/STM32H735G-DK/%.cyclo: ../Drivers/BSP/STM32H735G-DK/%.c Drivers/BSP/STM32H735G-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H735xx -DPROJECT_APP -DRELEASE -DE2_DEVICE_BR24L04W -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/STM32H735G-DK" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/Common" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/ft5336" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/mx25lm51245g" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/s70kl1281" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Core/Inc/App" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Core/Inc/App/Ext" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H735G-2d-DK

clean-Drivers-2f-BSP-2f-STM32H735G-2d-DK:
	-$(RM) ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.cyclo ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.d ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.o ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery.su ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.cyclo ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.d ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.o ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_bus.su ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.cyclo ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.d ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.o ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ospi.su ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.cyclo ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.d ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.o ./Drivers/BSP/STM32H735G-DK/stm32h735g_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H735G-2d-DK

