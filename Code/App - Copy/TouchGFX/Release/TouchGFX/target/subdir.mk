################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/target/CortexMMCUInstrumentation.cpp \
../TouchGFX/target/STM32TouchController.cpp \
../TouchGFX/target/TouchGFXGPIO.cpp \
../TouchGFX/target/TouchGFXHAL.cpp 

OBJS += \
./TouchGFX/target/CortexMMCUInstrumentation.o \
./TouchGFX/target/STM32TouchController.o \
./TouchGFX/target/TouchGFXGPIO.o \
./TouchGFX/target/TouchGFXHAL.o 

CPP_DEPS += \
./TouchGFX/target/CortexMMCUInstrumentation.d \
./TouchGFX/target/STM32TouchController.d \
./TouchGFX/target/TouchGFXGPIO.d \
./TouchGFX/target/TouchGFXHAL.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/target/%.o TouchGFX/target/%.su TouchGFX/target/%.cyclo: ../TouchGFX/target/%.cpp TouchGFX/target/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32H735xx -DPROJECT_APP -DRELEASE -DE2_DEVICE_BR24L04W -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/STM32H735G-DK" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/Common" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/ft5336" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/mx25lm51245g" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/s70kl1281" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Core/Inc/App" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Core/Inc/App/Ext" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc/TouchGFX" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-target

clean-TouchGFX-2f-target:
	-$(RM) ./TouchGFX/target/CortexMMCUInstrumentation.cyclo ./TouchGFX/target/CortexMMCUInstrumentation.d ./TouchGFX/target/CortexMMCUInstrumentation.o ./TouchGFX/target/CortexMMCUInstrumentation.su ./TouchGFX/target/STM32TouchController.cyclo ./TouchGFX/target/STM32TouchController.d ./TouchGFX/target/STM32TouchController.o ./TouchGFX/target/STM32TouchController.su ./TouchGFX/target/TouchGFXGPIO.cyclo ./TouchGFX/target/TouchGFXGPIO.d ./TouchGFX/target/TouchGFXGPIO.o ./TouchGFX/target/TouchGFXGPIO.su ./TouchGFX/target/TouchGFXHAL.cyclo ./TouchGFX/target/TouchGFXHAL.d ./TouchGFX/target/TouchGFXHAL.o ./TouchGFX/target/TouchGFXHAL.su

.PHONY: clean-TouchGFX-2f-target
