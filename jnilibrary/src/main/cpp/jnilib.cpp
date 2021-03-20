#include <jni.h>
#include <string>
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>
#include <strstream>

#define TAG "mytag"
#define     LOGI(...)     __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define     LOGD(...)     __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define     LOGE(...)     __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define     LOGW(...)     __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define     LOGF(...)     __android_log_print(ANDROID_LOG_FATAL, TAG, __VA_ARGS__)

/**
 * MethodParamsController 查看java方法参数对应jni方法参数
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_paas_appdev_jnilibrary_controller_MethodParamsController_params(JNIEnv *env, jobject thiz,
                                                                         jint a, jfloat b,
                                                                         jboolean c, jdouble d,
                                                                         jlong e, jshort f,
                                                                         jstring g, jobject h) {
    return g;
}
/**
 * 返回一个int类型
 */
extern "C"
JNIEXPORT jint JNICALL
Java_com_paas_appdev_jnilibrary_controller_MethodParamsController_getParamsInt(JNIEnv *env,
                                                                               jobject thiz,
                                                                               jint a) {
    jint ji = 12;//int类型是基本类型，直接返回即可
    return ji;
}

/**
 * 返回一个new出来的字符串
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_paas_appdev_jnilibrary_controller_MethodParamsController_getParamsString(JNIEnv *env,
                                                                                  jobject thiz) {
    jstring jstring1 = env->NewStringUTF("新建字符串返回");
    return jstring1;
}
/**
 * 在c中打印日志
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_LogController_logE(JNIEnv *env, jobject thiz) {
    LOGE("打印日志Error级别");
}

/**
 * 无返回值，无参数
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_RetuurnAndParamsController_noparamsAndnoreturn(
        JNIEnv *env, jobject thiz) {
    printf("c语言打印日志：%d", 12);
}
/**
 *无参数有返回值
 */
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_paas_appdev_jnilibrary_controller_RetuurnAndParamsController_noparamsAndhasreturn(
        JNIEnv *env, jobject thiz) {
    jboolean m = true;
    return m;
}
/**
 * 无返回值，有参数
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_RetuurnAndParamsController_hasparamsAndnoreturn(
        JNIEnv *env, jobject thiz, jint num) {
//    ostringstream oss;
//    oss<<"ss"<<num;
//    LOGE(oss.str());
}
/**
 * 有返回值，有参数
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_paas_appdev_jnilibrary_controller_RetuurnAndParamsController_hasparamsAndhasreturn(
        JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("哈哈哈");
}
/**
 * jni调用java方法：  无参数，无返回值
 * 调用完成，原生方法会打印参数
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_Jni2JavaStaticController_callNoParamsAndnoReturn(
        JNIEnv *env, jobject thiz) {
    jclass jclz = env->GetObjectClass(thiz);
    jmethodID jmethodId = env->GetStaticMethodID(jclz, "noparamsAndnoreturn", "()V");
    if (jmethodId == NULL) {
        LOGE("获取静态方法id为空");
        return;
    }
    env->CallStaticVoidMethod(jclz, jmethodId);

}
/**
 * jni调用java方法  有参数无返回值
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_Jni2JavaStaticController_callHasParamsAndnoReturn(
        JNIEnv *env, jobject thiz) {
    jclass jclz = env->GetObjectClass(thiz);
    jmethodID jmId = env->GetStaticMethodID(jclz, "hasparamsAndnoreturn", "(I)V");
    if (jmId == NULL) {
        LOGE("获取静态方法id为空，方法执行失败");
        return;
    }
    jint params = 123;
    env->CallStaticVoidMethod(jclz, jmId, params);
}
/**
 * jni调用java方法  没有参数，有返回值
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_Jni2JavaStaticController_callNoParamsAndHasReturn(
        JNIEnv *env, jobject thiz) {
    jclass jclz = env->GetObjectClass(thiz);
    jmethodID jmid = env->GetStaticMethodID(jclz, "noparamsAndhasreturn", "()Ljava/lang/String;");
    if (jmid == NULL) {
        LOGE("获取静态方法id为空，方法执行失败");
        return;
    }
    jobject jstr = env->CallStaticObjectMethod(jclz, jmid);
    //想用LOGE打印日志jstr，但是不能打印
}
/**
 * jni调用java方法    有参数有返回值
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_Jni2JavaStaticController_callHasParamsAndHasReturn(
        JNIEnv *env, jobject thiz) {
    jclass jclz = env->GetObjectClass(thiz);
    jmethodID jmid = env->GetStaticMethodID(jclz, "hasparamsAndhasreturn",
                                            "(Ljava/lang/String;)Ljava/lang/String;");
    if (jmid == NULL) {
        LOGE("获取静态方法id为空，方法执行失败");
        return;
    }
    jstring jstring1 = env->NewStringUTF("hahaha");
    env->CallStaticObjectMethod(jclz, jmid, jstring1);
}
/**
 * 调用其它类的方法或者参数
 * 调用Jni2JavaStaticController类里面的noparamsAndnoreturn静态方法
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_Jni2JavaStaticController_callOtherClassStaticMethod(
        JNIEnv *env, jobject thiz) {
    char *clsName = "com/paas/appdev/jnilibrary/controller/Jni2JavaStaticController";
    jclass jclz = env->FindClass(clsName);
    jmethodID jmid = env->GetStaticMethodID(jclz, "noparamsAndnoreturn", "()V");
    if (jmid == NULL) {
        LOGE("获取静态方法id为空，方法执行失败");
        return;
    }
    LOGE("调用外部类的静态方法");
    env->CallStaticVoidMethod(jclz, jmid);
}

/**
 * jni调用java对象的非静态方法
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_NonStaticMethodController_callnonstaticmethod(
        JNIEnv *env, jobject thiz) {
    char *clsName = "com/paas/appdev/jnilibrary/controller/NonStaticMethodController";
    jclass jclz = env->FindClass(clsName);
    char *initMethodName = "<init>";
    jmethodID jinitMid = env->GetMethodID(jclz, initMethodName, "()V");
    jobject jo = env->NewObject(jclz, jinitMid, env->NewStringUTF("哈哈哈"));
    jmethodID jcallMid = env->GetMethodID(jclz, "print", "()V");
    env->CallVoidMethod(jo, jcallMid);//如果被调用的方法后面有参数，在方法后面加上即可
}

/**
 * 调用java反射
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_paas_appdev_jnilibrary_controller_JniReflectController_callReflect(JNIEnv *env,
                                                                            jobject thiz) {
    char *clsName = "com/paas/appdev/jnilibrary/controller/JniReflectController";
    jclass jclz = env->FindClass(clsName);
    char *initMethodName = "<init>";
    jmethodID jconMid = env->GetMethodID(jclz, initMethodName, "(Ljava/lang/String;)V");
    jobject jobject1 = env->NewObject(jclz,jconMid ,env->NewStringUTF("哈哈哈"));

    jmethodID jprintMid = env->GetMethodID(jclz,"print1","()V");
    env->CallVoidMethod(jobject1,jprintMid);

}
/**
 * AES加密功能实现
 */
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_paas_appdev_jnilibrary_controller_AESDESEncrpyController_encrptOrdecrpt(JNIEnv *env, jobject thiz,
                                                                          jbyteArray textbyte,
                                                                          jbyteArray pwdbyte,
                                                                          jint flag) {
    //获取SecretKeySpec对象
    jstring CHIPER_MODE = env->NewStringUTF("AES/ECB/PKCS5Padding");
    jstring AES = env->NewStringUTF("AES");
    char *jsecretClsName ="javax/crypto/spec/SecretKeySpec";
    jclass jsecretClz = env->FindClass(jsecretClsName);
    char *initMethodName = "<init>";
    jmethodID jconMid = env->GetMethodID(jsecretClz,initMethodName,"([BLjava/lang/String;)V");
//    jbyte* jbytePwd = env->GetByteArrayElements(pwdbyte,0);
    jobject jSecretObj = env->NewObject(jsecretClz,jconMid,pwdbyte,AES);

    //获取Cipher对象
    char *chiperClsName = "javax/crypto/Cipher";
    jclass jChiperClz = env->FindClass(chiperClsName);
    jmethodID jChiperInstanceMid = env->GetStaticMethodID(jChiperClz,"getInstance","(Ljava/lang/String;)Ljavax/crypto/Cipher;");
    jobject jChiperObj = env->CallStaticObjectMethod(jChiperClz,jChiperInstanceMid,CHIPER_MODE);

    //调用Chiper的init方法
    jmethodID jInitMid = env->GetMethodID(jChiperClz,"init","(ILjava/security/Key;)V");
    env->CallVoidMethod(jChiperObj,jInitMid,flag,jSecretObj);

    //调用ChipperdoFinal方法
    jmethodID jdoFinalMid = env->GetMethodID(jChiperClz,"doFinal","([B)[B");
    jbyteArray jbyteArray1 = static_cast<jbyteArray>(env->CallObjectMethod(jChiperObj, jdoFinalMid,
                                                                           textbyte));
    return jbyteArray1;
}

