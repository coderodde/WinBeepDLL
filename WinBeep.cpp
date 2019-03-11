#include "WinBeep.h"
#include <windows.h>
#include <jni.h>

static const char* CLASS = "net/coderodde/os/beep/WindowsBeep";
static const char* FIELD_DURATION = "beepDuration";
static const char* FIELD_FREQUENCY = "beepFrequency";

static DWORD get_duration(JNIEnv* env, jobject obj) {
    jclass clazz = env->FindClass(CLASS);
    jfieldID fid = env->GetFieldID(clazz, FIELD_DURATION, "I");
    return (DWORD) env->GetIntField(obj, fid);
}

static DWORD get_frequency(JNIEnv* env, jobject obj) {
    jclass clazz = env->FindClass(CLASS);
    jfieldID fid = env->GetFieldID(clazz, FIELD_FREQUENCY, "I");
    return (DWORD) env->GetIntField(obj, fid);
}


JNIEXPORT void JNICALL Java_net_coderodde_os_beep_WindowsBeep_beep(JNIEnv* env, jobject obj) {
    DWORD dwFrequency = get_frequency(env, obj);
    DWORD dwDuration = get_duration(env, obj);
    Beep(dwFrequency, dwDuration);
}

