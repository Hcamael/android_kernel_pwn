EXPLOIT_NAME=stack_buffer_overflow_exploit
cp /mnt/hgfs/tmp/android_kernel/pwn/challenges/stack_buffer_overflow/solution/jni/stack_buffer_overflow_exploit.c ./jni
~/android_sdk/ndk-bundle/ndk-build
# ndk-build
adb push ./libs/armeabi-v7a/$EXPLOIT_NAME /data/local/tmp/
adb shell chmod 777 /data/local/tmp/$EXPLOT_NAME
# adb shell /data/local/tmp/$EXPLOIT_NAME
