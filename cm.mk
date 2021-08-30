# bootanimation target
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 720

# Release name
PRODUCT_RELEASE_NAME := HN3-U00

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/huawei/hn3_u00/device_hn3_u00.mk)


## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := hn3_u00
PRODUCT_NAME := cm_hn3_u00
PRODUCT_BRAND := Huawei
PRODUCT_MODEL := HN3-U00
PRODUCT_MANUFACTURER := HUAWEI


