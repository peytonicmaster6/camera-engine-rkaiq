/*
 * Copyright (c) 2019-2022 Rockchip Eletronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "rk_aiq_user_api_aynr_v2.h"

#if RKAIQ_HAVE_YNR_V2
#include "algo_handlers/RkAiqAynrV2Handle.h"
#endif

RKAIQ_BEGIN_DECLARE

#ifdef RK_SIMULATOR_HW
#define CHECK_USER_API_ENABLE
#endif

#if RKAIQ_HAVE_YNR_V2

XCamReturn
rk_aiq_user_api_aynrV2_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_ynr_attrib_v2_t* attr)
{
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_AYNR);
    RkAiqAynrV2HandleInt* algo_handle =
        algoHandle<RkAiqAynrV2HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_AYNR);

    if (algo_handle) {
        return algo_handle->setAttrib(attr);
    }

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn
rk_aiq_user_api_aynrV2_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_ynr_attrib_v2_t* attr)
{
    RkAiqAynrV2HandleInt* algo_handle =
        algoHandle<RkAiqAynrV2HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_AYNR);

    if (algo_handle) {
        return algo_handle->getAttrib(attr);
    }

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn
rk_aiq_user_api_aynrV2_SetStrength(const rk_aiq_sys_ctx_t* sys_ctx, float fPercnt)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    RKAIQ_API_SMART_LOCK(sys_ctx);

    RkAiqAynrV2HandleInt* algo_handle =
        algoHandle<RkAiqAynrV2HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_AYNR);
    if (algo_handle) {
        ret = algo_handle->setStrength(fPercnt);
    }

    return ret;
}


XCamReturn
rk_aiq_user_api_aynrV2_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, float *pPercnt)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    RKAIQ_API_SMART_LOCK(sys_ctx);

    RkAiqAynrV2HandleInt* algo_handle =
        algoHandle<RkAiqAynrV2HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_AYNR);
    if (algo_handle) {
        ret = algo_handle->getStrength(pPercnt);
    }

    return ret;
}

#else

XCamReturn
rk_aiq_user_api_aynrV2_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_ynr_attrib_v2_t* attr) {
    return XCAM_RETURN_ERROR_UNKNOWN;
}

XCamReturn
rk_aiq_user_api_aynrV2_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_ynr_attrib_v2_t* attr) {
    return XCAM_RETURN_ERROR_UNKNOWN;
}

XCamReturn
rk_aiq_user_api_aynrV2_SetStrength(const rk_aiq_sys_ctx_t* sys_ctx, float fPercnt) {
    return XCAM_RETURN_ERROR_UNKNOWN;
}

XCamReturn
rk_aiq_user_api_aynrV2_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, float *pPercnt) {
    return XCAM_RETURN_ERROR_UNKNOWN;
}

#endif

RKAIQ_END_DECLARE
