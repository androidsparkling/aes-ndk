/**
 * aes加密
 */
#include <jni.h>
#include <string>
#include <iostream>
#include "utils/LogUtils.h"
#include "utils/AES.h"
#include "utils/encryption.h"
#include <typeinfo>
extern "C" JNIEXPORT jstring JNICALL
Java_com_encryption_aes_EncryptionUtils_encryptByAES(
        JNIEnv* env,
        jclass type,
        jstring data,
        jstring secretKey,
        jstring iv,
        jstring iMode){
    const char * c_data = env->GetStringUTFChars(data, 0);
    const char * c_secret_key = env->GetStringUTFChars(secretKey, 0);
    const char * c_iv = env->GetStringUTFChars(iv, 0);
    const char * c_mode = env -> GetStringUTFChars(iMode, 0);
    string encrypt_data = encryptByAES(c_data, c_secret_key, c_iv, getModeByName(c_mode));
    return env->NewStringUTF(encrypt_data.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_encryption_aes_EncryptionUtils_decryptByAES(
        JNIEnv* env,
        jclass type,
        jstring data,
        jstring secretKey,
        jstring iv,
        jstring iMode){
    const char * c_data = env->GetStringUTFChars(data, 0);
    const char * c_secret_key = env->GetStringUTFChars(secretKey, 0);
    const char * c_iv = env->GetStringUTFChars(iv, 0);
    const char * c_mode = env -> GetStringUTFChars(iMode, 0);
    string decrypt_data = decryptByAES(c_data, c_secret_key, c_iv, getModeByName(c_mode));
    return env->NewStringUTF(decrypt_data.c_str());
}

int getModeByName(const char * iModeName){
    if(strcmp("CFB", iModeName) == 0){
        return AES::CFB;
    }else if(strcmp("ECB", iModeName) == 0){
        return AES::ECB;
    }else{
        return AES::CBC;
    }
}
