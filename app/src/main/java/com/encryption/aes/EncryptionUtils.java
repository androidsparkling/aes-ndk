package com.encryption.aes;

/**
 * Time: 2019/11/29 0029
 * Author: zoulong
 */
public class EncryptionUtils {
    static {
        System.loadLibrary("encryption");
    }

    public static native String encryptByAES(String data, String secretKey, String iv, String iMode);

    public static native String decryptByAES(String data, String secretKey, String iv, String iMode);
}
