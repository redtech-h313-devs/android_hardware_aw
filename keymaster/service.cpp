/*
**
** Copyright 2016, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#define LOG_TAG "android.hardware.keymaster@4.0-service-aw"

#include <hidl/HidlTransportSupport.h>
#include "ca/AW_Keymaster4Device.h"

#include <android/hardware/keymaster/4.0/IKeymasterDevice.h>

int main() {
    ::android::hardware::configureRpcThreadpool(1, true /* willJoinThreadpool */);

    auto awKeymaster =
        new aw::hardware::keymaster::V4_0::implementation::AndroidKeymaster4Device_AW();
    auto TaSetUp = awKeymaster->SetUpTa();
    if (TaSetUp != 0) {
        ALOGE("TA set up failed!");
    }
    auto status = awKeymaster->registerAsService();
    if (status != android::OK) {
        ALOGE("register keymaster 4.0 service failed");
    }

    android::hardware::joinRpcThreadpool();
    return -1;  // Should never get here.
}
