/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : https://creativecommons.org/licenses/by/4.0/
*/
#pragma once
#include <stdio.h>
#include <windows.h>
#include "pkcs11/cryptoki.h"

#ifdef _M_X64
#define ORIGLIB	"idprimepkcs1164"
#define CALL_SPEC_PRE
#else
#define ORIGLIB	"idprimepkcs11"
#define CALL_SPEC_PRE "_"
#endif

__pragma(comment(lib, "lib/" ORIGLIB ".lib"))

#define PR_FW(name)	__pragma(comment(linker, "/export:" #name "=" ORIGLIB "." #name))
#define PR_HK(name)	__pragma(comment(linker, "/export:" #name "=" CALL_SPEC_PRE "HOOK_" #name))

CK_RV CK_CALL_SPEC HOOK_C_GetFunctionList(CK_FUNCTION_LIST_PTR_PTR ppFunctionList);
CK_RV CK_CALL_SPEC HOOK_C_InitToken(CK_SLOT_ID slotID, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen, CK_UTF8CHAR_PTR pLabel);
CK_RV CK_CALL_SPEC HOOK_C_Login(CK_SESSION_HANDLE hSession, CK_USER_TYPE userType, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen);
CK_RV CK_CALL_SPEC HOOK_C_SetPIN(CK_SESSION_HANDLE hSession, CK_UTF8CHAR_PTR pOldPin, CK_ULONG ulOldLen, CK_UTF8CHAR_PTR pNewPin, CK_ULONG ulNewLen);

__declspec(noinline) CK_RV AdaptPukToValidPuk(CK_UTF8CHAR_PTR pPuk, CK_ULONG ulPukLen, CK_UTF8CHAR_PTR *ppValidPuk, CK_ULONG *pulValidPukLen);
__declspec(noinline) void FreeValidPuk(CK_UTF8CHAR_PTR pValidPuk);

PR_FW("C_CancelFunction")
PR_FW("C_CloseAllSessions")
PR_FW("C_CloseSession")
PR_FW("C_CopyObject")
PR_FW("C_CreateObject")
PR_FW("C_Decrypt")
PR_FW("C_DecryptDigestUpdate")
PR_FW("C_DecryptFinal")
PR_FW("C_DecryptInit")
PR_FW("C_DecryptUpdate")
PR_FW("C_DecryptVerifyUpdate")
PR_FW("C_DeriveKey")
PR_FW("C_DestroyObject")
PR_FW("C_Digest")
PR_FW("C_DigestEncryptUpdate")
PR_FW("C_DigestFinal")
PR_FW("C_DigestInit")
PR_FW("C_DigestKey")
PR_FW("C_DigestUpdate")
PR_FW("C_Encrypt")
PR_FW("C_EncryptFinal")
PR_FW("C_EncryptInit")
PR_FW("C_EncryptUpdate")
PR_FW("C_Finalize")
PR_FW("C_FindObjects")
PR_FW("C_FindObjectsFinal")
PR_FW("C_FindObjectsInit")
PR_FW("C_GenerateKey")
PR_FW("C_GenerateKeyPair")
PR_FW("C_GenerateRandom")
PR_FW("C_GetAttributeValue")
PR_FW("C_GetCardProperty")
PR_HK("C_GetFunctionList") //
PR_FW("C_GetFunctionStatus")
PR_FW("C_GetInfo")
PR_FW("C_GetMechanismInfo")
PR_FW("C_GetMechanismList")
PR_FW("C_GetObjectSize")
PR_FW("C_GetOperationState")
PR_FW("C_GetSessionInfo")
PR_FW("C_GetSlotInfo")
PR_FW("C_GetSlotList")
PR_FW("C_GetTokenInfo")
PR_FW("C_InitPIN")
PR_HK("C_InitToken") //
PR_FW("C_Initialize")
PR_HK("C_Login") //
PR_FW("C_Logout")
PR_FW("C_OpenSession")
PR_FW("C_SeedRandom")
PR_FW("C_SetAttributeValue")
PR_FW("C_SetCardProperty")
PR_FW("C_SetOperationState")
PR_HK("C_SetPIN"); //
PR_FW("C_Sign")
PR_FW("C_SignEncryptUpdate")
PR_FW("C_SignFinal")
PR_FW("C_SignInit")
PR_FW("C_SignRecover")
PR_FW("C_SignRecoverInit")
PR_FW("C_SignUpdate")
PR_FW("C_UnwrapKey")
PR_FW("C_Verify")
PR_FW("C_VerifyFinal")
PR_FW("C_VerifyInit")
PR_FW("C_VerifyRecover")
PR_FW("C_VerifyRecoverInit")
PR_FW("C_VerifyUpdate")
PR_FW("C_WaitForSlotEvent")
PR_FW("C_WrapKey")