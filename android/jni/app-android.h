#pragma once

#include "ppsspp_config.h"

#include <string>
#include "Common/LogManager.h"

#if PPSSPP_PLATFORM(ANDROID)

#include <jni.h>

jclass findClass(const char* name);
JNIEnv* getEnv();

#endif

class AndroidLogger : public LogListener {
public:
	void Log(const LogMessage &message) override;
};

extern std::string g_extFilesDir;

// Called from PathBrowser for example.

bool Android_IsContentUri(const std::string &filename);
int Android_OpenContentUriFd(const std::string &filename);

