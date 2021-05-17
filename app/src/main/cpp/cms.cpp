#include "MD5.h"
#include <jni.h>
#include <string.h>

std::string keyChunk1(){
    return "cgn94`,N]+6ypw#]"; // chunk 1
}

std::string keyChunk2(){
    return "(uQ46netBg8sDA'."; // chunk 2
}

std::string keyChunk3(){
    return ":<3@~9TCh,r?hFU@";// chunk 3
}

std::string initKey(){
    return keyChunk1() + keyChunk2()+ keyChunk3();
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_ssovit_example_MainActivity_socialRoulette(
	JNIEnv *env,
    jobject obj,
    jstring urlPath)
{
	std::string myKey=initKey();
	const char *originStr;
	originStr = env->GetStringUTFChars(urlPath, JNI_FALSE);
	MD5 md5 = MD5(myKey + originStr);
	std::string myHash = md5.hexdigest();
	return env->NewStringUTF(myHash.c_str());
}
