# bootanimation target
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 720

# Release name
PRODUCT_RELEASE_NAME := P6-U06

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/huawei/hwp6_u06/device_hwp6_u06.mk)


## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := hwp6_u06
PRODUCT_NAME := cm_hwp6_u06
PRODUCT_BRAND := huawei
PRODUCT_MODEL := P6-U06
PRODUCT_MANUFACTURER := HUAWEI


