################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TouchGFX/target/generated/subdir.mk
-include TouchGFX/target/subdir.mk
-include TouchGFX/gui/src/splash_screen/subdir.mk
-include TouchGFX/gui/src/model/subdir.mk
-include TouchGFX/gui/src/containers/subdir.mk
-include TouchGFX/gui/src/common/subdir.mk
-include TouchGFX/generated/texts/src/subdir.mk
-include TouchGFX/generated/images/src/subdir.mk
-include TouchGFX/generated/gui_generated/src/splash_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/containers/subdir.mk
-include TouchGFX/generated/gui_generated/src/common/subdir.mk
-include TouchGFX/generated/fonts/src/subdir.mk
-include TouchGFX/Release/TouchGFX/target/generated/subdir.mk
-include TouchGFX/Release/TouchGFX/target/subdir.mk
-include TouchGFX/Release/TouchGFX/gui/src/splash_screen/subdir.mk
-include TouchGFX/Release/TouchGFX/gui/src/model/subdir.mk
-include TouchGFX/Release/TouchGFX/gui/src/main_screen/subdir.mk
-include TouchGFX/Release/TouchGFX/gui/src/common/subdir.mk
-include TouchGFX/Release/TouchGFX/gui/src/clear_screen/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/texts/src/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/images/src/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/gui_generated/src/splash_screen/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/gui_generated/src/main_screen/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/gui_generated/src/common/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/gui_generated/src/clear_screen/subdir.mk
-include TouchGFX/Release/TouchGFX/generated/fonts/src/subdir.mk
-include TouchGFX/Release/TouchGFX/App/subdir.mk
-include TouchGFX/Release/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include TouchGFX/Release/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include TouchGFX/Release/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include TouchGFX/Release/Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include TouchGFX/Release/Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include TouchGFX/Release/Drivers/BSP/STM32H735G-DK/subdir.mk
-include TouchGFX/Release/Drivers/BSP/Components/s70kl1281/subdir.mk
-include TouchGFX/Release/Drivers/BSP/Components/mx25lm51245g/subdir.mk
-include TouchGFX/Release/Drivers/BSP/Components/ft5336/subdir.mk
-include TouchGFX/Release/Core/Startup/subdir.mk
-include TouchGFX/Release/Core/Src/App/subdir.mk
-include TouchGFX/Release/Core/Src/subdir.mk
-include TouchGFX/Release/Core/Inc/subdir.mk
-include TouchGFX/Release/Common/Src/TouchGFX/subdir.mk
-include TouchGFX/Release/Common/Src/subdir.mk
-include TouchGFX/App/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32H735G-DK/subdir.mk
-include Drivers/BSP/Components/s70kl1281/subdir.mk
-include Drivers/BSP/Components/mx25lm51245g/subdir.mk
-include Drivers/BSP/Components/ft5336/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/App/subdir.mk
-include Core/Src/subdir.mk
-include Core/Inc/subdir.mk
-include Common/Src/TouchGFX/subdir.mk
-include Common/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := App
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
App.elf \

MAP_FILES += \
App.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
App.list \

OBJCOPY_HEX += \
App.hex \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: App.elf secondary-outputs

# Tool invocations
App.elf App.map: $(OBJS) $(USER_OBJS) C:/ProlonDev/Projects/T2000/Firmware/Code/App\App.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "App.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:/ProlonDev/Projects/T2000/Firmware/Code/App\App.ld" --specs=nosys.specs -Wl,-Map="App.map" -Wl,--gc-sections -static -L"C:\ProlonDev\Projects\T2000\Firmware\Code\App\Middlewares\ST\touchgfx\lib\core\cortex_m7\gcc" -L"C:\ProlonDev\Projects\T2000\Firmware\Code/Common" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

App.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "App.list"
	@echo 'Finished building: $@'
	@echo ' '

App.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "App.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) App.elf App.hex App.list App.map default.size.stdout
	-@echo ' '

post-build:
	arm-none-eabi-objcopy  App.elf App_NOOSPI.elf --remove-section=*FlashSection
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified post-build

-include ../makefile.targets
