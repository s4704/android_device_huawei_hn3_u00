# The gps config appropriate for this device
#$(call inherit-product, device/common/gps/gps_us_supl.mk)

$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

$(call inherit-product-if-exists, vendor/huawei/hn3_u00/hn3_u00-vendor.mk)

LOCAL_PATH := device/huawei/hn3_u00

DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/root/fstab.k3v2oem1:root/fstab.k3v2oem1 \
    $(LOCAL_PATH)/root/init.k3v2oem1.rc:root/init.k3v2oem1.rc \
    $(LOCAL_PATH)/root/init.k3v2oem1.usb.rc:root/init.k3v2oem1.usb.rc \
    $(LOCAL_PATH)/root/init.k3v2oem1.cpu.rc:root/init.k3v2oem1.cpu.rc \
    $(LOCAL_PATH)/root/init.k3v2oem1.glove.rc:root/init.k3v2oem1.glove.rc \
    $(LOCAL_PATH)/root/ueventd.k3v2oem1.rc:root/ueventd.k3v2oem1.rc

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.camera.flash-autofocus.xml:system/etc/permissions/android.hardware.camera.flash-autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.location.gps.xml:system/etc/permissions/android.hardware.location.gps.xml \
    frameworks/native/data/etc/android.hardware.sensor.compass.xml:system/etc/permissions/android.hardware.sensor.compass.xml \
    frameworks/native/data/etc/android.hardware.sensor.gyroscope.xml:system/etc/permissions/android.hardware.sensor.gyroscope.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:system/etc/permissions/android.hardware.sensor.proximity.xml \
    frameworks/native/data/etc/android.hardware.telephony.gsm.xml:system/etc/permissions/android.hardware.telephony.gsm.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.software.sip.voip.xml:system/etc/permissions/android.software.sip.voip.xml \
    frameworks/native/data/etc/handheld_core_hardware.xml:system/etc/permissions/handheld_core_hardware.xml

# This device have enough room for precise davick
PRODUCT_TAGS += dalvik.gc.type-precise

# Device uses ultra-high-density artwork where available
PRODUCT_AAPT_CONFIG := hdpi xhdpi xxhdpi
PRODUCT_AAPT_PREF_CONFIG := xhdpi

# Prime spacific overrides
PRODUCT_PROPERTY_OVERRIDES += \
    ro.product.manufacturer=HUAWEI \
    ro.product.model=HN3-U00

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.usb.default \
    audio.r_submix.default \
    libemoji \
    sf2 \
    stream \
    record \
    recordvideo \
    libaudioutils \
    libaudio-resampler \
    audioloop \
    codec

# Display
PRODUCT_PACKAGES += \
    gralloc.k3v2oem1 \
    hwcomposer.k3v2oem1 \
    copybit.k3v2oem1 \
    libEGL_VIVANTE \
    libGLESv1_CM_VIVANTE \
    libGLESv2_VIVANTE \
    libGLSLC \
    libGAL

PRODUCT_PACKAGES += \
    wpa_supplicant.conf \
    hostapd.conf

# Misc
PRODUCT_PACKAGES += \
    setup_fs \
    librs_jni \
    libsrec_jni \
    com.android.future.usb.accessory \
    make_ext4fs 

# Live Wallpapers
PRODUCT_PACKAGES += \
    LiveWallpapers \
    LiveWallpapersPicker \
    VisualizationWallpapers

PRODUCT_PACKAGES += \
    libc2dcolorconvert \
    libdashplayer

PRODUCT_PACKAGES += \
    Torch \
    SOP

# Bluetooth
PRODUCT_PACKAGES += \
    bt_sco_app \
    BluetoothSCOApp \
    libtinyalsa

PRODUCT_PACKAGES += \
    uim-sysfs \
    libbt-vendor

# General
PRODUCT_PROPERTY_OVERRIDES += \
    ro.build.selinux=0

PRODUCT_PROPERTY_OVERRIDES += \
    media.stagefright.enable-player=true \
    media.stagefright.enable-meta=true \
    media.stagefright.enable-scan=true \
    media.stagefright.enable-http=true \
    media.stagefright.enable-rtsp=true \
    media.stagefright.enable-record=true \
    net.rmnet0.dns1=8.8.8.8 \
    net.rmnet0.dns2=8.8.4.4 \
    net.dns1=8.8.8.8 \
    net.dns2=8.8.4.4

# OpenGL ES
PRODUCT_PROPERTY_OVERRIDES += \
    wifi.interface=wlan0 \
    ap.interface=wlan1 \
    persist.sys.usb.config=mtp,adb \
    ro.opengles.version=131072

PRODUCT_PROPERTY_OVERRIDES += \
    ro.config.hspap_hsdpa_open=1 \
    ro.config.modem_hsic=true \
    ro.thmodem.type=sprd \
    ro.modem.type=6260 \
    ril.gsm.deviceid=-1 \
    ril.cdma.deviceid=-1 \
    ril.gsm.rssi=-1 \
    ril.cdma.rssi=-1 \
    persist.sys.logsystem.neversend=0 \
    modify_ram_show=true \
    persist.sys.phb.enable=1 \
    persist.sys.phb.debug.enable=1 \
    persist.sys.actualpoweron=true \
    persist.radio.apm_sim_not_pwdn=1 \
    ro.config.incall_notify_mms=true \
    ro.config.hw_allow_ums_and_mtp=true \
    ro.camera.sound.forced=1 \
    keyguard.no_require_sim=true \
    ro.config.hw_dolby=true \
    ro.dolbywithheadset.enable=1 \
    ro.streaming.video.drs=true \
    media.aac_51_output_enabled=true \
    ro.config.vdf_apn_switch=true \
    ro.config.hw_show_network_icon=true \
    persist.telephony.mpdn=false \
    ro.cellbroadcast.emergencyids=919,4371 \
    ro.config.vm_prioritymode=2 \
    ro.product.aac.softaac2ffmpeg=true \
    ro.config.helix_enable=true \
    af.resampler.quality=4 \
    ro.config.widevine_level3=true \
    drm.service.enabled=true

$(call inherit-product, build/target/product/full.mk)

# call dalvik heap config
$(call inherit-product-if-exists, frameworks/native/build/phone-xhdpi-1024-dalvik-heap.mk)
