EXPLOIT_NAME=stack_buffer_overflow_exploit
~/android_sdk/ndk-bundle/ndk-build
# ndk-build
~/android_sdk/platform-tools/adb push ./libs/armeabi-v7a/$EXPLOIT_NAME /data/local/tmp/
~/android_sdk/platform-tools/adb shell chmod 777 /data/local/tmp/$EXPLOT_NAME
# adb shell /data/local/tmp/$EXPLOIT_NAME
